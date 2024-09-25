#include<iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// TASK:
// Implement as many methods as you can in the Vector class.
////////////////////////////////////////////////////////////////////////

class Vector {
    int* data;
    size_t size;
    size_t capacity;

    // Write your code here :)
public:
    /**
    * @brief Initializing the vector with the provided capacity
    *
    * @param capacity
    */
    void init(size_t cap) 
    {
        this->data = new int[cap];
        this->capacity = cap;
        this->size = NULL;
        for (int i = 0; i < capacity; i++)
            this->data[i] = 0;
    }

    /**
    * @brief Creates a new vector with the same elements as the vector calling the function
    *
    * @return Vector* the copied vector
    */
    Vector* copy_vector() 
    {
        Vector* new_vector = new Vector();
        new_vector->size = this->size;
        new_vector->capacity = this->capacity;
        new_vector->data = this->data;
        return new_vector;
    }

    /**
    * @brief Retrieves the value of the vector at the provided index
    *
    * @param index
    * @return int
    */
    int at(size_t index) 
    {
        for (int i = 0; i < this->capacity; i++)
        {
            if (i == index)
                return this->data[index];
        }
        return -1;
    }

    /**
    * @brief Inserts element at the back of the vector
    *
    * @param element
    * @return int 0 if successful, otherwise -1
    */
    int push_back(int element) 
    {
        if (this->size == this->capacity)
            resize();
        for (int i = 0; i < this->capacity; i++)
        {
            if (this->data[i] != NULL)
                continue;
            else
            {
                this->data[i] = element;
                this->size++;
                return 0;
            }
        }
        return -1;
    }

    /**
    * @brief Enlarge the vector with capacity * 2
    */
    void resize() 
    {
        this->capacity *= 2;
        int* temp = new int[capacity];
        memcpy(temp, this->data, this->size * sizeof(int));
        delete this->data;
        init(this->capacity);
        this->data = temp;
    }

    /**
    * @brief Removes the last element of the vector
    * @return the element you just removed if successful, otherwise -1
    */
    int remove_back() 
    {
        for (int i = 0; i < this->capacity; i++)
        {
            if (this->data[i] != NULL)
                continue;
            else
            {
                int element = this->data[i--];
                this->data[i--] = NULL;
                this->size--;
                return element;
            }
        }
        return -1;
    }


    void destroy() 
    {
        delete[] this->data;
        this->size = NULL;
        this->capacity = NULL;
    }
};

// Driver code, do NOT edit this!
int main() 
{
    Vector* v = new Vector();

    v->init(2);

    cout << v->push_back(5) << endl;
    cout << v->push_back(10) << endl;

    Vector* v2 = v->copy_vector(); // Returns a new Vector object
                                   // with capacity 2, size 2 
                                   // and elements 5, 10

    v->destroy();
    v2->resize();

    cout << v2->push_back(15) << endl;
    cout << v2->at(1) << endl; //10
    cout << v2->remove_back() << endl; //15

    v2->destroy();

    return 0;
}