#include <stdio.h>
#include <stdlib.h>

#define VELOCIDAD_MINIMA 0.1

int cantidadSemaforos;         // Cantidad de semáforos en el trayecto
int limiteVelocidad;           // Límite de velocidad máxima permitido
double distanciaRecorrido;     // Distancia total del recorrido
int distanciasAcumuladas[100]; // Distancias acumuladas hasta cada semáforo
int ciclosSemaforo[100];       // Ciclo completo de cada semáforo
int duracionRojo[100];         // Duración de la luz roja de cada semáforo
int duracionVerde[100];        // Duración de la luz verde de cada semáforo

// Verifica si el semáforo está en luz roja en el momento de llegada
int semaforoEnRojo(int tiempoLlegada)
{
    double tiempoActual;
    int ciclosCompletos, i;
    for (i = 0; i < cantidadSemaforos - 1; i++)
    {
        // Calcula el tiempo relativo al semáforo actual
        tiempoActual = (tiempoLlegada * distanciasAcumuladas[i]) / distanciaRecorrido;

        // Calcula el tiempo dentro del ciclo actual del semáforo
        double tiempoDentroDelCiclo = fmod(tiempoActual, ciclosSemaforo[i]);

        // Verifica si el tiempo dentro del ciclo cae en la duración de la luz roja
        if (tiempoDentroDelCiclo >= 0.01 && tiempoDentroDelCiclo < (duracionRojo[i] - 0.01))
        {
            return 0; // El semáforo está en rojo
        }
    }

    return 1; // El semáforo está en verde
}

// Procesa un caso, captura datos y calcula el tiempo de espera
int procesarTrayecto()
{
    int i, entradaRojo, entradaVerde, distancia, semaforoSinVerde = 0;

    // Captura los datos de entrada
    if (scanf("%d %d", &cantidadSemaforos, &limiteVelocidad) != 2)
        return 0; // Lee el número de semáforos y la velocidad máxima permitida
    if (cantidadSemaforos == 0 && limiteVelocidad == 0)
        return 0; // Fin de los casos de prueba

    distanciaRecorrido = 0; // Inicializa la distancia recorrida

    // Captura datos de cada semáforo
    for (i = 0; i < cantidadSemaforos - 1; i++)
    {
        scanf("%d %d %d", &distancia, &entradaRojo, &entradaVerde); // Lee la distancia, el tiempo en rojo y el tiempo en verde
        if (entradaVerde == 0)
            semaforoSinVerde = 1; // Si el tiempo en verde es 0, el semáforo no tiene verde

        distanciaRecorrido += distancia;                        // Suma la distancia recorrida
        distanciasAcumuladas[i] = (int)distanciaRecorrido;      // Guarda la distancia acumulada
        duracionRojo[i] = entradaRojo;                          // Guarda el tiempo en rojo
        duracionVerde[i] = entradaVerde;                        // Guarda el tiempo en verde
        ciclosSemaforo[i] = duracionRojo[i] + duracionVerde[i]; // Guarda el ciclo completo del semáforo
    }

    // Captura datos del último semáforo
    scanf("%d %d %d", &distancia, &entradaRojo, &entradaVerde);
    if (entradaVerde == 0)
        semaforoSinVerde = 1; // Si el tiempo en verde es 0, el semáforo no tiene verde

    distanciaRecorrido += distancia;                                       // Suma la distancia recorrida
    distanciasAcumuladas[cantidadSemaforos - 1] = (int)distanciaRecorrido; // Guarda la distancia acumulada
    duracionRojo[cantidadSemaforos - 1] = entradaRojo;                     // Guarda el tiempo en rojo
    duracionVerde[cantidadSemaforos - 1] = entradaVerde;                   // Guarda el tiempo en verde
    ciclosSemaforo[cantidadSemaforos - 1] = duracionRojo[cantidadSemaforos - 1] + duracionVerde[cantidadSemaforos - 1];

    if (semaforoSinVerde)
    {
        printf("IMPOSIBLE\n"); // Si algún semáforo no tiene verde, es imposible recorrer la avenida
        return 1;
    }

    double velocidadCalculada;
    int ciclosUltimoSemaforo = (int)(distanciaRecorrido / limiteVelocidad) / ciclosSemaforo[cantidadSemaforos - 1];// Calcula los ciclos completos del último semáforo
    double tiempoTotal = distanciaRecorrido / limiteVelocidad;// Calcula el tiempo total de recorrido
    int cicloActualUltimoSemaforo = ciclosUltimoSemaforo * ciclosSemaforo[cantidadSemaforos - 1];// Calcula el ciclo actual del último semáforo

    if (tiempoTotal != cicloActualUltimoSemaforo)// Verifica si el tiempo total no cae en un ciclo completo del último semáforo
    {
        double tiempoRojoUltimo = duracionRojo[cantidadSemaforos - 1];

        // Verifica si el tiempo total cae en la duración de la luz roja del último semáforo
        if (tiempoTotal < tiempoRojoUltimo)
        {
            velocidadCalculada = distanciaRecorrido / (cicloActualUltimoSemaforo + tiempoRojoUltimo);

            if (velocidadCalculada < VELOCIDAD_MINIMA)// Verifica si la velocidad calculada es menor a la mínima
            {
                printf("IMPOSIBLE\n");
                return 1;
            }

            if (semaforoEnRojo(tiempoRojoUltimo))// Verifica si el semáforo está en rojo
            {
                printf("%d\n", (int)tiempoRojoUltimo);
                return 1;
            }
        }

        ciclosUltimoSemaforo++;// Ajusta los ciclos completos del último semáforo
    }

  velocidadCalculada = 1;

while (velocidadCalculada >= VELOCIDAD_MINIMA) {// Probar velocidades desde la máxima hacia abajo
    int tiempoCicloActual = ciclosSemaforo[cantidadSemaforos - 1] * ciclosUltimoSemaforo;// Calcula el tiempo del ciclo actual
int tiempoCicloConRojo = tiempoCicloActual + duracionRojo[cantidadSemaforos - 1];// Calcula el tiempo del ciclo actual con luz roja

    // Calcula la velocidad para el ciclo actual
    velocidadCalculada = distanciaRecorrido / tiempoCicloActual;
    if (velocidadCalculada < VELOCIDAD_MINIMA) {
        break;
    }

    // Verifica si el semáforo está en rojo para el ciclo actual
    if (semaforoEnRojo(tiempoCicloActual)) {
        printf("%d\n", tiempoCicloActual);
        return 1;
    }

    // Calcula la velocidad para el ciclo actual considerando la duración de la luz roja
    velocidadCalculada = distanciaRecorrido / tiempoCicloConRojo;
    if (velocidadCalculada < VELOCIDAD_MINIMA) {
        break;
    }

    // Verifica si el semáforo está en rojo considerando la duración de la luz roja
    if (semaforoEnRojo(tiempoCicloConRojo)) {
        printf("%d\n", tiempoCicloConRojo);
        return 1;
    }

    ciclosUltimoSemaforo++;
}


    printf("IMPOSIBLE\n");
    return 1;
}

int main()
{
    while (procesarTrayecto())// Procesa cada caso de prueba
    {
    }
    return 0;
}