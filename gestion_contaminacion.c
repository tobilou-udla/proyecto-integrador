#include "gestion_contaminacion.h"

int cargarZonas(Zona zonas[]) {
    FILE *file = fopen("zonas.dat", "rb");
    if (!file) {
        return 0; // No se pudo abrir el archivo
    }
    int numZonas;
    fread(&numZonas, sizeof(int), 1, file);
    fread(zonas, sizeof(Zona), numZonas, file);
    fclose(file);
    return numZonas;
}

void guardarZonas(Zona zonas[], int numZonas) {
    FILE *file = fopen("zonas.dat", "wb");
    fwrite(&numZonas, sizeof(int), 1, file);
    fwrite(zonas, sizeof(Zona), numZonas, file);
    fclose(file);
}

void registrarMedicion(Zona zonas[], int numZonas) {
    char nombreZona[50];
    printf("Ingrese el nombre de la zona: ");
    scanf("%s", nombreZona);

    for (int i = 0; i < numZonas; i++) {
        if (strcmp(zonas[i].nombre, nombreZona) == 0) {
            if (zonas[i].numMediciones >= MAX_MEDICIONES) {
                printf("No se pueden registrar más mediciones en esta zona.\n");
                return;
            }
            Medicion nuevaMedicion;
            printf("Ingrese los datos de la medición (PM2.5, NO2, SO2, CO, temperatura, velocidad del viento, humedad):\n");
            scanf("%f %f %f %f %f %f %f", &nuevaMedicion.pm25, &nuevaMedicion.no2, &nuevaMedicion.so2, &nuevaMedicion.co, &nuevaMedicion.temperatura, &nuevaMedicion.velocidadViento, &nuevaMedicion.humedad);
            printf("Ingrese la fecha y hora (YYYY-MM-DD HH:MM): ");
            scanf("%s", nuevaMedicion.timestamp);
            zonas[i].mediciones[zonas[i].numMediciones++] = nuevaMedicion;
            printf("Medición registrada correctamente.\n");
            return;
        }
    }

    printf("Zona no encontrada. Por favor, intente nuevamente.\n");
}

void mostrarNivelesActuales(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        if (zonas[i].numMediciones > 0) {
            Medicion actual = zonas[i].mediciones[zonas[i].numMediciones - 1];
            printf("Zona: %s\n", zonas[i].nombre);
            printf("PM2.5: %.2f, NO2: %.2f, SO2: %.2f, CO: %.2f\n", actual.pm25, actual.no2, actual.so2, actual.co);
        }
    }
}

void mostrarPrediccion(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        if (zonas[i].numMediciones > 2) {
            float promedioPM25 = 0;
            for (int j = zonas[i].numMediciones - 3; j < zonas[i].numMediciones; j++) {
                promedioPM25 += zonas[i].mediciones[j].pm25;
            }
            promedioPM25 /= 3;
            printf("Predicción PM2.5 para zona %s: %.2f\n", zonas[i].nombre, promedioPM25);
        }
    }
}

void emitirAlertas(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        if (zonas[i].numMediciones > 0) {
            Medicion actual = zonas[i].mediciones[zonas[i].numMediciones - 1];
            if (actual.pm25 > 15.0) {
                printf("ALERTA: Zona %s excede el límite de PM2.5\n", zonas[i].nombre);
            }
        }
    }
}

void mostrarRecomendaciones(Zona zonas[], int numZonas) {
    for (int i = 0; i < numZonas; i++) {
        if (zonas[i].numMediciones > 0) {
            Medicion actual = zonas[i].mediciones[zonas[i].numMediciones - 1];
            if (actual.pm25 > 15.0) {
                printf("Zona %s: Reduzca el tráfico vehicular y evite actividades al aire libre.\n", zonas[i].nombre);
            }
        }
    }
}

void exportarDatos(Zona zonas[], int numZonas) {
    FILE *file = fopen("reporte.txt", "w");
    for (int i = 0; i < numZonas; i++) {
        fprintf(file, "Zona: %s\n", zonas[i].nombre);
        for (int j = 0; j < zonas[i].numMediciones; j++) {
            Medicion m = zonas[i].mediciones[j];
            fprintf(file, "Fecha: %s, PM2.5: %.2f, NO2: %.2f, SO2: %.2f, CO: %.2f\n", m.timestamp, m.pm25, m.no2, m.so2, m.co);
        }
    }
    fclose(file);
    printf("Datos exportados correctamente a reporte.txt\n");
}
