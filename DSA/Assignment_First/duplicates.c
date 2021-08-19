#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    int i;
    printf("enter the size of the array\n");
    scanf("%d", &size);
    int *array;
    array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        printf("Enter the element number %d\n", i + 1);
        scanf("%d", (array + i));
    }
    for (i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                for (int k = j; k < size; k++)
                {
                    array[k] = array[k + 1];
                }
                j--;
                size--;
            }
        }
    }

    array = (int *)realloc(array, size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
}