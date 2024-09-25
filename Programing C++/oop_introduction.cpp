// C -> #include<stdio.h>
#include<iostream>

using namespace std;

struct point_t {};

struct vector_t {
    int capacity;
    int size;
    int* array;
};

typedef struct vector_t vector;

void initialize_vector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        v->array[i] = i * 5;
    }
}

void print_vector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        // printf("%d ", array[i]);
        cout << v->array[i] << " ";
    }
    cout << endl;
}

void create_vector(vector* v, int capacity, int size) {
    v->size = size;
    v->capacity = capacity;
    // C -> v->array = (int*) malloc(sizeof(int) * size);
    v->array = new int[capacity];
}

// add
void add(vector* v, int value) {

    if (v->size == v->capacity) {
        v->capacity = v->capacity * 2;
        vector *tmp = new vector[v->size];
        memcpy(tmp, v, sizeof(v[0]) * v->capacity);
        swap(tmp, v);
        delete[] tmp;
    }

    v->array[v->size] = value;
    v->size++;

}

// C -> malloc, calloc, realloc, free()
// C++ -> new, delete

// HW: void delete_vector(vector* v);
void delete_vector(vector* v)
{
    v->size = NULL;
    v->capacity = NULL;
    delete v->array;
}


int main() {
    // struct vector_t v;
    vector v;

    const int SIZE = 2;
    const int CAPACITY = 5;
    create_vector(&v, CAPACITY, SIZE);
    initialize_vector(&v);
    print_vector(&v);

    add(&v, 1);
    add(&v, 2);
    add(&v, 3);
    add(&v, 4);

    print_vector(&v);
    delete_vector(&v);

    return 0;
}