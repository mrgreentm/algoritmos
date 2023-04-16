#include <stdio.h>

void print_vector(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", v[i]);
}

void insertion_sort(int v[], int size)
{
    int aux, i, j;
    for (i = 0; i < size - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            aux = v[i + 1];
            v[i + 1] = v[i];
            v[i] = aux;
            j = i - 1;

            while (j >= 0)
            {
                if (aux < v[j])
                {
                    v[j + 1] = v[j];
                    v[j] = aux;
                }
                else
                {
                    break;
                }
                j--;
            }
        }
    }
}

int main()
{
    int v[10] = {12, 45, 6, 7, 8, 12, 5, 9, 10, 2};
    insertion_sort(v, 10);
    print_vector(v, 10);
    return 0;
}