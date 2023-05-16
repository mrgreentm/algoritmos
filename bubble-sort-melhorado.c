#include <stdio.h>

void bubbleSortRecursive(int arr[], int n) {
    // Caso base: se houver apenas um elemento ou a lista estiver vazia, retorna
    if (n <= 1) {
        return;
    }

    // Realiza uma passagem do Bubble Sort
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Troca os elementos adjacentes se estiverem fora de ordem
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Chama recursivamente o Bubble Sort para a parte desordenada restante
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSortRecursive(arr, n);
    
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}