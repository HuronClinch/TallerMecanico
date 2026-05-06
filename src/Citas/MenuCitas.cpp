#include <iostream>
#include <cstring>
#include "CitasCRUD.cpp"

using namespace std;

class MenuCitas
{
private:
    CitasCRUD CRUD; // Crud para Citas

    void menuCrear() // Ingresar datos para nueva cita
    {
        Cita cita; // Objeto de cita

        cout << "\n\n\n~~~~~~ Crear nueva cita ~~~~~~\n"
             << " Ingrese los siguintes datos:\n";
        cout << "  ID Cita: ";
        cin >> cita.idCita;
        cout << "   ID Cliente: ";
        cin >> cita.idCliente;
        cout << "   Placa: ";
        cin >> cita.placa;
        cout << "   Fecha: ";
        cin >> cita.fecha;
        cout << "   Estado: ";
        cin >> cita.estado;
        cout << "   Costo: ";
        cin >> cita.costo;

        CRUD.crear(cita); // Crear objeto
    }

    void menuBuscar() // Buscar todas las citas
    {
        int id;
        cout << "\n\n\n~~~~~~~ Buscar cita ~~~~~~~\n"
             << "   Ingrese ID a buscar: ";
        cin >> id;

        Cita cita = CRUD.buscarPorId(id); // Objeto de cita encontrado

        if (cita.idCita != -1) // Si se encontro cita
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    La cita fue encontrada\n "
                 << "       Placa: " << cita.placa << endl
                 << "       Fecha: " << cita.fecha << endl
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        else // No eciste cita
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    No existe la cita\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    void editarCita() // Editar a usario por id
    {
        int id;

        cout << "\n\n\n~~~~~~~~~~~~~ Editar cita ~~~~~~~~~~~~~\n"
             << "   Ingrese ID de la cita a editar: ";
        cin >> id;

        Cita cita = CRUD.buscarPorId(id); // Objeto de cita

        if (cita.idCita != -1) // Si de encuentra cita
        {
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    Editando Cita " << id << endl
                 << "       Nuevo Estado: ";
            cin >> cita.estado;
            cout << "       Nuevo Costo: ";
            cin >> cita.costo;

            CRUD.editar(cita); // Guardar los cambios

            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    La cita se actualizo corectamente\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
        else
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "          La cita\n"
                 << "   Cita no fue encontrada"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    void eliminarCita() // Eliminar
    {
        int id;

        cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~\n"
             << "   Eliminando Cita " << id << endl
             << "   ID a eliminar:";
        cin >> id;

        CRUD.eliminar(id); // Eliminar cita por id
    }

public:
    void menuCitas() // Menu del catalogo de citas
    {
        bool salir = false;
        string opcion;
        do
        {
            cout << "\n\n\n~~ CATALOGO DE CITAS ~~\n"
                 << "   1. Crear\n"
                 << "   2. Listar\n"
                 << "   3. Buscar\n"
                 << "   4. Editar\n"
                 << "   5. Eliminar\n"
                 << "   0. Volver\n"
                 << "   Opcion: ";
            cin >> opcion;
            try
            {
                int temp = stoi(opcion); // Canvertir el texto a numero

                switch (temp)
                {
                case 0: // Salir
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~\n"
                         << "     Saliendo del \n"
                         << "   Catalogo de citas\n"
                         << "~~~~~~~~~~~~~~~~~~~~~~~\n";
                    salir = true;
                    break;
                }
                case 1: // Menu para crear Cita
                {
                    menuCrear(); // Crear nuevo objeto de citas
                    break;
                }
                case 2:          // Menu para listar Cita
                    CRUD.leer(); // Ver todas las citas
                    break;
                case 3: // Menu para buscar Cita
                {
                    menuBuscar(); // Buscar por id
                    break;
                }
                case 4: // Menu para editar Cita
                {
                    editarCita(); // Editar cita por id
                    break;
                }
                case 5: // Menu para eliminar Cita
                {
                    eliminarCita(); // Eliminar cita por id
                    break;
                }
                default:
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                         << "      Opcion incorrecta \n"
                         << "   Elija una opcion de 0-5\n"
                         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    break;
                }
            }
            catch (const exception &e)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                     << "   Opcion ingresado incorrecta\n "
                     << "   Ingrese una opcion del 0-5\n"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
        } while (!salir); // Mientras no elija salir
    }
};