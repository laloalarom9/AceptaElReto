#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_LENGTH 1001
#define MAX_SYMBOLS 10

typedef struct NodeTrie {
    struct NodeTrie* arr[MAX_SYMBOLS]; // Espacio para hasta 10 símbolos (0-9)
    int isEndOfSymbol; // Marca si es un símbolo válido
} NodeTrie;

// Función para crear un nuevo nodo en el Trie
NodeTrie* createNode() {
    NodeTrie* newNode = (NodeTrie*)malloc(sizeof(NodeTrie));
    int i; // Declarar aquí
    for (i = 0; i < MAX_SYMBOLS; i++) {
        newNode->arr[i] = NULL; // Inicializa todos los punteros a NULL
    }
    newNode->isEndOfSymbol = 0; // Inicializa como no símbolo válido
    return newNode;
}

// Función para insertar un símbolo en el Trie
void insert(NodeTrie* root, const char* symbol) {
    NodeTrie* cur = root;
    while (*symbol) {
        int index = *symbol - '0'; // Convertir carácter a dígito
        if (cur->arr[index] == NULL) {
            cur->arr[index] = createNode(); // Crear un nuevo nodo si no existe
        }
        cur = cur->arr[index];
        symbol++;
    }
    cur->isEndOfSymbol = 1; // Marca el final de un símbolo válido
}

// Función para liberar memoria del Trie
void removeTrie(NodeTrie* root) {
    int i; // Declarar aquí
    for (i = 0; i < MAX_SYMBOLS; i++) {
        if (root->arr[i] != NULL) {
            removeTrie(root->arr[i]); // Llama recursivamente
            free(root->arr[i]); // Libera el nodo
        }
    }
}

// Función principal
int main() {
    int n;

    while (1) {
        scanf("%d", &n); // Leer el número de símbolos
        if (n == 0) break; // Terminar si n es 0

        NodeTrie* trie = createNode(); // Crear el trie
        int i; // Declarar aquí
        for (i = 0; i < n; ++i) {
            char simbolo[10]; // Suponemos que los símbolos tienen como máximo 9 dígitos
            scanf("%s", simbolo); // Leer el símbolo
            insert(trie, simbolo); // Insertar en el trie
        }

        char mensaje[MAX_LENGTH];
        scanf("%s", mensaje); // Leer el mensaje cifrado
        long long posibilidades[MAX_LENGTH] = {0}; // Inicializa el arreglo de posibilidades
        posibilidades[0] = 1; // Hay una forma de decodificar la cadena vacía

        // Procesar el mensaje
        int longitud = strlen(mensaje);
        for (i = 0; i < longitud; ++i) {
            if (mensaje[i] == '0') {
                posibilidades[i + 1] = posibilidades[i]; // Solo se puede propagar
                continue;
            }
            NodeTrie* cur = trie;
            int j; // Declarar aquí
            for (j = i; j < longitud; ++j) {
                int pos = mensaje[j] - '0'; // Convertir a entero
                if (cur->arr[pos] == NULL) break; // Si no existe el código, salir
                if (cur->arr[pos]->isEndOfSymbol) { // Si es un símbolo válido
                    posibilidades[j + 1] = (posibilidades[j + 1] + posibilidades[i]) % MOD; // Actualiza las posibilidades
                }
                cur = cur->arr[pos]; // Moverse al siguiente nodo
            }
        }

        printf("%lld\n", posibilidades[longitud]); // Salida del número de formas

        removeTrie(trie); // Liberar memoria del trie
    }

    return 0; // Finaliza el programa correctamente
}
