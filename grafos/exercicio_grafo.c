#include <stdio.h>
#include <stdlib.h>

// Dado um grafo direcionado representado pela estrutura de lista de adjacência,
// escreva uma função em C para verificar se existe um caminho entre dois vértices fornecidos.

typedef struct Node
{
    int dest;
    struct Node *prox;
} Node;

typedef struct Grafo
{
    int numVertices;
    Node **listaAdj;
} Grafo;

Node *criarNo(int dest)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->dest = dest;
    novoNo->prox = NULL;
    return novoNo;
}

Grafo *criarGrafo(int numVertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdj = (Node **)malloc(numVertices * sizeof(Node *));

    int i;
    for (i = 0; i < numVertices; i++)
    {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void adicionarAresta(Grafo *grafo, int origem, int destino)
{
    Node *novoNo = criarNo(destino);
    novoNo->prox = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;
}

int possuiCaminhoDFS(Grafo *grafo, int verticeInicial, int verticeFinal, int visitados[])
{
    if (verticeInicial == verticeFinal)
    {
        return 1; // Encontrou um caminho
    }

    visitados[verticeInicial] = 1;

    Node *temp = grafo->listaAdj[verticeInicial];
    while (temp != NULL)
    {
        if (!visitados[temp->dest])
            if (possuiCaminhoDFS(grafo, temp->dest, verticeFinal, visitados))
                return 1; // Encontrou um caminho

        temp = temp->prox;
    }

    return 0; // Não encontrou um caminho
}

int possuiCaminho(Grafo *grafo, int verticeInicial, int verticeFinal)
{
    int *visitados = (int *)calloc(grafo->numVertices, sizeof(int));
    int resultado = possuiCaminhoDFS(grafo, verticeInicial, verticeFinal, visitados);
    free(visitados);
    return resultado;
}

int main()
{
    Grafo *grafo = criarGrafo(6);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);
    adicionarAresta(grafo, 4, 5);
    adicionarAresta(grafo, 6, 9);

    int verticeInicial, verticeFinal;
    printf("Digite o vértice inicial: ");
    scanf("%d", &verticeInicial);
    printf("Digite o vértice final: ");
    scanf("%d", &verticeFinal);

    if (possuiCaminho(grafo, verticeInicial, verticeFinal))
    {
        printf("Existe um caminho entre %d e %d.\n", verticeInicial, verticeFinal);
    }
    else
    {
        printf("Não existe um caminho entre %d e %d.\n", verticeInicial, verticeFinal);
    }

    return 0;
}
