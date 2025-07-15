#include <stdio.h>// Para usar printf y scanf
#include <stdlib.h>// Para usar qsort

// Estructura para representar los intervalos
typedef struct {
    int inicio;
    int fin;
} Intervalo;

// Función para comparar intervalos por inicio y luego por fin
int compararIntervalos(const void *a, const void *b) {
    Intervalo *i1 = (Intervalo *)a;//punteros a y b apuntan a la estructura Intervalo para acceder a los campos inicio y fin
    Intervalo *i2 = (Intervalo *)b;
    if (i1->inicio != i2->inicio)//si los inicios son diferentes, se ordena por inicio
        return i1->inicio - i2->inicio;
    return i2->fin - i1->fin;//si los inicios son iguales, se ordena por fin
}

int main() {
    int longitudCalle, numRestaurantes,i;

    // Leer casos de prueba hasta el final de la entrada
    while (scanf("%d %d", &longitudCalle, &numRestaurantes) == 2) {
        Intervalo intervalos[numRestaurantes];

        // Leer los datos de los restaurantes
        for ( i = 0; i < numRestaurantes; i++) {
            int posicion, radio;
            scanf("%d %d", &posicion, &radio);
            intervalos[i].inicio = posicion - radio;// Inicio del intervalo
            intervalos[i].fin = posicion + radio;// Fin del intervalo
        }//Formulas dadas en el enunciado

        // Ordenar los intervalos por inicio y luego por fin
        qsort(intervalos, numRestaurantes, sizeof(Intervalo), compararIntervalos);
        /*void qsort(
        void *base,          // Puntero al array que se quiere ordenar
        size_t num,          // Número de elementos en el array
        size_t size,         // Tamaño en bytes de cada elemento
        ,[Función de comparación](compararIntervalos) 
        );
 */

        // Variables para verificar cobertura y contar restaurantes seleccionados
        int puntoCubierto = 0;   // Último punto de la calle que está cubierto
        int maxAlcance = 0;      // Máximo alcance del intervalo actual
        int restaurantesNecesarios = 0; // Contador de intervalos seleccionados
        int i = 0;               // Índice para recorrer los intervalos

        // Procesar para cubrir toda la calle
        while (puntoCubierto < longitudCalle) {
            maxAlcance = puntoCubierto;

            // Extender la cobertura usando los intervalos válidos
            while (i < numRestaurantes && intervalos[i].inicio <= puntoCubierto) {
                if (intervalos[i].fin > maxAlcance)
                    maxAlcance = intervalos[i].fin;
                i++;
            }

            // Si no podemos extender la cobertura, hay puntos descubiertos
            if (maxAlcance == puntoCubierto) {
                printf("-1\n");
                goto siguienteCaso;//goto etiqueta
            }

            // Actualizar el último punto cubierto y contar este restaurante
            puntoCubierto = maxAlcance;
            restaurantesNecesarios++;
        }

        // Calcular el máximo número de restaurantes que se pueden cerrar
        printf("%d\n", numRestaurantes - restaurantesNecesarios);

        siguienteCaso://etiqueta del goto
        continue;
    }

    return 0;
}