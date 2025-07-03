#include <stdio.h>
#include <string.h>
#include "gestion_contaminacion.h"

int main() {
    Zona zonas[5];
    cargarDatosHistoricos("datos_historicos.dat", zonas, 5);

    int opcion;
    do {
        printf("\nSistema Integral de Gestión y Predicción de Contaminación del Aire\n");
        printf("1. Ingresar datos de contaminación actual\n");
        printf("2. Monitorear contaminación actual\n");
        printf("3. Predicción de niveles futuros\n");
        printf("4. Calcular promedios históricos\n");
        printf("5. Generar reporte\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        fflush(stdin); // Limpia el buffer antes de leer la entrada
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarDatosContaminacion(zonas, 5);
                break;
            case 2:
                monitorearActual(zonas, 5);
                break;
            case 3:
                predecirNiveles(zonas, 5);
                break;
            case 4:
                calcularPromedios(zonas, 5);
                break;
            case 5:
                generarReporte(zonas, 5, "reportes.txt");
                break;
            case 6:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
