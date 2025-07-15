#include <stdio.h>
int puntuacionMax(int duracion, int n, int cancion[][2]) {
    int maxPuntuacion = 0;

   
// Función para calcular la puntuación máxima
int puntuacionMax(int duracionRestante, int n, int cancion[][2]) {
    int maxPuntuacion = 0;

    // Usamos un bucle para iterar sobre todas las combinaciones posibles de canciones
    int totalCombinaciones = 1;
    for (int k = 0; k < n; k++) {
        totalCombinaciones *= 2; // 2^n combinaciones
    }

    // Recorremos cada combinación
    for (int i = 0; i < totalCombinaciones; i++) {
        int duracionActual = 0;
        int puntuacionActual = 0;

        // Comprobamos cada canción para ver si está incluida en la combinación actual
        for (int j = 0; j < n; j++) {
            // Verificamos si la canción j está incluida en la combinación i
            if (i % (2 * (j + 1)) >= (2 * j + 1)) {
                if (duracionActual + cancion[j][0] <= duracionRestante) {
                    duracionActual += cancion[j][0]; // Sumar duración de la canción
                    puntuacionActual += cancion[j][1]; // Sumar puntuación de la canción
                }
            }
        }

        // Actualizamos la puntuación máxima si esta combinación es mejor
        if (puntuacionActual > maxPuntuacion) {
            maxPuntuacion = puntuacionActual;
        }
    }

    return maxPuntuacion; 
}
int main()
{
    int n, i;
    while(1)
    {
        int cancion[30][2];//maximo 30 canciones, 2 caras
        
        int duracion;
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        scanf("%d",&duracion);

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&cancion[i][0],&cancion[i][1]);
        }
        
        int cara1Max=puntuacionMax(duracion,n,cancion);
        int cara2Max = puntuacionMax(duracion, n, cancion);
        printf("%d\n", cara1Max + cara2Max);
        
    }
    return 0;
}