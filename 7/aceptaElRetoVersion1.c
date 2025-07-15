#include <stdio.h> //Para printf y scanf

int obtenerMaximo(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
} // se le pasan dos valores y devuelve el mayor

int obtenerMinimo(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
} // se le pasan dos valores y devuelve el menor
int main()
{
    while (1)
    {
        int longitudCiclo, i, valorEntrada, maxGananciaAnterior, maxGananciaActual, maxGananciaInicial, minGananciaInicial, sumaTotal;

        if (scanf("%d", &longitudCiclo) != 1 || longitudCiclo == 0)
            break; // Salir del bucle si longitudCiclo es 0 o la lectura falla

        // Leer el primer valor
        if (scanf("%d", &valorEntrada) != 1)
        {
            break; // Verificar si scanf tuvo éxito
        }

        // Inicializar variables
        maxGananciaAnterior = valorEntrada;
        maxGananciaActual = obtenerMaximo(valorEntrada, 0);
        maxGananciaInicial = valorEntrada;
        minGananciaInicial = valorEntrada;
        sumaTotal = valorEntrada;

        for (i = 1; i < longitudCiclo; i++)
        { // Empieza en 1 porque ya se leyó el primer valor
            if (scanf("%d", &valorEntrada) != 1)
            {
                break; // Verificar si scanf tuvo éxito
            }

            maxGananciaActual += valorEntrada; // maxGananciaActual=maxGananciaActual+valorEntrada;
            sumaTotal += valorEntrada;         // sumaTotal=sumaTotal+valorEntrada

            maxGananciaInicial = obtenerMaximo(maxGananciaInicial, sumaTotal);
            minGananciaInicial = obtenerMinimo(minGananciaInicial, sumaTotal);
            maxGananciaActual = obtenerMaximo(maxGananciaActual, 0);
            maxGananciaAnterior = obtenerMaximo(maxGananciaActual, maxGananciaAnterior);
        }
        int resultado = obtenerMaximo(maxGananciaAnterior, sumaTotal - minGananciaInicial + maxGananciaInicial);
        //maxGananciaAnterior mejor ganancia sin considerar perdidas
        //sumaTotal se suma todo y despues se resta la peor perdida y la mayor ganancia se suma
        //Ignorar la peor perdida y considerar la mejor ganancia o contemplar la combinacion de las ganancias sin contemplar perdidas y sacar el mayor
        printf("%d\n", resultado);
    }

    return 0;
}