#pragma once

namespace CONTROLLER {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlClient;
	using namespace MODEL;

	public ref class GeneradorReportesController {
	private:
		List<LogEvento^>^ eventos;
		MODEL::GeneradorReportes^ generador;
		SqlConnection^ conexion;
		bool datosCargados;
		String^ Limpiar(String^ valor);

	public:
		GeneradorReportesController();
		GeneradorReportesController(String^ rutaArchivo);
		void abrirConexion();
		void cerrarConexion();

		int ObtenerSiguienteId();
		LogEvento^ CrearEvento(
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

		void AgregarEvento(LogEvento^ evento);
		void ActualizarEvento(LogEvento^ evento);
		void EliminarEvento(int id);
		LogEvento^ BuscarPorId(int id);

		List<LogEvento^>^ ObtenerTodos();
		List<LogEvento^>^ ObtenerEventosReporte(String^ nombreReporte);
		Dictionary<String^, double>^ ObtenerValoresGrafico(String^ nombreReporte);
		String^ GenerarResumen(String^ nombreReporte);
		String^ ClasificarPuntualidad(LogEvento^ evento);
		double ObtenerPorcentajeCumplimientoGlobal();

		void CargarDatos();
		void RefrescarDatos();
		void GuardarDatos();
	};
}
