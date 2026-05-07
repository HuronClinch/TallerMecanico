#include <iostream>
#include "../Citas/MenuCitas.cpp"        //Menu para citas
#include "../Vehiculo/MenuVehiculos.cpp" //Menu para vehiculo
#include "../Cliente/MenuCliente.cpp"    //Menu para Clientes

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
                    menuClientes(); // Llamar metodo para menu de clientes
                    break;
                }
                case 2: // Catalogo para Vehiculos
                {
                    menuVehiculos(); // Llamar metodo para vehiculos
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