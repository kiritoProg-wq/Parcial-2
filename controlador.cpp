#include "Controlador.h"
#include "Recurso.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"
#include "Mision.h"
#include <iostream>
#include <limits>

Controlador::Controlador()
    : listaRecursos(nullptr), cantidadRecursos(0), capacidadRecursos(4),
      listaMisiones(nullptr), cantidadMisiones(0), capacidadMisiones(2)
{
    listaRecursos = new Recurso*[capacidadRecursos];
    for (int i = 0; i < capacidadRecursos; ++i)
    {
        listaRecursos[i] = nullptr;
    }

    listaMisiones = new Mision*[capacidadMisiones];
    for (int i = 0; i < capacidadMisiones; ++i)
    {
        listaMisiones[i] = nullptr;
    }

    cargarDatosPrueba();
}

Controlador::~Controlador()
{
    for (int i = 0; i < cantidadMisiones; ++i)
    {
        delete listaMisiones[i];
        listaMisiones[i] = nullptr;
    }
    delete[] listaMisiones;
    listaMisiones = nullptr;

    for (int i = 0; i < cantidadRecursos; ++i)
    {
        delete listaRecursos[i];
        listaRecursos[i] = nullptr;
    }
    delete[] listaRecursos;
    listaRecursos = nullptr;
}

void Controlador::redimensionarRecursos()
{
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < nuevaCapacidad; ++i)
    {
        nuevoArreglo[i] = nullptr;
    }

    for (int i = 0; i < cantidadRecursos; ++i)
    {
        nuevoArreglo[i] = listaRecursos[i];
    }

    delete[] listaRecursos;
    listaRecursos = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Controlador::redimensionarMisiones()
{
    int nuevaCapacidad = capacidadMisiones * 2;
    Mision** nuevoArreglo = new Mision*[nuevaCapacidad];

    for (int i = 0; i < nuevaCapacidad; ++i)
    {
        nuevoArreglo[i] = nullptr;
    }

    for (int i = 0; i < cantidadMisiones; ++i)
    {
        nuevoArreglo[i] = listaMisiones[i];
    }

    delete[] listaMisiones;
    listaMisiones = nuevoArreglo;
    capacidadMisiones = nuevaCapacidad;
}

void Controlador::agregarRecursoGeneral(Recurso* recurso)
{
    if (recurso == nullptr)
    {
        return;
    }

    if (cantidadRecursos == capacidadRecursos)
    {
        redimensionarRecursos();
    }

    listaRecursos[cantidadRecursos] = recurso;
    ++cantidadRecursos;
}

void Controlador::agregarMisionGeneral(Mision* mision)
{
    if (mision == nullptr)
    {
        return;
    }

    if (cantidadMisiones == capacidadMisiones)
    {
        redimensionarMisiones();
    }

    listaMisiones[cantidadMisiones] = mision;
    ++cantidadMisiones;
}

Recurso* Controlador::buscarRecursoPorId(const string& idBuscado) const
{
    for (int i = 0; i < cantidadRecursos; ++i)
    {
        if (listaRecursos[i]->getId() == idBuscado)
        {
            return listaRecursos[i];
        }
    }
    return nullptr;
}

Mision* Controlador::buscarMisionPorId(const string& idBuscado) const
{
    for (int i = 0; i < cantidadMisiones; ++i)
    {
        if (listaMisiones[i]->getId() == idBuscado)
        {
            return listaMisiones[i];
        }
    }
    return nullptr;
}

