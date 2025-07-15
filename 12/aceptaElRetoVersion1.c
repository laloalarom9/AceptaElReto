#include <stdio.h>

int main() {
    int nSemaforos, velocidadMaxima;
    int i,v;
    while (1) {
        // Leer el número de semáforos y la velocidad máxima
        scanf("%d %d", &nSemaforos, &velocidadMaxima);
        if (nSemaforos == 0 && velocidadMaxima == 0) break;  // Fin de los casos de prueba

        int distancias[nSemaforos], tSemaforoRojo[nSemaforos], tSemaforoVerde[nSemaforos];

        // Leer la información de los semáforos
        for (i = 0; i < nSemaforos; i++) {
            scanf("%d %d %d", &distancias[i], &tSemaforoRojo[i], &tSemaforoVerde[i]);
        }

        int velocidadOptima = -1;
        int tiempoOptimo = -1;

        // Probar velocidades desde la máxima hacia abajo
        for ( v = velocidadMaxima; v >= 1; v--) {
            int posible = 1;
            int tiempoTotal = 0;

            // Verificar si esta velocidad es válida
            for ( i = 0; i < nSemaforos; i++) {
                // Tiempo total para llegar al semáforo
                int tiempo = distancias[i] / v;
                tiempoTotal += tiempo;  // Acumular el tiempo total de los semáforos

                // Ciclo del semáforo
                int ciclo = tSemaforoRojo[i] + tSemaforoVerde[i];

                // Tiempo en el ciclo actual
                int tiempoEnCiclo = tiempoTotal % ciclo;

                // Verificar si el semáforo está en rojo
                if (tiempoEnCiclo < tSemaforoRojo[i]) {
                    if (tiempoEnCiclo == 0) {
                        // Si está justo cambiando a verde, ajustar velocidad con +0.1
                        posible = 1;
                    } else {
                        posible = 0;
                        break;
                    }
                } else if (tiempoEnCiclo == tSemaforoRojo[i]) {
                    // Si está justo antes de cambiar a rojo, ajustar velocidad con -0.1
                    posible = 1;
                }
                else if(tiempoEnCiclo > tSemaforoRojo[i]&&tiempoEnCiclo < tSemaforoRojo[i]+tSemaforoVerde[i]){
                    posible = 1;
                }
                else{
                    posible = 0;
                    break;
                }
            }

            // Si es posible con esta velocidad, guardar la más alta encontrada
            if (posible) {
                velocidadOptima = v;
                if (tiempoOptimo == -1 || tiempoTotal < tiempoOptimo) {
                    tiempoOptimo = tiempoTotal;
                }
                break;
            }
        }

        // Imprimir el resultado
        if (tiempoOptimo != -1) {
            printf("%d\n", tiempoOptimo);  // Imprime el tiempo total
        } else {
            printf("IMPOSIBLE\n");
        }
    }

    return 0;
}
