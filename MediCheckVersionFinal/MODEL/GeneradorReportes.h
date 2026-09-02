#pragma once
#include "LogEvento.h"

namespace MODEL {
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class GeneradorReportes {
	private:
		List<LogEvento^>^ logEventos;

		bool Contiene(String^ texto, String^ valor);
		bool EsTipo(LogEvento^ evento, String^ tipo);
		bool EsPausa(LogEvento^ evento);
		bool EsDosisCumplida(LogEvento^ evento);
		bool EsDosisOmitida(LogEvento^ evento);
		String^ NombreSeguro(String^ valor, String^ reemplazo);

	public:
		GeneradorReportes();
		GeneradorReportes(List<LogEvento^>^ logEventos);

		void setLogEventos(List<LogEvento^>^ logEventos);
		List<LogEvento^>^ getLogEventos();

		List<LogEvento^>^ ObtenerEventosReporte(String^ nombreReporte);
		Dictionary<String^, double>^ ObtenerValoresGrafico(String^ nombreReporte);
		String^ GenerarResumen(String^ nombreReporte);
		String^ ClasificarPuntualidad(LogEvento^ evento);
		double CalcularCumplimiento(List<LogEvento^>^ eventos);
	};
}
