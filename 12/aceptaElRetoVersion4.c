#include <stdio.h>
#include <math.h>  // Incluir para usar ceil()

int main() {
    int nSemaforos, velocidadMaxima;
    int i, v;
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
        float tiempoTotalDecimal = 0;  // Tiempo total con decimales
        int tiempoOptimo = -1;  // Tiempo óptimo sin decimales

        // Probar velocidades desde la máxima hacia abajo
        for (v = velocidadMaxima; v >= 1; v--) {
            int posible = 1;
            int tiempoTotalInt = 0;  // Parte entera del tiempo total

            // Verificar si esta velocidad es válida
            for (i = 0; i < nSemaforos; i++) {
                // Tiempo total para llegar al semáforo (entero y decimal)
                int tiempoInt = distancias[i] / v;  // Parte entera
                float tiempoDec = (float)distancias[i] / v - tiempoInt;  // Parte decimal
                tiempoTotalInt += tiempoInt;  // Acumulamos la parte entera
                tiempoTotalDecimal += tiempoDec;  // Acumulamos la parte decimal

                // Si la parte decimal supera 1, la agregamos a la parte entera
                if (tiempoTotalDecimal >= 1) {
                    tiempoTotalInt += (int)tiempoTotalDecimal;
                    tiempoTotalDecimal -= (int)tiempoTotalDecimal;  // Mantener solo la parte decimal
                }

                // Verificar el ciclo del semáforo
                int ciclo = tSemaforoRojo[i] + tSemaforoVerde[i];
                int tiempoEnCiclo = (tiempoTotalInt + (int)tiempoTotalDecimal) % ciclo;

                // Verificar semáforo en rojo
                if (tiempoEnCiclo < tSemaforoRojo[i]) {
                    posible = 0;
                    break;
                }
            }

            if (posible) {
                velocidadOptima = v;
                if (tiempoOptimo == -1 || tiempoTotalInt + tiempoTotalDecimal < tiempoOptimo) {
                    tiempoOptimo = tiempoTotalInt + tiempoTotalDecimal;
                }
                break;
            }
        }

        // Redondear el tiempo óptimo utilizando ceil
        if (tiempoOptimo != -1) {
            printf("%d\n", (int)ceil(tiempoOptimo));  // Imprimir el tiempo redondeado
        } else {
            printf("IMPOSIBLE\n");
        }
    }

    return 0;
}
