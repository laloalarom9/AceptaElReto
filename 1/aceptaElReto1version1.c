#include <stdio.h>

int main() {
    int numCasos;
    int ano;
    int i; // Para el for

    // Leer el número de casos
    if (scanf("%d", &numCasos) != 1) {//si no es 1, no se leyo bien
        printf("Error al leer el número de casos.\n");
        return 1;//Significa error
    }

    for (i = 0; i < numCasos; i++) {
        // Leer cada año
        if (scanf("%d", &ano) != 1) {//si no es 1, no se leyo bien
            printf("Error al leer el año.\n");
            return 1;//ERROR
        }

        // Ajustar el año para año positivo
        if (ano > 0) {
            ano = ano- 1;
        }
        //Respuesta
        printf("%d\n", ano);
    }
    return 0;
}
