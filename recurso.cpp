#include "Recurso.h"
#include <iostream>

Recurso::Recurso(const string& pId, const string& pNombre)
    : id(pId), nombre(pNombre), disponible(true)
{
}

Recurso::~Recurso()
{
}

const string& Recurso::getId() const
{
    return id;
}

const string& Recurso::getNombre() const
{
    return nombre;
}

bool Recurso::estaDisponible() const
{
    return disponible;
}

void Recurso::setDisponible(bool pDisponible)
{
    disponible = pDisponible;
}

void Recurso::mostrarDatosBase() const
{
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Disponibilidad: " << (disponible ? "Disponible" : "Asignado") << endl;
}
