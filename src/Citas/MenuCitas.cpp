#include <iostream>
#include <cstring>
#include "CitasCRUD.cpp"

using namespace std;

class MenuCitas
{
private:
    CitasCRUD CRUD; // Crud para Citas

    void limpiar() // Limpiar la entrada en caso de error
    {
        if (cin.fail())
        {
            cin.clear();            // Limpia el error
            cin.ignore(1000, '\n'); // Descarta error
            throw invalid_argument("Entrada invalida. Se esperaba un dato numerico.");
        }
    }

    void menuCrear() // Ingresar datos para nueva cita
    {
        try
        {
            Cita cita; // Objeto de cita

            cout << "\n\n\n~~~~~~ Crear nueva cita ~~~~~~\n"
                 << " Ingrese los siguintes datos:\n";

            cout << "   ID Cliente: ";
            cin >> cita.idCliente;
            limpiar(); // Limpiar la entrada
            cout << "   Placa: ";
            cin >> cita.placa;
            cout << "   Fecha (dd/mm/aaaa): ";
            cin >> cita.fecha;
            cout << "   Descripcion del problema: ";
            cin.ignore(); // Limpiar
            cin.getline(cita.descripcion, 100);
            cout << "   Estado: ";
            cin >> cita.estado;
            cout << "   Costo: ";
            cin >> cita.costo;
            limpiar(); // Limpiar la entrada

            CRUD.crear(cita); // Crear objeto
        }
        catch (const exception &e)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       !!!Error en datos!!!\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }

    void menuBuscar() // Buscar todas las citas
    {
        try
        {
            int id;
            cout << "\n\n\n~~~~~~~ Buscar cita ~~~~~~~\n"
                 << "   Ingrese ID a buscar: ";
            if (!(cin >> id))
            {
                limpiar(); // Limpiar la entrada
            }

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
        catch (const exception &e)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       !!!Error en datos!!!\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }

    void editarCita() // Editar a usario por id
    {
        try
        {
            int id;

            cout << "\n\n\n~~~~~~~~~~~~~ Editar cita ~~~~~~~~~~~~~\n"
                 << "   Ingrese ID de la cita a editar: ";
            if (!(cin >> id))
            {
                limpiar(); // Limpiar la entrada
            }
            Cita cita = CRUD.buscarPorId(id); // Objeto de cita

            if (cita.idCita != -1) // Si de encuentra cita
            {
                cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                     << "    Editando Cita " << id << endl
                     << "       Nuevo Estado: ";
                cin >> cita.estado;
                limpiar(); // Limpiar la entrada
                cout << "       Nuevo Costo: ";
                cin >> cita.costo;
                limpiar(); // Limpiar la entrada

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
        catch (const exception &e)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       !!!Error en datos!!!\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }

    void eliminarCita() // Eliminar
    {
        try
        {
            int id;

            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~\n"
                 << "   Eliminando Cita " << id << endl
                 << "   ID a eliminar:";
            if (!(cin >> id))
            {
                limpiar(); // Limpiar la entrada
            }
            CRUD.eliminar(id); // Eliminar cita por id
        }
        catch (const exception &e)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       !!!Error en datos!!!\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
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