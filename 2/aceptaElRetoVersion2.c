#include <stdio.h>

int main() {
    int n;  // Número de hectómetros recorridos
    while (scanf("%d", &n), n != 0) {
        int tiempos[n];  // Array para almacenar los tiempos de cada hectómetro
        int i;  // Declarar la variable 'i' antes del bucle
        for (i = 0; i < n; i++) {
            scanf("%d", &tiempos[i]);
        }

        int mejor_inicio = 0;  // Índice del mejor tramo de 1 km
        int mejor_tiempo = 0;  // Tiempo total del mejor tramo
        int tiempo_actual = 0; // Tiempo acumulado del tramo actual

        // Calcular el tiempo del primer kilómetro (0 a 9 hectómetros)
        for (i = 0; i < 10; i++) {
            tiempo_actual += tiempos[i];
        }
        mejor_tiempo = tiempo_actual;

        // Recorrer los siguientes tramos de un kilómetro
        for (i = 10; i < n; i++) {
            tiempo_actual = tiempo_actual - tiempos[i - 10] + tiempos[i];  // Actualizar el tramo
            if (tiempo_actual <= mejor_tiempo) {  // En caso de empate, toma el tramo más reciente
                mejor_tiempo = tiempo_actual;
                mejor_inicio = i - 9;  // Inicio del nuevo mejor tramo
            }
        }

        // Imprimir la salida en el formato requerido
        printf("%d-%d %d:%02d\n", mejor_inicio * 100, (mejor_inicio + 10) * 100, mejor_tiempo / 60, mejor_tiempo % 60);
    }
    return 0;
}
