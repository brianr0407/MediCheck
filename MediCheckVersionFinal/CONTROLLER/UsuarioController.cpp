#include "pch.h"
#include "UsuarioController.h"
namespace CONTROLLER {
    UsuarioController::UsuarioController() {
        this->listaUsuarios = gcnew List<Usuario^>();
    }
    UsuarioController::UsuarioController(List<Usuario^>^ listaUsuarios) {
        this->listaUsuarios = listaUsuarios;
    }

    // Operaciones CRUD
    void UsuarioController::agregarUsuario(Usuario^ Usuario) {
        this->listaUsuarios->Add(Usuario);
    }

    bool UsuarioController::eliminarUsuario(int id) {
        Usuario^ usuarioAEliminar = BuscarUsuarioPorId(id);
        if (usuarioAEliminar != nullptr) {
            this->listaUsuarios->Remove(usuarioAEliminar);
            return true;
        }
        return false;
    }
    // Buscar usuario por ID
    Usuario^ UsuarioController::BuscarUsuarioPorId(int id) {
        for each(Usuario ^ usuario in this->listaUsuarios) {
            if (usuario->getId() == id) {
                return usuario;
            }
        }
        return nullptr;
    }

    // Obtener todos los usuarios
    List<Usuario^>^ UsuarioController::ObtenerTodosUsuarios() {
        return this->listaUsuarios;
    }

    //actualizar usuario por id
    bool UsuarioController::ModificarUsuario(int id, String^ nombre, String^ apellido) {
        Usuario^ usuarioAModificar = BuscarUsuarioPorId(id);
        if (usuarioAModificar != nullptr) {
            usuarioAModificar->setNombre(nombre);
            usuarioAModificar->setApellido(apellido);
            
            return true;
        }
        return false;
    }

    bool UsuarioController::ExisteUsuario(int id) {
        return BuscarUsuarioPorId(id) != nullptr;
    }




    List<Usuario^>^ UsuarioController::BuscarUsuariosPorIdentificador(int id) {
        List<Usuario^>^ resultados = gcnew List<Usuario^>();
        for (int i = 0; i < this->listaUsuarios->Count; i++) {
            if (this->listaUsuarios[i]->getId() == id) {
                Usuario^ usuario1 = BuscarUsuarioPorId(this->listaUsuarios[i]->getId());
                resultados->Add(usuario1);
            }
        }
        return resultados;
    }
}