#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    float contaminantes[30]; // Últimos 30 días de contaminantes generales (promedio diario)
    float contaminantesEspecificos[4][30]; // Históricos específicos para CO2, SO2, NO2, PM2.5
    float actual[4]; // Niveles actuales de CO2, SO2, NO2, PM2.5
    float promedioHistorico; // Promedio histórico general
    float prediccion; // Predicción para las próximas 24 horas
} Zona;

void inicializarDatos(const char *archivo) {
    FILE *file = fopen(archivo, "wb");
    if (!file) {
        printf("Error al crear el archivo %s.\n", archivo);
        return;
    }

    Zona zonas[5] = {
        // Zonas con datos iniciales (como en ejemplos anteriores)
        // Agrega aquí todas las zonas
    };

    for (int i = 0; i < 5; i++) {
        fwrite(&zonas[i], sizeof(Zona), 1, file);
        fflush(stdin); // Limpia el buffer después de escribir
    }

    fclose(file);
    printf("Archivo %s creado exitosamente con datos iniciales.\n", archivo);
    fflush(stdin);
}

int main() {
    inicializarDatos("datos_historicos.dat");
    fflush(stdin); // Limpia el buffer después de ejecutar la función principal
    return 0;
}
