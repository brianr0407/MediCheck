#pragma once

namespace MODEL {
	using namespace System;

	public ref class LogEvento {
	private:
		int id;
		int idPaciente;
		String^ nombrePaciente;
		int idMedicamento;
		String^ medicamento;
		String^ tipoEvento;
		String^ estado;
		String^ origen;
		DateTime fechaHoraProgramada;
		DateTime fechaHoraReal;
		int cantidad;
		String^ detalle;

	public:
		LogEvento();
		LogEvento(
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
			String^ detalle);

		int getId();
		void setId(int id);

		int getIdPaciente();
		void setIdPaciente(int idPaciente);

		String^ getNombrePaciente();
		void setNombrePaciente(String^ nombrePaciente);

		int getIdMedicamento();
		void setIdMedicamento(int idMedicamento);

		String^ getMedicamento();
		void setMedicamento(String^ medicamento);

		String^ getTipoEvento();
		void setTipoEvento(String^ tipoEvento);

		String^ getEstado();
		void setEstado(String^ estado);

		String^ getOrigen();
		void setOrigen(String^ origen);

		DateTime getFechaHoraProgramada();
		void setFechaHoraProgramada(DateTime fechaHoraProgramada);

		DateTime getFechaHoraReal();
		void setFechaHoraReal(DateTime fechaHoraReal);

		int getCantidad();
		void setCantidad(int cantidad);

		String^ getDetalle();
		void setDetalle(String^ detalle);
	};
}
