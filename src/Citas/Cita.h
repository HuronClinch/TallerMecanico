#ifndef CITA_H
#define CITA_H

struct Cita // Estructura para Citas
{
    int idCita;     // Llave primaria
    int idCliente;  // Relación con Cliente
    char placa[15]; // Relación con Vehículo
    char fecha[20];
    char descripcion[100];
    char estado[20];
    double costo;
};

#endif