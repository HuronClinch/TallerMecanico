#include <iostream>
#include <cstring>
#include "CitasCRUD.cpp"

using namespace std;

class MenuCitas
{
private:
    CitasCRUD CRUD; // Crud para Citas

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
                    /*Logica*/
                    break;
                }
                case 2: // Menu para listar Cita
                    /*Logica*/
                    break;
                case 3: // Menu para buscar Cita
                {
                    /*Logica*/
                    break;
                }
                case 4: // Menu para editar Cita
                {
                    /*Logica*/
                    break;
                }
                case 5: // Menu para eliminar Cita
                {
                    /*Logica*/
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