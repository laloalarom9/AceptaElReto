#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ano;
    int numeroValido = 0;

    while (!numeroValido)
    {
        printf("Introduce un número entre -3000 y 3000, distinto de 0: ");
        if (scanf("%d", &ano) == 1) // Verifica si se lee bien
        {
            // Verifica que el número esté en el rango 
            if (ano >= -3000 && ano <= 3000 && ano != 0)
            {
                numeroValido = 1; // Salir del bucle 

                // Si es positivo
                if (ano > 0)
                {
                    ano = ano - 1;
                }

                printf("En un calendario que incluye el 0, el año es: %d\n", ano);
            }
            else
            {
                printf("Número fuera del rango permitido. Intenta de nuevo.\n");
            }
        }
        else
        {
            // Si scanf falla, limpia el buffer 
            printf("Error. Por favor, introduce un número válido.\n");
            while (getchar() != '\n'); // Limpia buffer
        }
    }
    return 0;
}
