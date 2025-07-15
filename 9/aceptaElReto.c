#include <stdio.h>
/*
Reglas
1.Todos distintos
2.Mínimo 3 personas
3.Siempre tiene que haber una Mafalda
4.Si llega Mafalda y no hay gente se espera hasta que haya
5.Si llega alguien y su personaje esta ocupado deja pasar a los demás hasta que el suyo se desocupe
*/
int main()
{

    int numPersonas;
    char nombres[15]; // Guarda los nombres de las personas
    int i, j;
    while (1)
    {
        scanf("%d", &numPersonas);
        if (numPersonas == 0)
        {
            break;
        }
        int contador[7] = {0};
        int fotos = 0;    // Contador de fotos realizadas
        int sin_foto = 0; // Personas que se quedaron sin foto

        for (i = 0; i < numPersonas; i++)
        {
            scanf("%s", nombres);
            if (strcmp(nombres, "Mafalda") == 0)
                contador[0]++;
            else if (strcmp(nombres, "Felipe") == 0)
                contador[1]++;
            else if (strcmp(nombres, "Manolito") == 0)
                contador[2]++;
            else if (strcmp(nombres, "Susanita") == 0)
                contador[3]++;
            else if (strcmp(nombres, "Miguelito") == 0)
                contador[4]++;
            else if (strcmp(nombres, "Libertad") == 0)
                contador[5]++;
            else if (strcmp(nombres, "Guille") == 0)
                contador[6]++;

            if (contador[0] > 0)
            {                                 // Verifica si hay Mafalda
                int personajes_distintos = 1; // Incluir a Mafalda siempre
                for (j = 1; j < 7; j++)
                { // Contamos los otros personajes
                    if (contador[j] > 0)
                    {
                        personajes_distintos++; // Para la condicion 2
                    }
                }

                if (personajes_distintos >= 3) // Minimo 3 personas
                {
                    fotos++;       // Incrementamos el contador de fotos
                    contador[0]--; // Restamos una Mafalda
                    // Restamos uno de cada personaje que hay,menos Mafalda
                    for (j = 1; j < 7; j++)
                    {
                        if (contador[j] > 0) // Si hay de ese personaje
                        {
                            contador[j]--; // Restamos uno de ese personaje
                        }
                    }
                }
            }
        }
        for (i = 0; i < 7; i++)
        {
            sin_foto = sin_foto + contador[i];
        }
        // Fotos tomadas y personas que se quedaron sin foto
        printf("%d %d\n", fotos, sin_foto);
    }
    return 0;
}