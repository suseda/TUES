#include <stdio.h>
#include <string.h>

int find_most_common(int* array, unsigned int size) 
{
    int most_common = array[0];
    int most_occurances = 1;

    for (int i = 0; i < size - most_occurances; i++) {
        int curr_item = array[i];
        int curr_occurances = 1;

        for (int j = i + 1; j < size; j++) {
            if (array[j] == curr_item) curr_occurances++;
        }

        if (curr_occurances > most_occurances) {
            most_common = curr_item;
            most_occurances = curr_occurances;
        }
    }

    return most_common;
}

void sort_most_common(int* array, unsigned int size) {
    int most_common = find_most_common(array, size);

  
    int buffer[size];
    int buffer_index = 0;
    for (int i = 0; i < size; i++) 
    {
        if (array[i] != most_common) {
            buffer[buffer_index] = array[i];
            buffer_index++;
        }
    }

    for (int i = buffer_index; i < size; i++) {
        buffer[i] = most_common;
    }

    memcpy(array, buffer, sizeof(int) * size);
}

void print_array(int* array, unsigned int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    puts("");
}

int main() {
    int arr1[] = { 1, 3, 5, 3, 7 };
    int arr2[] = { 3, 4, 2, 4, 3 };

    sort_most_common(arr1, 5);
    sort_most_common(arr2, 5);

    print_array(arr1, 5);
    print_array(arr2, 5);

    return 0;
}