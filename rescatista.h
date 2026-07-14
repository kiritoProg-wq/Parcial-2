#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"


class Rescatista : public Personal
{
public:
    Rescatista(const string& pId, const string& pNombre,
               const string& pEspecialidad);
    ~Rescatista() override;

    const char* getTipo() const override;
    void mostrarInformacion() const override;
    void ejecutarAccion() const override;
};

#endif
