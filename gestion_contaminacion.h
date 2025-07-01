#ifndef GESTION_CONTAMINACION_H
#define GESTION_CONTAMINACION_H

#include <stdio.h>
#include <string.h>

#define MAX_ZONAS 5
#define MAX_MEDICIONES 30

typedef struct {
    float pm25;
    float no2;
    float so2;
    float co;
    float temperatura;
    float velocidadViento;
    float humedad;
    char timestamp[20];
} Medicion;

typedef struct {
    char nombre[50];
    Medicion mediciones[MAX_MEDICIONES];
    int numMediciones;
} Zona;

// Funciones principales
int cargarZonas(Zona zonas[]);
void guardarZonas(Zona zonas[], int numZonas);
void registrarMedicion(Zona zonas[], int numZonas);
void mostrarNivelesActuales(Zona zonas[], int numZonas);
void mostrarPrediccion(Zona zonas[], int numZonas);
void emitirAlertas(Zona zonas[], int numZonas);
void mostrarRecomendaciones(Zona zonas[], int numZonas);
void exportarDatos(Zona zonas[], int numZonas);

#endif
