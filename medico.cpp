#include "Medico.h"
#include <iostream>

Medico::Medico(const string& pId, const string& pNombre,
               const string& pEspecialidad)
    : Personal(pId, pNombre, pEspecialidad)
{
}

Medico::~Medico()
{
}

const char* Medico::getTipo() const
{
    return "Medico";
}

void Medico::mostrarInformacion() const
{
    cout << "Tipo: " << getTipo() << endl;
    mostrarDatosPersonal();
}

void Medico::ejecutarAccion() const
{
    cout << "Estabilizando signos vitales." << endl;
}
