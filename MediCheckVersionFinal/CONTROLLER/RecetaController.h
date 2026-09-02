#pragma once

namespace CONTROLLER {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace MODEL;
	using namespace IO;
	public ref class RecetaController {
	private:
		List<Receta^>^ listaRecetas;
		SqlConnection^ conexion;
	public:
		RecetaController();
		RecetaController(List<Receta^>^ listaRecetas);
		void abrirConexion();
		void cerrarConexion();
		//BackUp
		void AgregarAlBackup(Receta^ receta);
		void ActualizarBackup(Receta^ receta);
		int ObtenerSiguienteId();
		//opearciones crud persiustencias de datos
		void EscribirArchivo(List<Receta^>^ listaRecetas);
		bool ActualizarArchivo(Receta^ receta);
		List<Receta^>^ ObtenerTodosRecetasTXT();
		DataTable^ ObtenerRecetasParaGrillaTXT();
		DataTable^ ObtenerRecetasInactivasTablaTXT();
		bool AgregarRecetaTXT(Receta^ receta);
		bool EliminarRecetaTXT(int id);
		bool RestaurarRecetaTXT(int id, String^% mensajeError);
		bool ValidarReceta(int idPaciente, Medicamento^ medicamento, int dosisDiaria, List<TimeSpan>^ horarios, String^% mensajeError);
		List<TimeSpan>^ GenerarHorariosPorFrecuencia(TimeSpan horaInicial, int frecuenciaHoras, int cantidadDosis, String^% mensajeError);
		bool RegistrarRecetaConHorarios(int idPaciente, Medicamento^ medicamento, int dosisDiaria, List<TimeSpan>^ horarios, int% idRecetaGenerado, String^% mensajeError);
		bool ModificarRecetaConHorarios(int idReceta, int idPaciente, Medicamento^ medicamento, int dosisDiaria, int dosisTomada, List<TimeSpan>^ horarios, String^% mensajeError);
		Receta^ BuscarRecetaPorIdTXT(int id);

		List<	Receta^>^ BuscarRecetaPorIdListaTXT(int id);

		List<Receta^>^ BuscarRecetasActivasPorCronogramaIdTXT(int id);
	};
};
