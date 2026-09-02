#include "pch.h"
#pragma once

namespace CONTROLLER {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlClient;
	using namespace MODEL;
	using namespace IO;
	public ref class CronogramaTomaController {
	private:
		List<CronogramaToma^>^ listaCronogramasToma;
		SqlConnection^ conexion;
	public:
		CronogramaTomaController();
		CronogramaTomaController(List<CronogramaToma^>^ listaCronogramasToma);
		void abrirConexion();
		void cerrarConexion();
		//opearciones crud persiustencias de datos

		void EscribirArchivo(List<CronogramaToma^>^ listaCronogramasToma);
		bool ActualizarArchivo(CronogramaToma^ cronogramaToma);

		List<CronogramaToma^>^ ObtenerTodosCronogramasTomaTXT();

		bool AgregarCronogramaTomaTXT(CronogramaToma^ cronogramaToma);
		bool EliminarCronogramaTomaTXT(int id);


		CronogramaToma^ BuscarCronogramaPorIdTXT(int id);
		List<CronogramaToma^>^ BuscarCronogramasPorIdListaTXT(int id);
	};
}
