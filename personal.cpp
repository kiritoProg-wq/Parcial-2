#include "Personal.h"
#include <iostream>

Personal::Personal(const string& pId, const string& pNombre,
                   const string& pEspecialidad)
    : Recurso(pId, pNombre), especialidad(pEspecialidad)
{
}

Personal::~Personal()
{
}

const string& Personal::getEspecialidad() const
{
    return especialidad;
}

void Personal::mostrarDatosPersonal() const
{
    mostrarDatosBase();
    cout << "Especialidad: " << especialidad << endl;
}
