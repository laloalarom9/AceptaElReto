#include <stdio.h> //para printf y scanf

int main()
{
    int hectometros = 3;
    int i, j;
    // si es 0 se acaba el programa
    while (1)
    {
        // Leer el número de hectómetros
        scanf("%d", &hectometros);
        if (hectometros == 0)
            break; // Si es 0, terminamos

        int tiempo[hectometros];
        for (i = 0; i < hectometros; i++)
        {
            scanf("%d", &tiempo[i]);
        }

        int mejorTiempoKilometro = 0;
        int tiempokilometro = 0;
        int inicioKilometro = 0;

        // Sumatoria del primer kilometro
        for (i = 0; i < 10; i++)
        {
            mejorTiempoKilometro += tiempo[i];
        }

        for (i = 1; i <= hectometros - 10; i++)
        {
            tiempokilometro = 0;
            // Sumar el tiempo del kilómetro actual
            for (j = i; j < i + 10; j++)
            {
                tiempokilometro += tiempo[j];
            }
            // actualizar el mejor tiempo, si es igual, el desempate sería con los kilometros mayores porque importa más un record con más cansacio
            if (tiempokilometro < mejorTiempoKilometro ||
                (tiempokilometro == mejorTiempoKilometro && i > inicioKilometro))
            {
                mejorTiempoKilometro = tiempokilometro;
                inicioKilometro = i;
                
            }
        }
        printf("%d-%d %d:%02d\n", inicioKilometro * 100, (inicioKilometro + 10) * 100, mejorTiempoKilometro / 60, mejorTiempoKilometro % 60);
        // Salidas
    }
    return 0;
}