#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>

using namespace std;

class Recurso;
class Mision;
class Controlador
{
private:
    Recurso** listaRecursos;
    int cantidadRecursos;
    int capacidadRecursos;

    Mision** listaMisiones;
    int cantidadMisiones;
    int capacidadMisiones;

    void cargarDatosPrueba();
    void mostrarMenu() const;
    void verRecursos() const;
    void verMisiones() const;
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMision();

    void agregarRecursoGeneral(Recurso* recurso);
    void agregarMisionGeneral(Mision* mision);
    void redimensionarRecursos();
    void redimensionarMisiones();

    Recurso* buscarRecursoPorId(const string& idBuscado) const;
    Mision* buscarMisionPorId(const string& idBuscado) const;

    int leerEnteroEnRango(const string& mensaje, int minimo, int maximo) const;
    int leerEnteroPositivo(const string& mensaje) const;
    string leerTextoNoVacio(const string& mensaje) const;

public:
    Controlador();
    ~Controlador();

    void iniciar();
};

#endif