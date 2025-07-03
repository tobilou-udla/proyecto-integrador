#ifndef GESTION_CONTAMINACION_H
#define GESTION_CONTAMINACION_H

typedef struct {
    char nombre[50];
    float contaminantes[30]; // Últimos 30 días de contaminantes (promedio diario)
    float actual[4]; // Niveles actuales de CO2, SO2, NO2, PM2.5
    float promedioHistorico; // Promedio histórico general
    float prediccion; // Predicción para las próximas 24 horas
} Zona;

void cargarDatosHistoricos(const char *archivo, Zona zonas[], int numZonas);
void ingresarDatosContaminacion(Zona zonas[], int numZonas);
void monitorearActual(Zona zonas[], int numZonas);
void predecirNiveles(Zona zonas[], int numZonas);
void calcularPromedios(Zona zonas[], int numZonas);
void generarReporte(Zona zonas[], int numZonas, const char *archivo);

#endif