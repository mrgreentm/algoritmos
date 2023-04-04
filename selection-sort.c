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

int find_minor(int v[], int k, int size)
{
    int min_index = k;
    for (int i = k + 1; i < size; i++)
    {
        if (v[i] < v[min_index])
            min_index = i;
    }
    return min_index;
}

void selection_sort(int v[], int size)
{
    int min_index = 0;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = find_minor(v, i, size);
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