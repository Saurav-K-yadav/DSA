#include <stdio.h>
#include <stdlib.h>
void reverse(int arr[], int first, int last);
int main()
{
    int size;
    printf("enter the size of the array\n");
    scanf("%d", &size);
    int *array;
    array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d\n", i + 1);
        scanf("%d", &array[i]);
    }
    reverse(array, 0, size - 1);
    printf("The reverse of the array is \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}
void reverse(int arr[], int first, int last)
{
    int temporary;
    while (first < last)
    {
        temporary = arr[first];
        arr[first] = arr[last];
        arr[last] = temporary;
        first++;
        last--;
    }
}