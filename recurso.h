#ifndef RECURSO_H
#define RECURSO_H

#include <string>

using namespace std;

/*
CRC - Clase Recurso
Responsabilidades:
- Representar el concepto general de recurso de rescate.
- Conservar identificador, nombre y disponibilidad.
- Definir el contrato polimorfico para mostrar informacion y ejecutar una accion.
Colaboraciones:
- Mision, Controlador, Vehiculo, Personal.
*/
class Recurso
{
protected:
    string id;
    string nombre;
    bool disponible;

    void mostrarDatosBase() const;

public:
    Recurso(const string& pId, const string& pNombre);
    virtual ~Recurso();

    const string& getId() const;
    const string& getNombre() const;
    bool estaDisponible() const;
    void setDisponible(bool pDisponible);

    virtual const char* getTipo() const = 0;
    virtual void mostrarInformacion() const = 0;
    virtual void ejecutarAccion() const = 0;
};

#endif