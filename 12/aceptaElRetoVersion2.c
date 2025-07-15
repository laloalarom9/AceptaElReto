#include <stdio.h>
#include <stdlib.h>

#define MAX_SEMAFOROS 100
#define MIN_VELOCIDAD 0.1

typedef struct {
    int distanciaAcumulada;  // Distancia total acumulada hasta este semáforo
    int duracionCiclo;       // Duración total del ciclo (rojo + verde)
    int tiempoRojo;          // Duración en segundos que el semáforo está en rojo
    int tiempoVerde;         // Duración en segundos que el semáforo está en verde
} Semaforo;

Semaforo avenida[MAX_SEMAFOROS];
int nSemaforos;
double disTotal;
int velocidadMaxima;

/* Verifica si es posible pasar por todos los semáforos con un tiempo dado */
int verificarRojo(int tiempoLlegadaUltimo) {
    double tiempoActual;
    int ciclosCompletos, i;

    for (i = 0; i < nSemaforos - 1; i++) {
        // Calcular el tiempo que se tarda en llegar a este semáforo
        tiempoActual = tiempoLlegadaUltimo * (avenida[i].distanciaAcumulada / disTotal);

        // Calcular los ciclos completos que el semáforo ha completado
        ciclosCompletos = (int)(tiempoActual / avenida[i].duracionCiclo);

        // Ajustar el tiempo dentro del ciclo actual del semáforo
        tiempoActual -= ciclosCompletos * avenida[i].duracionCiclo;

        // Verificar si el semáforo está en rojo cuando se llega
        if (tiempoActual < (avenida[i].tiempoRojo - 0.01) && tiempoActual > 0.01) {
            return 0;  // No es posible pasar
        }
    }
    return 1;  // Es posible pasar por todos los semáforos
}

/* Procesa un caso de prueba */
int casoUsuario() {
    int i, tiempoRojo, tiempoVerde, distancia, semaforoSinVerde = 0;

    // Leer el número de semáforos y la velocidad máxima
    if (scanf("%d %d", &nSemaforos, &velocidadMaxima) != 2) {
        return 0;
    }
    if (nSemaforos == 0 && velocidadMaxima == 0) {
        return 0;
    }

    disTotal = 0;

    // Leer la información de cada semáforo
    for (i = 0; i < nSemaforos - 1; i++) {
        scanf("%d %d %d", &distancia, &tiempoRojo, &tiempoVerde);
        if (tiempoVerde == 0) {
            semaforoSinVerde = 1;
        }
        disTotal += distancia;
        avenida[i].distanciaAcumulada = (int)disTotal;
        avenida[i].tiempoRojo = tiempoRojo;
        avenida[i].tiempoVerde = tiempoVerde;
        avenida[i].duracionCiclo = tiempoRojo + tiempoVerde;
    }
    // Último semáforo
    scanf("%d %d %d", &distancia, &tiempoRojo, &tiempoVerde);
    if (tiempoVerde == 0) {
        semaforoSinVerde = 1;
    }
    disTotal += distancia;
    Semaforo ultimoSemaforo = { (int)disTotal, tiempoRojo + tiempoVerde, tiempoRojo, tiempoVerde };

    if (semaforoSinVerde) {
        // Si algún semáforo nunca se pone verde, es imposible recorrer la avenida
        printf("IMPOSIBLE\n");
        return 1;
    }

    double velocidadActual;
    int ciclosUltimoSemaforo = (int)(disTotal / velocidadMaxima) / ultimoSemaforo.duracionCiclo;

    if ((disTotal / velocidadMaxima) != ciclosUltimoSemaforo * ultimoSemaforo.duracionCiclo) {
        if ((disTotal / velocidadMaxima) < ultimoSemaforo.tiempoRojo) {
            velocidadActual = disTotal / (ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo + ultimoSemaforo.tiempoRojo);
            if (velocidadActual < MIN_VELOCIDAD) {
                printf("IMPOSIBLE\n");
                return 1;
            }
            if (verificarRojo(ultimoSemaforo.tiempoRojo)) {
                printf("%d\n", ultimoSemaforo.tiempoRojo);
                return 1;
            }
        }
        ciclosUltimoSemaforo++;
    }

    velocidadActual = 1;
    while (velocidadActual >= MIN_VELOCIDAD) {
        velocidadActual = disTotal / (ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo);
        if (velocidadActual < MIN_VELOCIDAD) {
            break;
        }
        if (verificarRojo(ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo)) {
            printf("%d\n", ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo);
            return 1;
        }
        velocidadActual = disTotal / (ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo + ultimoSemaforo.tiempoRojo);
        if (velocidadActual < MIN_VELOCIDAD) {
            break;
        }
        if (verificarRojo(ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo + ultimoSemaforo.tiempoRojo)) {
            printf("%d\n", ultimoSemaforo.duracionCiclo * ciclosUltimoSemaforo + ultimoSemaforo.tiempoRojo);
            return 1;
        }
        ciclosUltimoSemaforo++;
    }

    printf("IMPOSIBLE\n");
    return 1;
}

int main() {
    while (casoUsuario()) {
        // Procesar cada caso
    }
    return 0;
}