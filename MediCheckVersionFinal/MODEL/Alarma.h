#pragma once
using namespace System;

namespace MODEL {

    public ref class Alarma abstract {  // abstract porque nunca instancias Alarma sola
    protected:
        int     id;
        bool    estado;
        String^ tipo;   // lo fijan las subclases, no el usuario

    public:
        Alarma();
        Alarma(int id, bool estado, String^ tipo);

        // Getters y Setters
        int     getId();
        void    setId(int id);
        bool    getEstado();
        void    setEstado(bool estado);
        String^ getTipo();      // útil para mostrar en pantalla o guardar en TXT

        // Métodos que cada subclase implementará a su manera (ESP32)
        virtual void activar() = 0;  // puro virtual, obliga a cada subclase a implementarlo
        virtual void desactivar() = 0;
    };
}