int Controlador::leerEnteroEnRango(const string& mensaje, int minimo, int maximo) const
{
    int valor;

    while (true)
    {
        cout << mensaje;
        if (cin >> valor && valor >= minimo && valor <= maximo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        cout << "Entrada invalida. Intente nuevamente." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int Controlador::leerEnteroPositivo(const string& mensaje) const
{
    int valor;

    while (true)
    {
        cout << mensaje;
        if (cin >> valor && valor > 0)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        cout << "Debe ingresar un entero positivo." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string Controlador::leerTextoNoVacio(const string& mensaje) const
{
    string texto;

    while (true)
    {
        cout << mensaje;
        getline(cin, texto);
        if (!texto.empty())
        {
            return texto;
        }
        cout << "El dato no puede quedar vacio." << endl;
    }
}

void Controlador::cargarDatosPrueba()
{
    agregarRecursoGeneral(new Ambulancia("A01", "Ambulancia Norte", "UV-A01", 4));
    agregarRecursoGeneral(new Ambulancia("A02", "Ambulancia Sur", "UV-A02", 3));
    agregarRecursoGeneral(new Helicoptero("H01", "Halcon Uno", "HK-2026", 6));
    agregarRecursoGeneral(new Medico("M01", "Laura Gomez", "Urgencias"));
    agregarRecursoGeneral(new Medico("M02", "Carlos Ruiz", "Trauma"));
    agregarRecursoGeneral(new Rescatista("R01", "Diana Lopez", "Rescate vertical"));
    agregarRecursoGeneral(new Rescatista("R02", "Mateo Diaz", "Busqueda en estructuras"));

    Mision* misionUno = new Mision("MS01", "Evacuacion Rio Pance", "Cali - Pance");
    Mision* misionDos = new Mision("MS02", "Deslizamiento La Buitrera", "Cali - La Buitrera");
    agregarMisionGeneral(misionUno);
    agregarMisionGeneral(misionDos);

    // Datos preasignados para que el profesor pueda ejecutar una mision de inmediato.
    misionUno->agregarRecurso(buscarRecursoPorId("A01"));
    misionUno->agregarRecurso(buscarRecursoPorId("H01"));
    misionUno->agregarRecurso(buscarRecursoPorId("M01"));
    misionUno->agregarRecurso(buscarRecursoPorId("R01"));
}

void Controlador::mostrarMenu() const
{
    cout << "\n========================================" << endl;
    cout << " SISTEMA DE GESTION DE MISIONES DE RESCATE" << endl;
    cout << "========================================" << endl;
    cout << "1. Ver recursos" << endl;
    cout << "2. Registrar recurso" << endl;
    cout << "3. Crear mision" << endl;
    cout << "4. Asignar recurso a mision" << endl;
    cout << "5. Ejecutar mision" << endl;
    cout << "6. Salir" << endl;
}

void Controlador::verRecursos() const
{
    cout << "\n=== INVENTARIO DE RECURSOS ===" << endl;
    for (int i = 0; i < cantidadRecursos; ++i)
    {
        cout << "\nRecurso " << (i + 1) << endl;
        listaRecursos[i]->mostrarInformacion();
    }
}

void Controlador::verMisiones() const
{
    cout << "\n=== MISIONES REGISTRADAS ===" << endl;
    for (int i = 0; i < cantidadMisiones; ++i)
    {
        cout << "\nMision " << (i + 1) << endl;
        listaMisiones[i]->mostrarInformacion();
    }
}

void Controlador::registrarRecurso()
{
    cout << "\n=== REGISTRAR RECURSO ===" << endl;
    cout << "1. Ambulancia" << endl;
    cout << "2. Helicoptero" << endl;
    cout << "3. Medico" << endl;
    cout << "4. Rescatista" << endl;

    int tipo = leerEnteroEnRango("Seleccione el tipo: ", 1, 4);
    string idRecurso = leerTextoNoVacio("ID unico: ");

    if (buscarRecursoPorId(idRecurso) != nullptr)
    {
        cout << "Ya existe un recurso con ese ID." << endl;
        return;
    }

    string nombreRecurso = leerTextoNoVacio("Nombre: ");
    Recurso* nuevoRecurso = nullptr;

    if (tipo == 1 || tipo == 2)
    {
        string placa = leerTextoNoVacio("Placa o matricula: ");
        int capacidad = leerEnteroPositivo("Capacidad: ");

        if (tipo == 1)
        {
            nuevoRecurso = new Ambulancia(idRecurso, nombreRecurso, placa, capacidad);
        }
        else
        {
            nuevoRecurso = new Helicoptero(idRecurso, nombreRecurso, placa, capacidad);
        }
    }
    else
    {
        string especialidad = leerTextoNoVacio("Especialidad: ");

        if (tipo == 3)
        {
            nuevoRecurso = new Medico(idRecurso, nombreRecurso, especialidad);
        }
        else
        {
            nuevoRecurso = new Rescatista(idRecurso, nombreRecurso, especialidad);
        }
    }

    agregarRecursoGeneral(nuevoRecurso);
    cout << "Recurso registrado correctamente." << endl;
}

void Controlador::crearMision()
{
    cout << "\n=== CREAR MISION ===" << endl;
    string idMision = leerTextoNoVacio("ID unico de la mision: ");

    if (buscarMisionPorId(idMision) != nullptr)
    {
        cout << "Ya existe una mision con ese ID." << endl;
        return;
    }

    string nombreMision = leerTextoNoVacio("Nombre de la mision: ");
    string zonaMision = leerTextoNoVacio("Zona de desastre: ");

    agregarMisionGeneral(new Mision(idMision, nombreMision, zonaMision));
    cout << "Mision creada correctamente." << endl;
}

void Controlador::asignarRecursoAMision()
{
    verMisiones();
    string idMision = leerTextoNoVacio("\nID de la mision: ");
    Mision* mision = buscarMisionPorId(idMision);

    if (mision == nullptr)
    {
        cout << "Mision no encontrada." << endl;
        return;
    }

    verRecursos();
    string idRecurso = leerTextoNoVacio("\nID del recurso: ");
    Recurso* recurso = buscarRecursoPorId(idRecurso);

    if (recurso == nullptr)
    {
        cout << "Recurso no encontrado." << endl;
        return;
    }

    if (mision->agregarRecurso(recurso))
    {
        cout << "Recurso asignado correctamente a la mision." << endl;
    }
    else
    {
        cout << "No fue posible asignar el recurso. Verifique disponibilidad, duplicados o estado de la mision." << endl;
    }
}

void Controlador::ejecutarMision()
{
    verMisiones();
    string idMision = leerTextoNoVacio("\nID de la mision que desea ejecutar: ");
    Mision* mision = buscarMisionPorId(idMision);

    if (mision == nullptr)
    {
        cout << "Mision no encontrada." << endl;
        return;
    }

    mision->ejecutar();
}

void Controlador::iniciar()
{
    int opcion;

    do
    {
        mostrarMenu();
        opcion = leerEnteroEnRango("Seleccione una opcion: ", 1, 6);

        switch (opcion)
        {
            case 1:
                verRecursos();
                break;
            case 2:
                registrarRecurso();
                break;
            case 3:
                crearMision();
                break;
            case 4:
                asignarRecursoAMision();
                break;
            case 5:
                ejecutarMision();
                break;
            case 6:
                cout << "Cerrando el sistema y liberando memoria dinamica..." << endl;
                break;
        }
    }
    while (opcion != 6);
}