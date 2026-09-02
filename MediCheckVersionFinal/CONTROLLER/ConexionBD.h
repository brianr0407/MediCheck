#include "pch.h"
#pragma once

namespace CONTROLLER {
    using namespace System;
    using namespace System::Data::SqlClient;

    public ref class ConexionBD abstract sealed {
    public:
        static String^ ObtenerCadenaConexion();
        static SqlConnection^ CrearConexion();
    };
}
