#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(const string& pId, const string& pNombre,
                   const string& pPlaca, int pCapacidad)
    : Recurso(pId, pNombre), placa(pPlaca), capacidad(pCapacidad)
{
}

Vehiculo::~Vehiculo()
{
}

const string& Vehiculo::getPlaca() const
{
    return placa;
}

int Vehiculo::getCapacidad() const
{
    return capacidad;
}

void Vehiculo::mostrarDatosVehiculo() const
{
    mostrarDatosBase();
    cout << "Placa/Matricula: " << placa << endl;
    cout << "Capacidad: " << capacidad << endl;
}
