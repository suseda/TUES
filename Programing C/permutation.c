#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
void printarray(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void permutation(int arr, int start, int end)
{

    if (start == end)
    {
        printarray(arr, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        swap((arr + i), (arr + start));
        permutation(arr, start + 1, end);
        swap((arr + i), (arr + start));
    }
}

void main()
{
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int* arr;
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
    permutation(arr, 0, size - 1);
    free(arr);
}
