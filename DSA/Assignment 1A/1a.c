#include <stdio.h>
int main()
{
    int num;
    printf("Enter number of rows");
    scanf("%d", &num);
    int array[num];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                printf("Enter the %d row  %d column \n", i + 1, j + 1);
                scanf("%d", &array[i]);
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                printf("%d\t", array[i]);
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}