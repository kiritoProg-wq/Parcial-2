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
#ifndef RECURSO_H
#define RECURSO_H

#include <string>

/**
 * Clase base abstracta para todo recurso administrable por el SGMR
 * (vehículos o personal). Define el comportamiento polimórfico común.
 */
class Recurso {
protected:
    int id;
    std::string nombre;
    bool disponible;

public:
    Recurso(int id, const std::string& nombre);
    virtual ~Recurso();

    // Método polimórfico puro: cada tipo de recurso lo implementa distinto (HU03)
    virtual void ejecutarAccion() const = 0;

    // Método virtual con implementación base, extensible por los hijos
    virtual void mostrarInfo() const;

    int getId() const;
    std::string getNombre() const;
    bool isDisponible() const;
    void setDisponible(bool valor);
};

#endif
