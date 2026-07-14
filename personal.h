#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"

/*
CRC - Clase Personal
Responsabilidades:
- Agrupar los datos comunes del personal de rescate.
- Conservar la especialidad profesional u operativa.
Colaboraciones:
- Recurso, Medico, Rescatista.
*/
class Personal : public Recurso
{
protected:
    string especialidad;

    void mostrarDatosPersonal() const;

public:
    Personal(const string& pId, const string& pNombre,
             const string& pEspecialidad);
    virtual ~Personal();

    const string& getEspecialidad() const;
};

#endif
