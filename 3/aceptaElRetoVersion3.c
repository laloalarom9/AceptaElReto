#include <stdio.h>

int main()
{
    int numeroSimbolos;
    char mensaje[200];

    while (1)
    {
        scanf("%d", &numeroSimbolos);
        if (numeroSimbolos == 0)
        {
            break;
        }
        int numCodigo[numeroSimbolos];
        for (int i = 0; i < numeroSimbolos; i++)
        {
            scanf("%d", &numCodigo[i]);
        }
        scanf("%s", mensaje);           // Leer mensaje cifrado
        int longitud = stlrlen(mensaje); // Se obtiene la longitud del mensaje
        for(int i = 0; i < longitud; i++)
        {
            
            int digito = mensaje[i] - '0'; // Convertimos el carácter a número. en ASCII 0 es 48 y 1 es 49, si restas obtienes el número
            
        }
    }
    return 0;
}