#include "pch.h"
#include "LogEvento.h"

namespace MODEL {
	LogEvento::LogEvento() {
		this->id = 0;
		this->idPaciente = 0;
		this->nombrePaciente = "";
		this->idMedicamento = 0;
		this->medicamento = "";
		this->tipoEvento = "";
		this->estado = "";
		this->origen = "";
		this->fechaHoraProgramada = DateTime::MinValue;
		this->fechaHoraReal = DateTime::MinValue;
		this->cantidad = 0;
		this->detalle = "";
	}

	LogEvento::LogEvento(
		int id,
		int idPaciente,
		String^ nombrePaciente,
		int idMedicamento,
		String^ medicamento,
		String^ tipoEvento,
		String^ estado,
		String^ origen,
		DateTime fechaHoraProgramada,
		DateTime fechaHoraReal,
		int cantidad,
		String^ detalle)
	{
		this->id = id;
		this->idPaciente = idPaciente;
		this->nombrePaciente = nombrePaciente;
		this->idMedicamento = idMedicamento;
		this->medicamento = medicamento;
		this->tipoEvento = tipoEvento;
		this->estado = estado;
		this->origen = origen;
		this->fechaHoraProgramada = fechaHoraProgramada;
		this->fechaHoraReal = fechaHoraReal;
		this->cantidad = cantidad;
		this->detalle = detalle;
	}

	int LogEvento::getId() { return this->id; }
	void LogEvento::setId(int id) { this->id = id; }

	int LogEvento::getIdPaciente() { return this->idPaciente; }
	void LogEvento::setIdPaciente(int idPaciente) { this->idPaciente = idPaciente; }

	String^ LogEvento::getNombrePaciente() { return this->nombrePaciente; }
	void LogEvento::setNombrePaciente(String^ nombrePaciente) { this->nombrePaciente = nombrePaciente; }

	int LogEvento::getIdMedicamento() { return this->idMedicamento; }
	void LogEvento::setIdMedicamento(int idMedicamento) { this->idMedicamento = idMedicamento; }

	String^ LogEvento::getMedicamento() { return this->medicamento; }
	void LogEvento::setMedicamento(String^ medicamento) { this->medicamento = medicamento; }

	String^ LogEvento::getTipoEvento() { return this->tipoEvento; }
	void LogEvento::setTipoEvento(String^ tipoEvento) { this->tipoEvento = tipoEvento; }

	String^ LogEvento::getEstado() { return this->estado; }
	void LogEvento::setEstado(String^ estado) { this->estado = estado; }

	String^ LogEvento::getOrigen() { return this->origen; }
	void LogEvento::setOrigen(String^ origen) { this->origen = origen; }

	DateTime LogEvento::getFechaHoraProgramada() { return this->fechaHoraProgramada; }
	void LogEvento::setFechaHoraProgramada(DateTime fechaHoraProgramada) {
		this->fechaHoraProgramada = fechaHoraProgramada;
	}

	DateTime LogEvento::getFechaHoraReal() { return this->fechaHoraReal; }
	void LogEvento::setFechaHoraReal(DateTime fechaHoraReal) {
		this->fechaHoraReal = fechaHoraReal;
	}

	int LogEvento::getCantidad() { return this->cantidad; }
	void LogEvento::setCantidad(int cantidad) { this->cantidad = cantidad; }

	String^ LogEvento::getDetalle() { return this->detalle; }
	void LogEvento::setDetalle(String^ detalle) { this->detalle = detalle; }
}
