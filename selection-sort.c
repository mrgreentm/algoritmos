#include <stdio.h>

void print_vector(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", v[i]);
}

void swap(int v[], int i, int min_index)
{
    int aux = v[i];
    v[i] = v[min_index];
    v[min_index] = aux;
}

void selection_sort(int v[], int size)
{
    int min_index = 0;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)

            if (v[j] < v[min_index])
            {
                min_index = j;
            }

        swap(v, i, min_index);
    }
}

int main()
{
    int v[10] = {12, 45, 6, 7, 8, 12, 5, 9, 10, 2};
    selection_sort(v, 10);
    print_vector(v, 10);
    return 0;
}