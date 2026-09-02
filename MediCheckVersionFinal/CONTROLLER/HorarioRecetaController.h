#pragma once

namespace CONTROLLER {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlClient;
	using namespace MODEL;

	public ref class HorarioRecetaController {
	private:
		SqlConnection^ conexion;

	public:
		HorarioRecetaController();

		void abrirConexion();
		void cerrarConexion();

		int ObtenerSiguienteId();
		bool AgregarHorarioReceta(HorarioReceta^ horario);
		bool ActualizarHorarioReceta(HorarioReceta^ horario);
		bool EliminarHorarioReceta(int idHorario);
		bool EliminarHorariosPorReceta(int idReceta);

		HorarioReceta^ BuscarHorarioPorId(int idHorario);
		List<HorarioReceta^>^ ObtenerTodosHorariosReceta();
		List<HorarioReceta^>^ ObtenerHorariosPorReceta(int idReceta);
		bool ExisteHorarioEnReceta(int idReceta, TimeSpan horaProgramada);
	};
}
