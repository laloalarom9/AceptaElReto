#include <stdio.h>  //printf y scanf
#include <stdlib.h> //asignación de memoria
#include <string.h> //Para usar strlen

#define MOD 1000000007    // para evitar que los resultados se vuelvan muy grandes
#define MAX_LONGITUD 1001 // longitud máxima del mensaje cifrado
#define MAX_SIMBOLOS 10   // MAX_SYMBOLS: La cantidad máxima de símbolos ( 0 al 9).

int simbolos[MAX_LONGITUD][MAX_SIMBOLOS]; // Matriz: cada posición puede tener hasta 10 símbolos
int CadenaValida[MAX_LONGITUD];           // cadena válida
int contador = 1;

// Función para añadir nuevos símbolos a matriz
void insertar(const char *simbolo)
{
    int posicionActual = 0; // Comenzamos desde el primer lugar
    while (*simbolo)
    {                                             // Mientras haya caracteres en el símbolo
        int index = *simbolo - '0';               // Convertir char a numero, se resta el codigo Ascii
                                                  // Si en la posición actual y el índice son 0
        if (simbolos[posicionActual][index] == 0) // Si es 0, aun no hay un simbolo
        {
            simbolos[posicionActual][index] = contador++; //// Crea lugar si no existe
        }
        posicionActual = simbolos[posicionActual][index]; // Moverse al siguiente lugar
        simbolo++;                                        // Pasar al siguiente carácter de simbolo
    }
    CadenaValida[posicionActual] = 1; // Marca el final de una cadena válida
}

int main()
{
    int n; // número de símbolos
    int i; // bucles
    int j; // bucles

    while (1)
    {                             // Bucle infinito
        if (scanf("%d", &n) != 1) // Leer el número de símbolos y ver si el scanf fue exitoso
        {
            break;
        }
        if (n == 0)
        {
            break; // Terminar si el número es 0
        }
        // Reinicia la matriz
        for (i = 0; i < MAX_LONGITUD; i++)
        { // Los for recorren la matriz para acceder a cada simbolo
            for (j = 0; j < MAX_SIMBOLOS; j++)
            {
                simbolos[i][j] = 0; // Cada elemento de la matriz a 0
            }
        }

        for (i = 0; i < MAX_LONGITUD; i++) // Array cadena
        {
            CadenaValida[i] = 0; // Cada elemento del arreglo a 0
        }

        contador = 1; // Reinicia el contador

        for (i = 0; i < n; ++i)
        {                                  // Hacer esto n veces(lo especifica el usuario---n= número de símbolos)
            char simbolo[10];              // Simbolo 0 a 9
            if (scanf("%s", simbolo) != 1) // Lee simbolo y si no es 1, no es exitoso
            {
                printf("Error al leer el símbolo\n");
                return 1; // ERROR
            }
            insertar(simbolo); // Agregar el símbolo en la matriz
        }

        char mensaje[MAX_LONGITUD];               // mensaje cifrado
        if (scanf("%s", mensaje) != 1)            // Verificar lectura
        {                                         // Leer el mensaje cifrado y comprobar si la lectura fue exitosa
            printf("Error al leer el mensaje\n"); // ERROR
            return 1;
        }

        long long posibilidades[MAX_LONGITUD] = {0}; // contar posibilidades
        posibilidades[0] = 1;                        // No hay nada, establecemos posición a 1

        // Procesar el mensaje
        int longitud = strlen(mensaje); // Obtener longitud del mensaje
        for (i = 0; i < longitud; ++i)  // Recorremos mensaje caracter por caracter
        {
            if (mensaje[i] == '0')
            {
                posibilidades[i + 1] = posibilidades[i]; // Se omite el 0
                continue;                                // continuar con el siguiente carácter
            }
            int indiceActual = 0;          // Reiniciar primer lugar
            for (j = i; j < longitud; ++j) // Desde el carácter actual hasta el final
            {
                int pos = mensaje[j] - '0'; // Convertir el carácter a número
                // Si en la posición actual y el número convertido no hay nada (es 0)
                if (simbolos[indiceActual][pos] == 0)
                {
                    break; // Si no existe el código, salir del bucle
                }
                // Si hay una cadena válida
                if (CadenaValida[simbolos[indiceActual][pos]])
                {
                    // Actualiza las posibilidades
                    posibilidades[j + 1] = (posibilidades[j + 1] + posibilidades[i]) % MOD;
                }
                indiceActual = simbolos[indiceActual][pos]; // al siguiente lugar del array
            }
        }

        printf("%lld\n", posibilidades[longitud]); // número de formas de decodificar
    }

    return 0;
}
