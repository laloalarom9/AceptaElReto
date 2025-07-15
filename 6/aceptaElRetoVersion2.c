#include <stdio.h> //printf
#include <string.h>//Para el memset

int ObtenerMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int NCanciones, duracionMx, i, j, k;        // NCanciones= Número de canciones duracionMx =Capacidad de una de las dos caras de la cinta
    int duracion[30], puntuacion[30];           // Duración y puntuación de cada canción
    int puntuacionAnterior[1000 + 1][1000 + 1]; // Actualizacion de puntuaciones
    int puntuacionNueva[1000 + 1][1000 + 1];

    while (1)
    {
        scanf("%d", &NCanciones);
        if (NCanciones == 0)break;//si es 0 se acaba el programa
            
        // Leer la capacidad que le quiere dar el usuario a cada cinta
        scanf("%d", &duracionMx);

        for (i = 0; i < NCanciones; i++)
        {
            scanf("%d %d", &duracion[i], &puntuacion[i]); // duración y puntuación de cada cancion
        }
        memset(puntuacionAnterior, 0, sizeof(puntuacionAnterior)); // Llena todo con 0

        for (i = 1; i <= NCanciones; i++)
        {
            // Copiar la tabla anterior al estado actual
            for (j = 0; j <= duracionMx; j++)
            {
                for (k = 0; k <= duracionMx; k++)
                {
                    puntuacionNueva[j][k] = puntuacionAnterior[j][k];
                }
            }

            for (j = 0; j <= duracionMx; j++)
            {
                for (k = 0; k <= duracionMx; k++)
                {
                    // No usar la canción actual
                    puntuacionNueva[j][k] = puntuacionAnterior[j][k];

                    // Usar la canción actual en la primera cara si es que puede entra
                    if (j >= duracion[i - 1])puntuacionNueva[j][k] = ObtenerMax(puntuacionNueva[j][k], puntuacionAnterior[j - duracion[i - 1]][k] + puntuacion[i - 1]);

                    // Usar la canción actual en la segunda cara si es que puede entra
                    if (k >= duracion[i - 1])puntuacionNueva[j][k] = ObtenerMax(puntuacionNueva[j][k], puntuacionAnterior[j][k - duracion[i - 1]] + puntuacion[i - 1]);
                }
            }
            // Actualizar puntuacionAnterior
            for (j = 0; j <= duracionMx; j++)
            {
                for (k = 0; k <= duracionMx; k++)
                {
                    puntuacionAnterior[j][k] = puntuacionNueva[j][k];
                }
            }
        }

        int max_puntuacion = 0;               
        for (i = 0; i <= duracionMx; i++) 
        {
            for ( j = 0; j <= duracionMx; j++)
            {
                
                if (puntuacionAnterior[i][j] > max_puntuacion)max_puntuacion = puntuacionAnterior[i][j];// Comparar para obtener la máxima puntuación
            }
        }
        printf("%d\n", max_puntuacion);
    }
    return 0;
}
