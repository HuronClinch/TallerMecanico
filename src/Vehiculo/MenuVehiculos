#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Vehiculo {
    int idVehiculo;
    int idCliente; // RELACION CON CLIENTE
    char marca[30];
    char modelo[30];
    char placa[15];
};

// CREAR VEHICULO
void crearVehiculo() {
    Vehiculo v;

    cout << "ID Vehiculo: ";
    cin >> v.idVehiculo;

    cout << "ID Cliente: ";
    cin >> v.idCliente;
    cin.ignore();

    cout << "Marca: ";
    cin.getline(v.marca, 30);

    cout << "Modelo: ";
    cin.getline(v.modelo, 30);

    cout << "Placa: ";
    cin.getline(v.placa, 15);

    ofstream archivo("vehiculos.bin", ios::binary | ios::app);

    if (archivo.is_open()) {
        archivo.write((char*)&v, sizeof(Vehiculo));
        archivo.close();
        cout << "\nVehiculo guardado.\n";
    } else {
        cout << "\nError al abrir archivo.\n";
    }
}

// MOSTRAR VEHICULOS
void mostrarVehiculos() {
    Vehiculo v;
    ifstream archivo("vehiculos.bin", ios::binary);

    if (archivo.is_open()) {
        while (archivo.read((char*)&v, sizeof(Vehiculo))) {
            cout << "\nID Vehiculo: " << v.idVehiculo << endl;
            cout << "ID Cliente: " << v.idCliente << endl;
            cout << "Marca: " << v.marca << endl;
            cout << "Modelo: " << v.modelo << endl;
            cout << "Placa: " << v.placa << endl;
            cout << "------------------------\n";
        }
        archivo.close();
    } else {
        cout << "Error al abrir archivo.\n";
    }
}

// BUSCAR VEHICULO
void buscarVehiculo() {
    int id;
    bool encontrado = false;
    Vehiculo v;

    cout << "Ingrese ID Vehiculo: ";
    cin >> id;

    ifstream archivo("vehiculos.bin", ios::binary);

    if (archivo.is_open()) {
        while (archivo.read((char*)&v, sizeof(Vehiculo))) {
            if (v.idVehiculo == id) {
                cout << "\nVehiculo encontrado:\n";
                cout << "Marca: " << v.marca << endl;
                cout << "Modelo: " << v.modelo << endl;
                cout << "Placa: " << v.placa << endl;
                encontrado = true;
            }
        }

        if (!encontrado)
            cout << "No encontrado.\n";

        archivo.close();
    }
}

// EDITAR VEHICULO
void editarVehiculo() {
    int id;
    Vehiculo v;
    bool encontrado = false;

    cout << "Ingrese ID Vehiculo a editar: ";
    cin >> id;
    cin.ignore();

    fstream archivo("vehiculos.bin", ios::in | ios::out | ios::binary);

    if (archivo.is_open()) {
        while (archivo.read((char*)&v, sizeof(Vehiculo))) {
            if (v.idVehiculo == id) {

                cout << "Nueva marca: ";
                cin.getline(v.marca, 30);

                cout << "Nuevo modelo: ";
                cin.getline(v.modelo, 30);

                cout << "Nueva placa: ";
                cin.getline(v.placa, 15);

                archivo.seekp(-sizeof(Vehiculo), ios::cur);
                archivo.write((char*)&v, sizeof(Vehiculo));

                cout << "Vehiculo actualizado.\n";
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
            cout << "Vehiculo no encontrado.\n";

        archivo.close();
    }
}

// ELIMINAR VEHICULO
void eliminarVehiculo() {
    int id;
    Vehiculo v;

    cout << "Ingrese ID Vehiculo a eliminar: ";
    cin >> id;

    ifstream archivo("vehiculos.bin", ios::binary);
    ofstream temp("temp.bin", ios::binary);

    if (archivo.is_open() && temp.is_open()) {
        while (archivo.read((char*)&v, sizeof(Vehiculo))) {
            if (v.idVehiculo != id) {
                temp.write((char*)&v, sizeof(Vehiculo));
            }
        }

        archivo.close();
        temp.close();

        remove("vehiculos.bin");
        rename("temp.bin", "vehiculos.bin");

        cout << "Vehiculo eliminado.\n";
    }
}

// MENU VEHICULOS
void menuVehiculos() {
    int op;

    do {
        cout << "\n=== MODULO VEHICULOS ===\n";
        cout << "1. Crear\n";
        cout << "2. Mostrar\n";
        cout << "3. Buscar\n";
        cout << "4. Editar\n";
        cout << "5. Eliminar\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1: crearVehiculo(); break;
            case 2: mostrarVehiculos(); break;
            case 3: buscarVehiculo(); break;
            case 4: editarVehiculo(); break;
            case 5: eliminarVehiculo(); break;
        }

    } while (op != 6);
}