#include "pch.h"
#include "GeneradorReportes.h"

namespace MODEL {
	using namespace System::Globalization;
	using namespace System::Text;

	GeneradorReportes::GeneradorReportes() {
		this->logEventos = gcnew List<LogEvento^>();
	}

	GeneradorReportes::GeneradorReportes(List<LogEvento^>^ logEventos) {
		setLogEventos(logEventos);
	}

	void GeneradorReportes::setLogEventos(List<LogEvento^>^ logEventos) {
		this->logEventos = logEventos == nullptr ? gcnew List<LogEvento^>() : logEventos;
	}

	List<LogEvento^>^ GeneradorReportes::getLogEventos() {
		return gcnew List<LogEvento^>(this->logEventos);
	}

	bool GeneradorReportes::Contiene(String^ texto, String^ valor) {
		if (String::IsNullOrWhiteSpace(texto) || String::IsNullOrWhiteSpace(valor))
			return false;
		return texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
	}

	bool GeneradorReportes::EsTipo(LogEvento^ evento, String^ tipo) {
		return evento != nullptr && Contiene(evento->getTipoEvento(), tipo);
	}

	bool GeneradorReportes::EsPausa(LogEvento^ evento) {
		return evento != nullptr &&
			(Contiene(evento->getEstado(), "Pausa") || EsTipo(evento, "Pausa"));
	}

	bool GeneradorReportes::EsDosisCumplida(LogEvento^ evento) {
		if (evento == nullptr || EsPausa(evento))
			return false;
		if (EsDosisOmitida(evento))
			return false;
		String^ estado = evento->getEstado();
		return Contiene(estado, "Tomada") ||
			Contiene(estado, "A tiempo") ||
			Contiene(estado, "Retraso") ||
			Contiene(estado, "Exitosa");
	}

	bool GeneradorReportes::EsDosisOmitida(LogEvento^ evento) {
		if (evento == nullptr || EsPausa(evento))
			return false;
		String^ estado = evento->getEstado();
		return Contiene(estado, "No tomada") ||
			Contiene(estado, "No tomado") ||
			Contiene(estado, "Omision") ||
			Contiene(estado, "Omitida") ||
			Contiene(estado, "Fallida");
	}

	String^ GeneradorReportes::NombreSeguro(String^ valor, String^ reemplazo) {
		return String::IsNullOrWhiteSpace(valor) ? reemplazo : valor->Trim();
	}

	String^ GeneradorReportes::ClasificarPuntualidad(LogEvento^ evento) {
		if (evento == nullptr || EsDosisOmitida(evento))
			return "Omision";

		DateTime programada = evento->getFechaHoraProgramada();
		DateTime real = evento->getFechaHoraReal();
		if (programada == DateTime::MinValue || real == DateTime::MinValue)
			return "Omision";

		double diferencia = Math::Abs((real - programada).TotalMinutes);
		return diferencia <= 15.0 ? "A tiempo" : "Retraso";
	}

	List<LogEvento^>^ GeneradorReportes::ObtenerEventosReporte(String^ nombreReporte) {
		List<LogEvento^>^ resultado = gcnew List<LogEvento^>();

		for each (LogEvento ^ evento in this->logEventos) {
			if (evento == nullptr)
				continue;

			bool incluir = false;
			if (nombreReporte == "Cumplimiento")
				incluir = EsTipo(evento, "Dosis") && !EsPausa(evento);
			else if (nombreReporte == "Dispensado")
				incluir = EsTipo(evento, "Dispensacion") && Contiene(evento->getEstado(), "Exitosa");
			else if (nombreReporte == "Puntualidad")
				incluir = EsTipo(evento, "Dosis") && !EsPausa(evento);
			else if (nombreReporte == "Dosis Omitidas")
				incluir = EsTipo(evento, "Dosis") && EsDosisOmitida(evento);
			else if (nombreReporte == "Alertas Criticas")
				incluir = EsTipo(evento, "Alerta Critica") ||
					EsTipo(evento, "Error Hardware") ||
					Contiene(evento->getOrigen(), "Alarma Critica") ||
					Contiene(evento->getOrigen(), "Error") ||
					(Contiene(evento->getOrigen(), "Antibiotico") && EsDosisOmitida(evento));
			else if (nombreReporte == "Uso del Sistema")
				incluir = EsTipo(evento, "Autenticacion") || EsTipo(evento, "Agua Servida");
			else if (nombreReporte == "Adherencia por Medicamento")
				incluir = EsTipo(evento, "Dosis") && !EsPausa(evento);
			else if (nombreReporte == "Tendencias")
				incluir = EsTipo(evento, "Dosis") && !EsPausa(evento);

			if (incluir)
				resultado->Add(evento);
		}

		return resultado;
	}

	double GeneradorReportes::CalcularCumplimiento(List<LogEvento^>^ eventos) {
		if (eventos == nullptr || eventos->Count == 0)
			return 0.0;

		int cumplidas = 0;
		int evaluadas = 0;
		for each (LogEvento ^ evento in eventos) {
			if (evento == nullptr || EsPausa(evento))
				continue;
			evaluadas++;
			if (EsDosisCumplida(evento))
				cumplidas++;
		}

		return evaluadas == 0 ? 0.0 : (cumplidas * 100.0 / evaluadas);
	}

