#ifndef MISION_H
#define MISION_H

#include <string>

using namespace std;

class Recurso;

/*
CRC - Clase Mision
Responsabilidades:
- Conservar los datos de una mision de emergencia.
- Conocer recursos heterogeneos mediante punteros a Recurso.
- Redimensionar manualmente su arreglo dinamico.
- Ejecutar polimorficamente las acciones de los recursos asignados.
Colaboraciones:
- Recurso, Controlador.

Propiedad de memoria:
- La Mision es propietaria del arreglo dinamico Recurso**.
- La Mision NO es propietaria de los objetos Recurso apuntados.
- Controlador destruye los objetos Recurso para evitar doble liberacion.
*/
class Mision
{
private:
    string id;
    string nombre;
    string zona;
    string estado;

    Recurso** recursosAsignados;
    int cantidadRecursos;
    int capacidadRecursos;

    void redimensionarRecursos();
    bool contieneRecurso(const Recurso* recurso) const;
    void liberarDisponibilidadRecursos();

public:
    Mision(const string& pId, const string& pNombre, const string& pZona);
    ~Mision();

    const string& getId() const;
    const string& getNombre() const;
    const string& getZona() const;
    const string& getEstado() const;
    int getCantidadRecursos() const;

    bool agregarRecurso(Recurso* recurso);
    void mostrarInformacion() const;
    void ejecutar();
};

#endif
