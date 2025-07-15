#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int n,i, puntosDer, puntosIzq; // numero de sonidos
    char palabra[50];
    bool jugadorDerecha; 

    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        puntosIzq = 0;
        puntosDer = 0;
        jugadorDerecha = true;
        
        for (i = 0; i < n; i++)
        {
            scanf("%s", palabra);
            if (strcmp(palabra, "PIC") == 0) // compara y si es 0, son identicos
            {
                jugadorDerecha = !jugadorDerecha;
            }
            else if (strcmp(palabra, "PONG!") == 0)
            {
                if (jugadorDerecha)
                {
                    puntosIzq++;
                }
                else
                {
                    puntosDer++;
                }
            }
        }
        printf("%d %d\n", puntosIzq, puntosDer);
     
    }
    return 0;
}