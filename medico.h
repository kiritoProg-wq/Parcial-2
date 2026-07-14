#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"

/*
CRC - Clase Medico
Responsabilidades:
- Representar un medico registrado en el SGMR.
- Ejecutar la accion medica propia de su rol.
Colaboraciones:
- Personal, Mision.
*/
class Medico : public Personal
{
public:
    Medico(const string& pId, const string& pNombre,
           const string& pEspecialidad);
    ~Medico() override;

    const char* getTipo() const override;
    void mostrarInformacion() const override;
    void ejecutarAccion() const override;
};

#endif
