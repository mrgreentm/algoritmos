#include <stdio.h>

void print_vector(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", v[i]);
}

void insertion_sort(int arr[], int size) {
    int i, j, key, low, high, mid;
    
    for (i = 1; i < size; i++) {
        key = arr[i];
        low = 0;
        high = i - 1;
        
        // Busca binária para encontrar a posição correta de inserção
        while (low <= high) {
            mid = (low + high) / 2;
            if (key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Move os elementos maiores para a direita
        for (j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
        }
        
        // Insere o elemento na posição correta
        arr[low] = key;
    }
}
int main()
{
    int v[10] = {12, 45, 6, 7, 8, 12, 5, 9, 10, 2};
    insertion_sort(v, 10);
    print_vector(v, 10);
    return 0;
}