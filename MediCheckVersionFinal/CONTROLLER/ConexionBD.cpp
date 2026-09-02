#include "pch.h"
#include "ConexionBD.h"

namespace CONTROLLER {
    String^ ConexionBD::ObtenerCadenaConexion() {
        String^ cadena = Environment::GetEnvironmentVariable(
            "MEDICHECK_DB_CONNECTION"
        );

        if (String::IsNullOrWhiteSpace(cadena)) {
            throw gcnew InvalidOperationException(
                "No se configuró MEDICHECK_DB_CONNECTION."
            );
        }

        return cadena;
    }

    SqlConnection^ ConexionBD::CrearConexion() {
        return gcnew SqlConnection(ObtenerCadenaConexion());
    }
}
