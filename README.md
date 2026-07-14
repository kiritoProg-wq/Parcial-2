# Parcial-2

# SGMR — Sistema de Gestión de Misiones de Rescate

Proyecto del Parcial 2 — Fundamentos de Programación Orientada a Objetos (Grupo 80), Universidad del Valle.

## Integrantes
- Nombre completo 1 — Código 1
- Nombre completo 2 — Código 2

## Contexto
Motor lógico para el registro centralizado de recursos humanos y vehiculares (médicos,
rescatistas, ambulancias, helicópteros) y su asignación dinámica a misiones de rescate,
operado desde una consola centralizada.

## Arquitectura

## Estructura del repositorio

## Compilación

```bash
make
./sgmr
```

## Requerimientos técnicos cumplidos
- **HT01**: Colecciones implementadas como arreglos dinámicos de punteros (`Recurso**`, `Mision**`), redimensionados manualmente con `new`/`delete[]`. Cero uso de `std::vector`.
- **HT02**: Destructores explícitos en `Controlador`, `Mision` y toda la jerarquía de `Recurso` para evitar fugas de memoria.
- **HT03**: Todo paso de objetos complejos entre métodos se hace por referencia (`&`) o puntero (`*`).

## Menú principal
1. Ver recursos
2. Registrar recurso
3. Crear misión
4. Asignar recurso a misión
5. Ejecutar misión
6. Salir
7. hola 


# Binarios y objetos de compilación
*.o
*.obj
sgmr
sgmr.exe
build/

# Archivos del sistema/editor
.vscode/
.DS_Store

# codigo del .h de la clase recurso
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
