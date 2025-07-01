#include "gestion_contaminacion.h"

// Función para inicializar las zonas y crear el archivo .dat
void inicializarZonas() {
    Zona zonas[MAX_ZONAS] = {
        {"Zona Centro", {}, 0},
        {"Zona Norte", {}, 0},
        {"Zona Sur", {}, 0},
        {"Zona Este", {}, 0},
        {"Zona Oeste", {}, 0}
    };
    FILE *file = fopen("zonas.dat", "wb");
    int numZonas = MAX_ZONAS;
    fwrite(&numZonas, sizeof(int), 1, file);
    fwrite(zonas, sizeof(Zona), numZonas, file);
    fclose(file);
    printf("Archivo 'zonas.dat' creado con zonas pre-cargadas.\n");
}

int main() {
    inicializarZonas();
    return 0;
}
