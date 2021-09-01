#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    printf("Enter number of rows");
    scanf("%d", &num);
    int k = 0;
    int array[3 * num + 2];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (abs(i - j) <= 1)
            {
                printf("Enter the element of %d row and %d colomn\n", i + 1, j + 1);
                scanf("%d", &array[k]);
                k++;
            }
        }
    }
    k = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (abs(i - j) <= 1)
            {
                printf("%d \t", array[k]);
                k++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}