#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    printf("enter the size of the array\n");
    scanf("%d", &size);
    int *array;
    array = (int *)malloc(size * sizeof(int));
    int i = 0;

    while (1)
    {
        int placeholder;
        int insert;
        int position;
        int search;
        printf("press : \n");
        printf("1 to create\n");
        printf("2 to display\n");
        printf("3 to insert\n");
        printf("4 to delete\n");
        printf("5 to search\n");
        printf("6 to exit\n");

        scanf("%d", &placeholder);
        switch (placeholder)
        {
        case 1:
            for (i = 0; i < size; i++)
            {
                printf("Enter the element number %d\n", i + 1);
                scanf("%d", (array + i));
            }
            break;

        case 2:
            printf("The array is:\n");
            for (i = 0; i < size; i++)
            {
                printf("%d\t", *(array + i));
            }
            printf("\n");
            break;
        case 3:
            printf("Enter the position where you want to insert\n");
            scanf("%d", &position);
            printf("Enter the element\n");
            scanf("%d", &insert);
            size++;
            array = (int *)realloc(array, size * sizeof(int));
            for (i = size - 1; i >= position; i--)
            {
                array[i] = array[i - 1];
            }
            array[position - 1] = insert;
            break;
        case 4:
        {
            printf("Enter the array you wanat to delete");
            int del;
            scanf("%d", &del);
            for (i = 0; i < size; i++)
            {
                if (array[i] == del)
                {
                    for (i; i < size - 1; i++)
                    {
                        array[i] = array[i + 1];
                    }
                    size--;
                    array = (int *)realloc(array, size * sizeof(int));
                }
            }
            break;
        }
        case 5:
        {
            printf("Enter the array you want to search\n");
            scanf("%d", &search);
            int catch = 0;
            for (i = 0; i < sizeof(array); i++)
            {
                if (array[i] == search)
                {
                    printf("The position of array %d is: %d\n", search, i + 1);
                    catch = 1;
                }
            }
            if (catch != 1)
            {
                printf("Error: NOT FOUND!!!\n");
            }
            break;
        }
        case 6:
            printf("exiting\n");
            exit(1);
            break;
        default:
            printf("Invalid option, Enter again\n");
            break;
        }
    }
    free(array);
    return 0;
}