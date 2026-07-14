#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"


class Vehiculo : public Recurso
{
protected:
    string placa;
    int capacidad;

    void mostrarDatosVehiculo() const;

public:
    Vehiculo(const string& pId, const string& pNombre,
             const string& pPlaca, int pCapacidad);
    virtual ~Vehiculo();

    const string& getPlaca() const;
    int getCapacidad() const;
};

#endif
