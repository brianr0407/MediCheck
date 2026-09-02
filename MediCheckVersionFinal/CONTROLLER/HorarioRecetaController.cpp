#include "pch.h"
#include "HorarioRecetaController.h"
#include "ConexionBD.h"

namespace CONTROLLER {
	HorarioRecetaController::HorarioRecetaController() {
		this->conexion = ConexionBD::CrearConexion();
	}

	void HorarioRecetaController::abrirConexion() {
		if (this->conexion == nullptr)
			this->conexion = ConexionBD::CrearConexion();
		if (this->conexion->State != System::Data::ConnectionState::Open)
			this->conexion->Open();
	}

	void HorarioRecetaController::cerrarConexion() {
		if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
			this->conexion->Close();
	}

	int HorarioRecetaController::ObtenerSiguienteId() {
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"SELECT ISNULL(MAX(idHorario), 0) + 1 FROM HorariosReceta", this->conexion);
		int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
		cerrarConexion();
		return id;
	}

	bool HorarioRecetaController::AgregarHorarioReceta(HorarioReceta^ horario) {
		if (horario == nullptr)
			return false;
		if (ExisteHorarioEnReceta(horario->getIdReceta(), horario->getHoraProgramada()))
			return false;

		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"INSERT INTO HorariosReceta(idHorario,idReceta,horaProgramada) "
			"VALUES(@idHorario,@idReceta,@horaProgramada)", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idHorario", horario->getIdHorario());
		sentenciaSQL->Parameters->AddWithValue("@idReceta", horario->getIdReceta());
		sentenciaSQL->Parameters->AddWithValue("@horaProgramada", horario->getHoraProgramada());
		bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
		cerrarConexion();
		return agregado;
	}

	bool HorarioRecetaController::ActualizarHorarioReceta(HorarioReceta^ horario) {
		if (horario == nullptr)
			return false;

		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"UPDATE HorariosReceta SET idReceta=@idReceta,horaProgramada=@horaProgramada "
			"WHERE idHorario=@idHorario", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idReceta", horario->getIdReceta());
		sentenciaSQL->Parameters->AddWithValue("@horaProgramada", horario->getHoraProgramada());
		sentenciaSQL->Parameters->AddWithValue("@idHorario", horario->getIdHorario());
		bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
		cerrarConexion();
		return actualizado;
	}

	bool HorarioRecetaController::EliminarHorarioReceta(int idHorario) {
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"DELETE FROM HorariosReceta WHERE idHorario=@idHorario", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idHorario", idHorario);
		bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
		cerrarConexion();
		return eliminado;
	}

	bool HorarioRecetaController::EliminarHorariosPorReceta(int idReceta) {
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"DELETE FROM HorariosReceta WHERE idReceta=@idReceta", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idReceta", idReceta);
		bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
		cerrarConexion();
		return eliminado;
	}

	HorarioReceta^ HorarioRecetaController::BuscarHorarioPorId(int idHorario) {
		HorarioReceta^ horario = nullptr;
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"SELECT h.idHorario,h.idReceta,h.horaProgramada FROM HorariosReceta h "
			"INNER JOIN Recetas r ON r.idReceta = h.idReceta "
			"WHERE h.idHorario=@idHorario AND r.Activo=1", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idHorario", idHorario);
		SqlDataReader^ data = sentenciaSQL->ExecuteReader();

		if (data->Read()) {
			horario = gcnew HorarioReceta(
				Convert::ToInt32(data["idHorario"]),
				Convert::ToInt32(data["idReceta"]),
				safe_cast<TimeSpan>(data["horaProgramada"]));
		}

		data->Close();
		cerrarConexion();
		return horario;
	}

	List<HorarioReceta^>^ HorarioRecetaController::ObtenerTodosHorariosReceta() {
		List<HorarioReceta^>^ horarios = gcnew List<HorarioReceta^>();
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"SELECT h.idHorario,h.idReceta,h.horaProgramada FROM HorariosReceta h "
			"INNER JOIN Recetas r ON r.idReceta = h.idReceta "
			"WHERE r.Activo=1 ORDER BY h.idReceta,h.horaProgramada", this->conexion);
		SqlDataReader^ data = sentenciaSQL->ExecuteReader();

		while (data->Read()) {
			horarios->Add(gcnew HorarioReceta(
				Convert::ToInt32(data["idHorario"]),
				Convert::ToInt32(data["idReceta"]),
				safe_cast<TimeSpan>(data["horaProgramada"])));
		}

		data->Close();
		cerrarConexion();
		return horarios;
	}

	List<HorarioReceta^>^ HorarioRecetaController::ObtenerHorariosPorReceta(int idReceta) {
		List<HorarioReceta^>^ horarios = gcnew List<HorarioReceta^>();
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"SELECT h.idHorario,h.idReceta,h.horaProgramada FROM HorariosReceta h "
			"INNER JOIN Recetas r ON r.idReceta = h.idReceta "
			"WHERE h.idReceta=@idReceta AND r.Activo=1 ORDER BY h.horaProgramada", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idReceta", idReceta);
		SqlDataReader^ data = sentenciaSQL->ExecuteReader();

		while (data->Read()) {
			horarios->Add(gcnew HorarioReceta(
				Convert::ToInt32(data["idHorario"]),
				Convert::ToInt32(data["idReceta"]),
				safe_cast<TimeSpan>(data["horaProgramada"])));
		}

		data->Close();
		cerrarConexion();
		return horarios;
	}

	bool HorarioRecetaController::ExisteHorarioEnReceta(int idReceta, TimeSpan horaProgramada) {
		abrirConexion();
		SqlCommand^ sentenciaSQL = gcnew SqlCommand(
			"SELECT COUNT(*) FROM HorariosReceta h "
			"INNER JOIN Recetas r ON r.idReceta = h.idReceta "
			"WHERE h.idReceta=@idReceta AND h.horaProgramada=@horaProgramada AND r.Activo=1", this->conexion);
		sentenciaSQL->Parameters->AddWithValue("@idReceta", idReceta);
		sentenciaSQL->Parameters->AddWithValue("@horaProgramada", horaProgramada);
		bool existe = Convert::ToInt32(sentenciaSQL->ExecuteScalar()) > 0;
		cerrarConexion();
		return existe;
	}
}
