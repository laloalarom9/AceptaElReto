#include <stdio.h>

int main()
{
    int aguaPiscinaYo, aguaPiscinaVecino;
    int litrosPerdidosYo, litrosPerdidosVecino;
    int capacidadBandejaYo, capacidadBandejaVecino;
    int viajesYo, viajesVecino;
    int i;

    while (1)
    {
        scanf("%d %d %d %d %d %d", &aguaPiscinaYo, &capacidadBandejaYo, &litrosPerdidosYo, &aguaPiscinaVecino, &capacidadBandejaVecino, &litrosPerdidosVecino);
        if (aguaPiscinaYo == 0 && capacidadBandejaYo == 0 && litrosPerdidosYo == 0 && aguaPiscinaVecino == 0 && capacidadBandejaVecino == 0 && litrosPerdidosVecino == 0)
        {
            break;
        }
        
        viajesYo = 0, viajesVecino = 0;

        while (1)
        {

            while (aguaPiscinaYo > 0 || aguaPiscinaVecino > 0)
            {
                if (aguaPiscinaYo > 0)
                {
                    viajesYo++;
                    aguaPiscinaYo -= capacidadBandejaYo;
                    aguaPiscinaYo += litrosPerdidosYo;
                }

                if (aguaPiscinaVecino > 0)
                {
                    viajesVecino++;
                    aguaPiscinaVecino -= capacidadBandejaVecino;
                    aguaPiscinaVecino += litrosPerdidosVecino;
                }
            }

            if (viajesYo == viajesVecino)
            {
                printf("EMPATE %d\n", viajesYo);
                break;
            }
            else if (viajesYo < viajesVecino)
            {
                printf("YO %d\n", viajesYo);
                break;
            }
            else
            {
                printf("VECINO %d\n", viajesVecino);
                break;
            }
        }
    }
    return 0;
}