	Dictionary<String^, double>^ GeneradorReportes::ObtenerValoresGrafico(String^ nombreReporte) {
		Dictionary<String^, double>^ valores = gcnew Dictionary<String^, double>();
		List<LogEvento^>^ eventos = ObtenerEventosReporte(nombreReporte);

		if (nombreReporte == "Cumplimiento" || nombreReporte == "Tendencias") {
			Dictionary<String^, List<LogEvento^>^>^ grupos = gcnew Dictionary<String^, List<LogEvento^>^>();
			for each (LogEvento ^ evento in eventos) {
				String^ clave = nombreReporte == "Tendencias"
					? String::Format("{0:yyyy}-S{1:00}",
						evento->getFechaHoraProgramada(),
						CultureInfo::InvariantCulture->Calendar->GetWeekOfYear(
							evento->getFechaHoraProgramada(),
							CalendarWeekRule::FirstFourDayWeek,
							DayOfWeek::Monday))
					: evento->getFechaHoraProgramada().ToString("dd/MM/yyyy");
				if (!grupos->ContainsKey(clave))
					grupos->Add(clave, gcnew List<LogEvento^>());
				grupos[clave]->Add(evento);
			}
			for each (KeyValuePair<String^, List<LogEvento^>^> grupo in grupos)
				valores->Add(grupo.Key, CalcularCumplimiento(grupo.Value));
			return valores;
		}

		if (nombreReporte == "Adherencia por Medicamento") {
			Dictionary<String^, List<LogEvento^>^>^ grupos = gcnew Dictionary<String^, List<LogEvento^>^>();
			for each (LogEvento ^ evento in eventos) {
				String^ clave = NombreSeguro(evento->getMedicamento(), "Sin medicamento");
				if (!grupos->ContainsKey(clave))
					grupos->Add(clave, gcnew List<LogEvento^>());
				grupos[clave]->Add(evento);
			}
			for each (KeyValuePair<String^, List<LogEvento^>^> grupo in grupos)
				valores->Add(grupo.Key, CalcularCumplimiento(grupo.Value));
			return valores;
		}

		for each (LogEvento ^ evento in eventos) {
			String^ clave;
			if (nombreReporte == "Puntualidad")
				clave = ClasificarPuntualidad(evento);
			else if (nombreReporte == "Uso del Sistema")
				clave = NombreSeguro(evento->getTipoEvento(), "Sin tipo");
			else if (nombreReporte == "Alertas Criticas")
				clave = evento->getFechaHoraReal() == DateTime::MinValue
					? evento->getFechaHoraProgramada().ToString("dd/MM/yyyy")
					: evento->getFechaHoraReal().ToString("dd/MM/yyyy");
			else
				clave = NombreSeguro(evento->getMedicamento(), "Sin medicamento");

			if (valores->ContainsKey(clave))
				valores[clave] += nombreReporte == "Uso del Sistema" && EsTipo(evento, "Agua Servida")
					? Math::Max(1, evento->getCantidad())
					: 1.0;
			else
				valores->Add(clave, nombreReporte == "Uso del Sistema" && EsTipo(evento, "Agua Servida")
					? Math::Max(1, evento->getCantidad())
					: 1.0);
		}

		return valores;
	}

	String^ GeneradorReportes::GenerarResumen(String^ nombreReporte) {
		List<LogEvento^>^ eventos = ObtenerEventosReporte(nombreReporte);
		StringBuilder^ texto = gcnew StringBuilder();
		texto->AppendLine("REPORTE: " + nombreReporte->ToUpperInvariant());
		texto->AppendLine("----------------------------------------");
		texto->AppendLine("Eventos incluidos: " + eventos->Count.ToString());

		if (nombreReporte == "Cumplimiento" ||
			nombreReporte == "Adherencia por Medicamento" ||
			nombreReporte == "Tendencias") {
			texto->AppendLine(String::Format(
				CultureInfo::InvariantCulture,
				"Cumplimiento total: {0:F2}%",
				CalcularCumplimiento(eventos)));
		}
		else if (nombreReporte == "Puntualidad") {
			int aTiempo = 0;
			int retrasos = 0;
			int omisiones = 0;
			for each (LogEvento ^ evento in eventos) {
				String^ clasificacion = ClasificarPuntualidad(evento);
				if (clasificacion == "A tiempo") aTiempo++;
				else if (clasificacion == "Retraso") retrasos++;
				else omisiones++;
			}
			texto->AppendLine("A tiempo: " + aTiempo.ToString());
			texto->AppendLine("Retrasos: " + retrasos.ToString());
			texto->AppendLine("Omisiones: " + omisiones.ToString());
		}
		else if (nombreReporte == "Uso del Sistema") {
			int autenticaciones = 0;
			int agua = 0;
			for each (LogEvento ^ evento in eventos) {
				if (EsTipo(evento, "Autenticacion")) autenticaciones++;
				if (EsTipo(evento, "Agua Servida")) agua += Math::Max(0, evento->getCantidad());
			}
			texto->AppendLine("Autenticaciones: " + autenticaciones.ToString());
			texto->AppendLine("Agua servida: " + agua.ToString() + " ml");
		}

		texto->AppendLine("");
		for each (LogEvento ^ evento in eventos) {
			texto->AppendFormat(
				"{0:dd/MM/yyyy HH:mm} | {1} | {2} | {3}\r\n",
				evento->getFechaHoraProgramada(),
				NombreSeguro(evento->getMedicamento(), NombreSeguro(evento->getTipoEvento(), "Evento")),
				NombreSeguro(evento->getEstado(), "Sin estado"),
				NombreSeguro(evento->getNombrePaciente(), "Sin paciente"));
		}

		return texto->ToString();
	}
}
