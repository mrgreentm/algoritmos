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

void DFSUtil(Grafo* grafo, int vertice, int visitados[]) {
    visitados[vertice] = 1;
    printf("%d ", vertice);

    No* temp = grafo->listaAdj[vertice];
    while (temp != NULL) {
        int verticeAdjacente = temp->destino;
        if (!visitados[verticeAdjacente]) {
            DFSUtil(grafo, verticeAdjacente, visitados);
        }
        temp = temp->prox;
    }
}

void DFS(Grafo* grafo, int verticeInicial) {
    int* visitados = (int*)calloc(grafo->numVertices, sizeof(int));
    DFSUtil(grafo, verticeInicial, visitados);
    free(visitados);
}

void possuiLigacao(int vertice1, int vertice2, Grafo *grafo)
{
    
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
    printf("DFS começando do vértice %d: ", verticeInicial);
    DFS(grafo, verticeInicial);
    printf("\n");

    return 0;
}