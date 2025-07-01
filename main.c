#include "gestion_contaminacion.h"

int main() {
    Zona zonas[MAX_ZONAS];
    int numZonas = cargarZonas(zonas);
    
    if (numZonas == 0) {
        printf("No se encontraron datos iniciales. Iniciando con datos vacíos.\n");
    }

    // Menú principal
    int opcion;
    do {
        printf("\n--- Sistema Integral de Gestión y Predicción de Contaminación del Aire ---\n");
        printf("1. Registrar nueva medición\n");
        printf("2. Mostrar niveles actuales\n");
        printf("3. Mostrar predicción de contaminación\n");
        printf("4. Emitir alertas preventivas\n");
        printf("5. Mostrar recomendaciones\n");
        printf("6. Exportar datos a archivo\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarMedicion(zonas, numZonas);
                break;
            case 2:
                mostrarNivelesActuales(zonas, numZonas);
                break;
            case 3:
                mostrarPrediccion(zonas, numZonas);
                break;
            case 4:
                emitirAlertas(zonas, numZonas);
                break;
            case 5:
                mostrarRecomendaciones(zonas, numZonas);
                break;
            case 6:
                exportarDatos(zonas, numZonas);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente nuevamente.\n");
                break;
        }
    } while (opcion != 7);

    guardarZonas(zonas, numZonas);
    return 0;
}
