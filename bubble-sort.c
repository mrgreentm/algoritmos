#include <stdio.h>

void print_vector(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", v[i]);
}

void swap(int v[], int i)
{
    int aux = v[i];
    v[i] = v[i + 1];
    v[i + 1] = aux;
}

void bubble_sort(int v[], int size)
{
    int flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v, j);
            flag++;
        }
        if (flag == 0)
            return;
    }
}

int main()
{
    int v[10] = {12, 45, 6, 7, 8, 12, 5, 9, 10, 2};
    bubble_sort(v, 10);
    print_vector(v, 10);
    return 0;
}