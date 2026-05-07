#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Cliente
{
    int idCliente;
    char nombre[50];
    char apellido[50];
    char telefono[15];
    char nit[16];
    char correo[50];
};

void crearCliente()
{
    system("cls");
    Cliente cliente;
    bool existeId = false;
    cout << "\n\n\n";
    cout << "-----------------------------------------" << endl;
    cout << "        Registro de nuevo cliente        " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "\nID Cliente: ";
    cin >> cliente.idCliente;
    cin.ignore();
    ifstream ARCHIVO_LEER("clientes.bin", ios::binary);
    Cliente aux;
    if (ARCHIVO_LEER.is_open())
    {

        while (ARCHIVO_LEER.read((char *)&aux, sizeof(Cliente)))
        {

            if (aux.idCliente == cliente.idCliente)
            {
                existeId = true;
                break;
            }
        }
        ARCHIVO_LEER.close();
    }
    if (existeId)
    {
        cout << endl;
        cout << "Este ID ya se encuentra registrado" << endl;
        system("pause");
        return;
    }

    cout << "Nombre: ";
    cin.getline(cliente.nombre, 50);
    cout << "Apellido: ";
    cin.getline(cliente.apellido, 50);
    cout << "Telefono: ";
    cin.getline(cliente.telefono, 15);
    cout << "NIT: ";
    cin.getline(cliente.nit, 16);
    cout << "Correo: ";
    cin.getline(cliente.correo, 50);
    ofstream ARCHIVO_ESCRIBIR("clientes.bin", ios::binary | ios::app);
    if (ARCHIVO_ESCRIBIR.is_open())
    {
        ARCHIVO_ESCRIBIR.write((char *)&cliente, sizeof(Cliente));
        ARCHIVO_ESCRIBIR.close();
        cout << endl;
        cout << "El cliente fue registrado con exito" << endl;
    }
    else
    {
        cout << endl;
        cout << "Error de apertura de archivo" << endl;
    }
    cout << "\n\n\n";
    system("pause");
}
void mostrarClientes()
{
    system("cls");
    Cliente cliente;
    ifstream ARCHIVO("clientes.bin", ios::binary);
    if (ARCHIVO.is_open())
    {
        cout << "\n\n\n";
        cout << "-----------------------------------------" << endl;
        cout << "           Listado de clientes             " << endl;
        cout << "-----------------------------------------\n\n";
        while (ARCHIVO.read((char *)&cliente, sizeof(Cliente)))
        {
            cout << "\n\nCliente registrado\n\n";
            cout << "ID: " << cliente.idCliente << endl;
            cout << "Nombre: " << cliente.nombre << " " << cliente.apellido << endl;
            cout << "Telefono: " << cliente.telefono << endl;
            cout << "NIT: " << cliente.nit << endl;
            cout << "Correo: " << cliente.correo << endl;
        }

        ARCHIVO.close();
    }
    else
    {
        cout << endl;
        cout << "Error de apertura de archivo" << endl;
    }
    cout << "\n\n\n";
    system("pause");
}
void buscarCliente()
{
    system("cls");
    int id;
    bool encontrado = false;
    Cliente cliente;

    cout << "\n\n\n";
    cout << "-----------------------------------------" << endl;
    cout << "              Buscar cliente              " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese ID: ";
    cin >> id;

    ifstream ARCHIVO("clientes.bin", ios::binary);
    if (ARCHIVO.is_open())
    {

        while (ARCHIVO.read((char *)&cliente, sizeof(Cliente)))
        {
            if (cliente.idCliente == id)
            {
                cout << "\nCliente encontrado\n";
                cout << "\nNombre: " << cliente.nombre << " " << cliente.apellido << endl;
                cout << "Telefono: " << cliente.telefono << endl;
                cout << "Correo: " << cliente.correo << endl;
                cout << "NIT: " << cliente.nit << endl;
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            cout << endl;
            cout << "No se encontro ningun cliente con ese ID" << endl;
        }
        ARCHIVO.close();
    }
    else
    {
        cout << endl;
        cout << "Error de apertura de archivo" << endl;
    }
    cout << "\n\n\n";
    system("pause");
}
void editarCliente()
{
    system("cls");
    int id;
    bool encontrado = false;
    Cliente cliente;
    cout << "\n\n\n";
    cout << "-----------------------------------------" << endl;
    cout << "            Editar informacion              " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese ID del cliente a modificar: ";
    cin >> id;
    cin.ignore();

    ifstream ARCHIVO("clientes.bin", ios::binary);
    ofstream temporal("temp.bin", ios::binary);

    if (ARCHIVO.is_open() && temporal.is_open())
    {

        while (ARCHIVO.read((char *)&cliente, sizeof(Cliente)))
        {

            if (cliente.idCliente == id)
            {
                encontrado = true;
                cout << "\nIngrese los nuevos datos" << endl;
                cout << "Nombre: ";
                cin.getline(cliente.nombre, 50);
                cout << "Apellido: ";
                cin.getline(cliente.apellido, 50);
                cout << "Telefono: ";
                cin.getline(cliente.telefono, 15);
                cout << "NIT: ";
                cin.getline(cliente.nit, 16);

                cout << "Correo: ";
                cin.getline(cliente.correo, 50);
            }
            temporal.write((char *)&cliente, sizeof(Cliente));
        }
        ARCHIVO.close();
        temporal.close();
        if (encontrado)
        {
            remove("clientes.bin");
            rename("temp.bin", "clientes.bin");
            cout << "\nDatos actualizados correctamente" << endl;
        }
        else
        {
            remove("temp.bin");
            cout << "Cliente no encontrado" << endl;
        }
    }
    else
    {
        cout << "\n\nError de apertura de archivo" << endl;
    }
    cout << "\n\n\n";
    system("pause");
}
void eliminarCliente()
{
    system("cls");
    int id;
    Cliente cliente;
    bool encontrado = false;

    cout << "\n\n\n";
    cout << "-----------------------------------------" << endl;
    cout << "             Eliminar cliente              " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese ID del cliente a eliminar: ";
    cin >> id;

    ifstream ARCHIVO("clientes.bin", ios::binary);
    ofstream temp("temp.bin", ios::binary);

    if (ARCHIVO.is_open() && temp.is_open())
    {

        while (ARCHIVO.read((char *)&cliente, sizeof(Cliente)))
        {

            if (cliente.idCliente != id)
            {

                temp.write((char *)&cliente, sizeof(Cliente));
            }
            else
            {

                encontrado = true;
            }
        }
        ARCHIVO.close();
        temp.close();
        remove("clientes.bin");
        rename("temp.bin", "clientes.bin");
        if (encontrado)
        {
            cout << "\nCliente eliminado" << endl;
        }
        else
        {

            cout << "\nCliente no encontrado" << endl;
        }
    }
    else
    {
        cout << "\n\nError de apertura de archivo" << endl;
    }
    cout << "\n\n\n";
    system("pause");
}
void menuClientes()
{
    int opcion;
    do
    {
        system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "                 CLIENTES                  " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "\n\n\n";
        cout << "1) Registrar cliente" << endl;
        cout << "2) Ver clientes" << endl;
        cout << "3) Buscar cliente" << endl;
        cout << "4) Modificar cliente" << endl;
        cout << "5) Eliminar cliente" << endl;
        cout << "0) Regresar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            crearCliente();
            break;
        case 2:
            mostrarClientes();
            break;
        case 3:
            buscarCliente();
            break;
        case 4:
            editarCliente();
            break;
        case 5:
            eliminarCliente();
            break;
        case 0:
            cout << "\nRegresando al menu principal\n";
            break;
        default:
            cout << "\nOpcion no valida\n";
            cout << "\n\n\n";
            system("pause");
        }
    } while (opcion != 0);
}