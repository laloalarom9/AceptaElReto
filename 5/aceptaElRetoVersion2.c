#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n; // número de sonidos
    char palabra[50]; // buffer para los sonidos
    bool jugadorDerecha; // indica la dirección de la bola

    while (1) {
        // Leer el número de sonidos
        scanf("%d", &n);
        if (n == 0) { // si n es 0, termina el programa
            break;
        }

        int puntosIzq = 0; // inicializar puntos para el jugador izquierdo
        int puntosDer = 0; // inicializar puntos para el jugador derecho
        jugadorDerecha = true; // la bola comienza moviéndose hacia la derecha

        for (int i = 0; i < n; i++) {
            // Leer el sonido
            scanf("%s", palabra);
            // Comparar la cadena de sonido
            if (strcmp(palabra, "PIC") == 0) {
                // Si es "PIC", cambia la dirección de la bola
                jugadorDerecha = !jugadorDerecha; 
            } else if (strcmp(palabra, "PONG!") == 0) {
                // Si es "PONG!", se incrementa el puntaje del jugador contrario
                if (jugadorDerecha) {
                    // Si el jugador de la derecha no puede golpear
                    puntosIzq++; // el jugador de la izquierda gana un punto
                } else {
                    // Si el jugador de la izquierda no puede golpear
                    puntosDer++; // el jugador de la derecha gana un punto
                }
                // Cambiar dirección de la bola después de un fallo
                
            }
            // Ignorar "POC" ya que no afecta la puntuación ni la dirección
        }

        // Imprimir el marcador final de la partida
        printf("%d %d\n", puntosIzq, puntosDer);
    }
    return 0;
}
