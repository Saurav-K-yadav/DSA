//Sparse Transpose of a matrix
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    int column;
    int row;
    printf("Enter the number of non-zero elements\n");
    scanf("%d ", &num);
    int arr[num+1][3];
    printf("Enter the no. of rows and column\n");
    scanf("%d %d ", &row, &column);
    arr[0][1] = column;
    arr[0][0] = row;
    arr[0][2] = num;
    for (int i = 1; i <= num; i++)
    {
        printf("enter the row, column and value");
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    for (int i = 0; i = num; i++)
    {
        printf("%d \t%d\t %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}