#include <iostream>
#include "../Citas/MenuCitas.cpp" //Menu para citas

using namespace std;

class MenuTaller
{
public:
    void menu() // Menu para elegir catalogos
    {
        bool salir = false;
        string opcion;

        do
        {
            cout << "\n\n\n~~ TALLER MECANICO ~~\n"
                 << "   1. Clientes\n"
                 << "   2. Vehiculos\n"
                 << "   3. Citas\n"
                 << "   0. Salir\n"
                 << "   Opcion: ";
            cin >> opcion;
            try
            {
                int temp = stoi(opcion); // Canvertir el texto a numero

                switch (temp)
                {
                case 0: // Salir de eleccion de Catalogos
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                         << "   Saliendo del taller\n"
                         << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    salir = true;
                    break;
                }
                case 1: // Catalogo para clientes
                {
                    /*Logica para catalogo*/
                    break;
                }
                case 2: // Catalogo para Vehiculos
                {
                    /*Logica para catalogo*/
                    break;
                }
                case 3: // Catalogo para Citas
                {
                    MenuCitas menuCitas;
                    menuCitas.menuCitas();
                    break;
                }
                default:
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                         << "      Opcion incorrecta \n"
                         << "   Elija una opcion de 0-3\n"
                         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    break;
                }
            }
            catch (const std::exception &e)
            {
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                     << "   Error, el dato ingresado no es valido\n"
                     << "   Ingrese opcion de 1-5" << endl
                     << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
        } while (!salir); // Mientras no elija salir
    }
};