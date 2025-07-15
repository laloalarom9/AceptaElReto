#include <stdio.h>

int main() {
    char tren[10001]; // tren con un máximo de 10,000 vagones
    int parejas_formadas, indice_vagon; // Contador de parejas e índice para recorrer el tren
    char vagones_pendientes[10001]; // Almacena los vagones que aún no tienen pareja
    int indice_pendientes;          // Índice del último vagón pendiente

    while (scanf("%s", tren) != EOF) {// Leer tren hasta fin de archivo
        parejas_formadas = 0;
        indice_pendientes = -1; // Inicializar la lista de vagones pendientes en -1

        for (indice_vagon = 0; tren[indice_vagon] != '\0'; indice_vagon++) {// Recorrer el tren mientras haya vagones y no sea el final de la cadena
            switch (tren[indice_vagon]) {
                case '@': // Reiniciar al encontrar el separador @
                    indice_pendientes = -1;
                    break;
                case 'H':
                case 'h': 
                    vagones_pendientes[++indice_pendientes] = tren[indice_vagon];
                    break;
                case 'M': // Emparejar con un vagón 'H'
                    if (indice_pendientes >= 0 && vagones_pendientes[indice_pendientes] == 'H') {// Si hay un vagón 'H' pendiente
                        indice_pendientes--;
                        parejas_formadas++;
                    } else {
                        vagones_pendientes[++indice_pendientes] = tren[indice_vagon]; // No se pudo emparejar
                    }
                    break;
                case 'm': // Emparejar con un vagón 'h'
                    if (indice_pendientes >= 0 && vagones_pendientes[indice_pendientes] == 'h') {
                        indice_pendientes--;
                        parejas_formadas++;
                    } else {
                        vagones_pendientes[++indice_pendientes] = tren[indice_vagon]; // No se pudo emparejar
                    }
                    break;
            }
        }

        printf("%d\n", parejas_formadas);
    }

    return 0;
}
