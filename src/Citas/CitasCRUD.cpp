#include <iostream>
#include <fstream>
#include <stdexcept> // Necesario para runtime_error
#include "Cita.h"    //Estructura de Citas

using namespace std;

/*
    Clase DRUD para citas, la cual tiene metodos: Crear, Leer, BuscarPoId Editar Eliminar por medio de objetos
    Crear y editar se hace por objetos
    Buscar por id y eliminar se hace por el id a buscar
    <<Creado por: Norman Santizo>>
*/
class CitasCRUD
{
private:
    const string ARCHIVO = "citas.bin"; // Nombre para el archivo binario

    int generarSiguienteId() // Calcula el siguiente ID disponible
    {
        ifstream documento(ARCHIVO, ios::binary | ios::ate); // Leer datos del documento

        if (!documento || documento.tellg() == 0) // Si no existe el archivo o esta vacio es 1
            return 1;

        int tamanoArchivo = documento.tellg();         // Posicion del ultimo registro registro
        documento.seekg(tamanoArchivo - sizeof(Cita)); // Ir a posicion del ultimo objeto

        Cita ultimaCita;

        documento.read((char *)&ultimaCita, sizeof(Cita)); // Leer documento

        documento.close(); // Cerrar documento

        return ultimaCita.idCita + 1; // Nuevo id de cita
    }

public:
    void crear(Cita nuevaCita) // Metodo para crear nueva cita
    {
        nuevaCita.idCita = generarSiguienteId(); // Crear el Id automaticamente

        ofstream documento(ARCHIVO, ios::binary | ios::app); // Escribir en archivo

        if (documento)
        {
            documento.write((char *)&nuevaCita, sizeof(Cita));
            documento.close(); // Cerrar documento
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    Cita guardada exitosamente\n"
                 << "     Id: " << nuevaCita.idCita
                 << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
        else
        {
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    Error en abrir el documento\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
    }

    void leer() // Merodo para ver todas las citas
    {
        ifstream documento(ARCHIVO, ios::binary); // Leer datos del documento

        if (!documento) // Si no existe el archivo
        {
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       No hay registros\n"
                 << "    o el archivo no existe\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            return;
        }

        Cita tmp; // Cita temporal para visualizar
        cout << "\n\n\n~~~~~~~ LISTADO DE CITAS ~~~~~~~";

        while (documento.read((char *)&tmp, sizeof(Cita))) // Leer documento
        {
            cout << "   \nID: " << tmp.idCita
                 << "   \nPlaca: " << tmp.placa
                 << "   \nFecha: " << tmp.fecha
                 << "   \nEstado: " << tmp.estado
                 << "   \nCosto: $" << tmp.costo
                 << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        documento.close(); // Cerrar documento
    }

    Cita buscarPorId(int id) // Metodo para buscar por id
    {
        ifstream documento(ARCHIVO, ios::binary); // Leer datos del documento

        if (!documento) // Si no existe el archivo
        {
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       No hay registros\n"
                 << "    o el archivo no existe\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        Cita tmp; // Cita temporal para visualizar

        while (documento.read((char *)&tmp, sizeof(Cita))) // Leer documento
        {
            if (tmp.idCita == id) // Si se encuentra cita por id
            {
                documento.close(); // Cerrar documento
                return tmp;
            }
        }

        documento.close(); // Cerrar documento
        tmp.idCita = -1;   // Si no fue encuentrada cita por id
        return tmp;
    }

    void editar(Cita editarCita) // Metodo para editar cita
    {
        fstream documento(ARCHIVO, ios::binary | ios::in | ios::out); // Leer y escribir en documento

        if (!documento) // Si no existe el archivo
        {
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       No hay registros\n"
                 << "    o el archivo no existe\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            return;
        }

        Cita tmp; // Cita temporal para visualizar
        bool encontrado = false;

        while (documento.read((char *)&tmp, sizeof(Cita))) // Leer documento
        {
            if (tmp.idCita == editarCita.idCita) // Encontrar id de cita
            {
                encontrado = true;                                 // Definie que fue encontrado
                long pos = (long)documento.tellg() - sizeof(Cita); // Obtener posicion del objeto de cita
                documento.seekp(pos);

                documento.write(reinterpret_cast<char *>(&editarCita), sizeof(Cita)); // Remplazar objeto
                break;
            }
        }

        documento.close(); // Cerrar documento

        if (encontrado)
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    La cita fue actualizada exitosamente\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        else
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "               Error\n"
                 << "   No se encontro el ID en el archivo\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

        documento.close(); // Cerrar documento
    }

    void eliminar(int id) // Metodo para eliminar por id
    {
        ifstream documento(ARCHIVO, ios::binary); // Leer datos del documento

        if (!documento) // Si no existe el archivo
        {
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "       No hay registros\n"
                 << "    o el archivo no existe\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            return;
        }

        ofstream tmpDocumento("temp.bin", ios::binary); // Escrir datos del documento
        Cita tmp;                                       // Cita temporal para visualizar

        bool encontrado = false;

        while (documento.read((char *)&tmp, sizeof(Cita))) // Leer documento
        {
            if (tmp.idCita != id) // Si encontramos cita
            {
                tmpDocumento.write((char *)&tmp, sizeof(Cita));
            }
            else // Si se encontro, solo se salta
            {
                encontrado = true;
            }
        }

        documento.close();    // Cerrar documento
        tmpDocumento.close(); // Cerrar documento

        remove(ARCHIVO.c_str());             // Eliminamos documento acual
        rename("temp.bin", ARCHIVO.c_str()); // Renombramos documento temporal

        if (encontrado) // Si se elimino el registro
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    La cita fue eliminada correctamente\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        else
            cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "    No se encontro el ID de la cita\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }
};