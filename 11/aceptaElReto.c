#include <stdio.h>

int main()
{
    int nCasos;
    int nacimientoA, nacimientoB, muerteA, muerteB, coincidenciaInicial, coincidenciaFinal;
    int i;
    scanf("%d", &nCasos);
    for ( i = 0; i < nCasos; i++)
    {
        scanf("%d %d %d %d", &nacimientoA, &muerteA, &nacimientoB, &muerteB);
        if (muerteA >= nacimientoB && muerteB >= nacimientoA)
        {
            if (muerteA >= nacimientoB && muerteB >= nacimientoA)
            {
                // Determinar el inicio de la coincidencia
                if (nacimientoA > nacimientoB)
                {
                    coincidenciaInicial = nacimientoA;
                }
                else
                {
                    coincidenciaInicial = nacimientoB;
                }
                // Determinar el fin de la coincidencia
                if (muerteA < muerteB)
                {
                    coincidenciaFinal = muerteA;
                }
                else
                {
                    coincidenciaFinal = muerteB;
                }
                // Calcular los años de coincidencia
                int aniosCoincidencia = coincidenciaFinal - coincidenciaInicial + 1;
                printf("%d\n", aniosCoincidencia);
            }
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
