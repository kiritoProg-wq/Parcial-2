#include "Rescatista.h"
#include <iostream>

Rescatista::Rescatista(const string& pId, const string& pNombre,
                       const string& pEspecialidad)
    : Personal(pId, pNombre, pEspecialidad)
{
}

Rescatista::~Rescatista()
{
}

const char* Rescatista::getTipo() const
{
    return "Rescatista";
}

void Rescatista::mostrarInformacion() const
{
    cout << "Tipo: " << getTipo() << endl;
    mostrarDatosPersonal();
}

void Rescatista::ejecutarAccion() const
{
    cout << "Buscando sobrevivientes en escombros." << endl;
}
