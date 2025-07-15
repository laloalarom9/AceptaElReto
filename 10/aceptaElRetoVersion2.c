#include <stdio.h>

//  redondeo hacia arriba
int dividirConRedondeo(int n, int k) {
    if (n % k == 0) 
    {
        return n / k;//division normal
    }
    return n / k + 1;//para redondear hacia arriba la division de int 
}

int main() {
    int persona1, bandeja1, perdida1, persona2, bandeja2, perdida2;
    
    scanf("%d %d %d %d %d %d", &persona1, &bandeja1, &perdida1, &persona2, &bandeja2, &perdida2);

    while (persona1 != 0 && persona2 != 0) {
        int viajes1 = 1, viajes2 = 1;//se considera que hacen un viaje al principio
        persona1 -= bandeja1;
        persona2 -= bandeja2;

        
        int ganador = 0;  //  1 = YO, 2 = VECINO, 3 = EMPATE
        int viajes = 0;

        if (persona1 <= 0 && persona2 <= 0) {//A la primera bandeja lo lleno
            ganador = 3;  // EMPATE
            viajes = 1;
        } else if (persona1 <= 0) {
            ganador = 1;  // YO
            viajes = 1;
        } else if (persona2 <= 0) {
            ganador = 2;  // VECINO
            viajes = 1;
        } else {//si no se lleno la primera bandeja
            int difRestoViajes1 = bandeja1 - perdida1;//se le resta la perdida
            int difRestoViajes2 = bandeja2 - perdida2;

            if (difRestoViajes1 > 0 && difRestoViajes2 <= 0) {//si es mayor la perdida que lo que cabe en la bandeja
                viajes = viajes1 + dividirConRedondeo(persona1, difRestoViajes1);
                ganador = 1;  // YO
            } else if (difRestoViajes1 <= 0 && difRestoViajes2 > 0) {
                viajes = viajes2 + dividirConRedondeo(persona2, difRestoViajes2);
                ganador = 2;  // VECINO
            } else {//si no se llena la bandeja
                viajes1 += dividirConRedondeo(persona1, difRestoViajes1);//se calcula los viajes que necesita para llenar la piscina con lo que queda
                viajes2 += dividirConRedondeo(persona2, difRestoViajes2);

                if (viajes1 < viajes2) {//comparo los viajes
                    ganador = 1;  // YO
                    viajes = viajes1;
                } else if (viajes1 > viajes2) {
                    ganador = 2;  // VECINO
                    viajes = viajes2;
                } else {
                    ganador = 3;  // EMPATE
                    viajes = viajes1;
                }
            }
        }

       
        if (ganador == 1) {
            printf("YO %d\n", viajes);
        } else if (ganador == 2) {
            printf("VECINO %d\n", viajes);
        } else {
            printf("EMPATE %d\n", viajes);
        }

        scanf("%d %d %d %d %d %d", &persona1, &bandeja1, &perdida1, &persona2, &bandeja2, &perdida2);
    }

    return 0;
}
