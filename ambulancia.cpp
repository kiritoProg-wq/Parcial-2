#include "Ambulancia.h"
#include <iostream>

Ambulancia::Ambulancia(const string& pId, const string& pNombre,
                       const string& pPlaca, int pCapacidad)
    : Vehiculo(pId, pNombre, pPlaca, pCapacidad)
{
}

Ambulancia::~Ambulancia()
{
}

const char* Ambulancia::getTipo() const
{
    return "Ambulancia";
}

void Ambulancia::mostrarInformacion() const
{
    cout << "Tipo: " << getTipo() << endl;
    mostrarDatosVehiculo();
}

void Ambulancia::ejecutarAccion() const
{
    cout << "Transportando paciente via terrestre." << endl;
}
