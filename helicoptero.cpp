#include "Helicoptero.h"
#include <iostream>

Helicoptero::Helicoptero(const string& pId, const string& pNombre,
                         const string& pPlaca, int pCapacidad)
    : Vehiculo(pId, pNombre, pPlaca, pCapacidad)
{
}

Helicoptero::~Helicoptero()
{
}

const char* Helicoptero::getTipo() const
{
    return "Helicoptero";
}

void Helicoptero::mostrarInformacion() const
{
    cout << "Tipo: " << getTipo() << endl;
    mostrarDatosVehiculo();
}

void Helicoptero::ejecutarAccion() const
{
    cout << "Realizando extraccion aerea." << endl;
}