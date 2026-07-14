#include "Mision.h"
#include "Recurso.h"
#include <iostream>

Mision::Mision(const string& pId, const string& pNombre, const string& pZona)
    : id(pId), nombre(pNombre), zona(pZona), estado("Pendiente"),
      recursosAsignados(nullptr), cantidadRecursos(0), capacidadRecursos(2)
{
    recursosAsignados = new Recurso*[capacidadRecursos];
    for (int i = 0; i < capacidadRecursos; ++i)
    {
        recursosAsignados[i] = nullptr;
    }
}

Mision::~Mision()
{
    // La mision solo destruye el arreglo de punteros, no los recursos.
    delete[] recursosAsignados;
    recursosAsignados = nullptr;
}

const string& Mision::getId() const
{
    return id;
}

const string& Mision::getNombre() const
{
    return nombre;
}

const string& Mision::getZona() const
{
    return zona;
}

const string& Mision::getEstado() const
{
    return estado;
}

int Mision::getCantidadRecursos() const
{
    return cantidadRecursos;
}

bool Mision::contieneRecurso(const Recurso* recurso) const
{
    for (int i = 0; i < cantidadRecursos; ++i)
    {
        if (recursosAsignados[i] == recurso)
        {
            return true;
        }
    }
    return false;
}

void Mision::redimensionarRecursos()
{
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < nuevaCapacidad; ++i)
    {
        nuevoArreglo[i] = nullptr;
    }

    for (int i = 0; i < cantidadRecursos; ++i)
    {
        nuevoArreglo[i] = recursosAsignados[i];
    }

    delete[] recursosAsignados;
    recursosAsignados = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

bool Mision::agregarRecurso(Recurso* recurso)
{
    if (recurso == nullptr || estado != "Pendiente")
    {
        return false;
    }

    if (!recurso->estaDisponible() || contieneRecurso(recurso))
    {
        return false;
    }

    if (cantidadRecursos == capacidadRecursos)
    {
        redimensionarRecursos();
    }

    recursosAsignados[cantidadRecursos] = recurso;
    ++cantidadRecursos;
    recurso->setDisponible(false);
    return true;
}

void Mision::mostrarInformacion() const
{
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Zona: " << zona << endl;
    cout << "Estado: " << estado << endl;
    cout << "Recursos asignados: " << cantidadRecursos << endl;

    for (int i = 0; i < cantidadRecursos; ++i)
    {
        cout << "  - " << recursosAsignados[i]->getTipo()
             << " | " << recursosAsignados[i]->getId()
             << " | " << recursosAsignados[i]->getNombre() << endl;
    }
}

void Mision::liberarDisponibilidadRecursos()
{
    for (int i = 0; i < cantidadRecursos; ++i)
    {
        if (recursosAsignados[i] != nullptr)
        {
            recursosAsignados[i]->setDisponible(true);
        }
    }
}

void Mision::ejecutar()
{
    if (estado == "Ejecutada")
    {
        cout << "La mision ya fue ejecutada anteriormente." << endl;
        return;
    }

    if (cantidadRecursos == 0)
    {
        cout << "La mision no tiene recursos asignados." << endl;
        return;
    }

    cout << "\n=== EJECUCION DE MISION ===" << endl;
    cout << nombre << " - Zona: " << zona << endl;

    for (int i = 0; i < cantidadRecursos; ++i)
    {
        cout << "\n[" << recursosAsignados[i]->getTipo() << "] "
             << recursosAsignados[i]->getNombre() << endl;
        recursosAsignados[i]->ejecutarAccion();
    }

    estado = "Ejecutada";
    liberarDisponibilidadRecursos();
    cout << "\nMision finalizada. Los recursos quedaron disponibles nuevamente." << endl;
}
