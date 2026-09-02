#include "pch.h"


namespace CONTROLLER {
    using namespace System;
    using namespace System:: Collections::Generic;
    using namespace MODEL;

    public ref class UsuarioController {
    private:
        List<Usuario^>^ listaUsuarios;

    public:
        UsuarioController();
        UsuarioController(List<Usuario^>^ listaUsuarios);
        // Operaciones CRUD
        void agregarUsuario(Usuario^ Usuario);
        bool eliminarUsuario(int id);
        bool ModificarUsuario(int id, String^ nombre, String^ apellido);
        bool ExisteUsuario(int id);
        Usuario^ BuscarUsuarioPorId(int id);
        List<Usuario^>^ ObtenerTodosUsuarios();
        List<Usuario^>^ BuscarUsuariosPorIdentificador(int id);

    };
}