#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

/*
CRC - Clase Ambulancia
Responsabilidades:
- Representar una ambulancia registrada en el SGMR.
- Ejecutar la accion terrestre propia de una ambulancia.
Colaboraciones:
- Vehiculo, Mision.
*/
class Ambulancia : public Vehiculo
{
public:
    Ambulancia(const string& pId, const string& pNombre,
               const string& pPlaca, int pCapacidad);
    ~Ambulancia() override;

    const char* getTipo() const override;
    void mostrarInformacion() const override;
    void ejecutarAccion() const override;
};

#endif
