#include <stdio.h>


void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], unsigned int size, int i) 
{
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (right_child < size && arr[right_child] > arr[largest])
        largest = right_child;

    if (left_child < size && arr[left_child] > arr[largest])
        largest = left_child;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapsort(int arr[], unsigned int size) 
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void print_array(int arr[], unsigned int size) 
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    puts("");
}

int main()
{
	int arr[] = {2,4,7,1,5,3,8,6};
    int size = sizeof(arr) / sizeof(arr[0]);
	heapsort(arr, size);
	print_array(arr, size);
	return 0;
}




