#include <stdio.h>
#include <string.h>
#include "gestion_contaminacion.h"

void cargarDatosHistoricos(const char *archivo, Zona zonas[], int numZonas) {
    FILE *file = fopen(archivo, "rb");
    if (!file) {
        printf("Error al abrir el archivo %s.\n", archivo);
        return;
    }

    for (int i = 0; i < numZonas; i++) {
        fread(&zonas[i], sizeof(Zona), 1, file);
    }

    fclose(file);
}

void ingresarDatosContaminacion(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        printf("Ingrese datos de contaminación para la zona %s:\n", zonas[i].nombre);
        fflush(stdin); // Limpia el buffer antes de leer datos
        printf("CO2 (ppm): ");
        scanf("%f", &zonas[i].actual[0]);
        fflush(stdin);
        printf("SO2 (ppm): ");
        scanf("%f", &zonas[i].actual[1]);
        fflush(stdin);
        printf("NO2 (ppm): ");
        scanf("%f", &zonas[i].actual[2]);
        fflush(stdin);
        printf("PM2.5 (µg/m³): ");
        scanf("%f", &zonas[i].actual[3]);
        fflush(stdin);
    }
}

void monitorearActual(Zona zonas[], int numZonas) {
    const float umbrales[4] = {400.0, 0.075, 0.053, 35.0}; // Umbrales para CO2, SO2, NO2, PM2.5 (según OMS)
    for (int i = 0; i < numZonas; i++) {
        printf("Zona: %s\n", zonas[i].nombre);
        fflush(stdin); // Limpia el buffer antes de imprimir datos
        printf("Niveles actuales de contaminación:\n");
        printf("CO2: %.2f ppm\n", zonas[i].actual[0]);
        printf("SO2: %.2f ppm\n", zonas[i].actual[1]);
        printf("NO2: %.2f ppm\n", zonas[i].actual[2]);
        printf("PM2.5: %.2f µg/m³\n", zonas[i].actual[3]);

        // Mensajes de alerta
        for (int j = 0; j < 4; j++) {
            if (zonas[i].actual[j] > umbrales[j]) {
                printf("¡ALERTA! El nivel de %s excede el límite aceptable.\n",
                       (j == 0 ? "CO2" : j == 1 ? "SO2" : j == 2 ? "NO2" : "PM2.5"));
                fflush(stdin);
            }
        }
    }
}

void predecirNiveles(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        zonas[i].prediccion = (zonas[i].contaminantes[29] * 0.4) +
                              (zonas[i].contaminantes[28] * 0.3) +
                              (zonas[i].contaminantes[27] * 0.2) +
                              (zonas[i].contaminantes[26] * 0.1);
        printf("Predicción para zona %s: %.2f\n", zonas[i].nombre, zonas[i].prediccion);
        fflush(stdin);
    }
}

void calcularPromedios(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        float suma = 0;
        for (int j = 0; j < 30; j++) {
            suma += zonas[i].contaminantes[j];
        }
        zonas[i].promedioHistorico = suma / 30;
        printf("Promedio histórico para zona %s: %.2f\n", zonas[i].nombre, zonas[i].promedioHistorico);
        fflush(stdin);
    }
}

void generarReporte(Zona zonas[], int numZonas, const char *archivo) {
    FILE *file = fopen(archivo, "w");
    if (!file) {
        printf("Error al abrir el archivo %s.\n", archivo);
        return;
    }

    fprintf(file, "Reporte de Contaminación:\n");
    for (int i = 0; i < numZonas; i++) {
        fprintf(file, "Zona: %s\n", zonas[i].nombre);
        fprintf(file, "Niveles actuales:\n");
        fprintf(file, "CO2: %.2f ppm\n", zonas[i].actual[0]);
        fprintf(file, "SO2: %.2f ppm\n", zonas[i].actual[1]);
        fprintf(file, "NO2: %.2f ppm\n", zonas[i].actual[2]);
        fprintf(file, "PM2.5: %.2f µg/m³\n", zonas[i].actual[3]);
        fprintf(file, "Promedio histórico: %.2f\n", zonas[i].promedioHistorico);
        fprintf(file, "Predicción: %.2f\n\n", zonas[i].prediccion);
        fflush(stdin);
    }

    fclose(file);
    printf("Reporte generado en %s.\n", archivo);
    fflush(stdin);
}
