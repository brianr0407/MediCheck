#include "pch.h"
#include "AlarmaVisual.h"

namespace MODEL {
    using namespace System;

    AlarmaVisual::AlarmaVisual() {}

    AlarmaVisual::AlarmaVisual(int id, bool estado, String^ tipo)
        : Alarma(id, estado, tipo)
    {
    }
}