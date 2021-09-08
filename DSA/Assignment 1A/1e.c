//Symmetrical Matrix
//upper triangular matrix
#include <stdio.h>
int main()
{
    int num;
    printf("Enter number of rows");
    scanf("%d", &num);
    int k = 0;
    int array[(num * (num + 1)) / 2];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i >= j)
            {
                printf("Enter the element of %d row and %d column", i + 1, j + 1);
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
            // if (i <= j)
            // {
                printf("%d\t", array[(i*(i-1))/ 2 + j ]);
            // }
            // else
            //     printf("%d\t", j * num - (j - 1) * j / 2 + i - j);
        }
        printf("\n");
    }
}