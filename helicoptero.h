#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"

class Helicoptero : public Vehiculo
{
public:
    Helicoptero(const string& pId, const string& pNombre,
                const string& pPlaca, int pCapacidad);
    ~Helicoptero() override;

    const char* getTipo() const override;
    void mostrarInformacion() const override;
    void ejecutarAccion() const override;
};

#endif
