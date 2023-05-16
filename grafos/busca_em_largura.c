#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    struct No* prox;
} No;

typedef struct Grafo {
    int numVertices;
    No** listaAdj;
} Grafo;

No* criarNo(int destino) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->prox = NULL;
    return novoNo;
}

Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdj = (No**)malloc(numVertices * sizeof(No*));

    int i;
    for (i = 0; i < numVertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = criarNo(destino);
    novoNo->prox = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;
}

void BFS(Grafo* grafo, int verticeInicial) {
    int* visitados = (int*)calloc(grafo->numVertices, sizeof(int));
    int* fila = (int*)malloc(grafo->numVertices * sizeof(int));
    int frente = 0;
    int tras = 0;

    visitados[verticeInicial] = 1;
    fila[tras++] = verticeInicial;

    while (frente != tras) {
        int vertice = fila[frente++];
        printf("%d ", vertice);

        No* temp = grafo->listaAdj[vertice];
        while (temp != NULL) {
            int verticeAdjacente = temp->destino;
            if (!visitados[verticeAdjacente]) {
                visitados[verticeAdjacente] = 1;
                fila[tras++] = verticeAdjacente;
            }
            temp = temp->prox;
        }
    }

    free(visitados);
    free(fila);
}

int main() {
    Grafo* grafo = criarGrafo(6);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);
    adicionarAresta(grafo, 4, 5);

    int verticeInicial = 0;
    printf("BFS começando do vértice %d: ", verticeInicial);
    BFS(grafo, verticeInicial);
    printf("\n");

    return 0;
}
