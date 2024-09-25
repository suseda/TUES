#include <iostream>

//======================================//
//======== First exam - group 1 ========//
//======================================//

using namespace std;

class Movie {
    string name;
    double time; // This is stored as hours -> 1.5 means 1 hour and 30 minutes
    string description;

public:
    // Default constructor
    Movie() {}

    // Custom constructor
    Movie(string name, double time, string description) {
        this->name = name;
        this->time = time;
        this->description = description;
    }

    Movie(const Movie& movie) {
        this->name = movie.name;
        this->time = movie.time;
        this->description = movie.description;
    }

    // TODO: Predefine the operator =
    Movie& operator=(const Movie& movie)
    {
        if (this != &movie)
        {
            this->name = movie.name;
            this->time = movie.time;
            this->description = movie.description;
        }
        return *this;
    }

    // TODO: Add getters and setters here

    string get_name()
    {
        return this->name;
    }
    void set_name(string new_name)
    {
        this->name = new_name;
    }

    string get_description()
    {
        return this->description;
    }
    void set_description(string new_description)
    {
        this->description = new_description;
    }

    double get_time()
    {
        return this->time;
    }
    void set_time(double new_time)
    {
        this->time = new_time;
    }

    // TODO: Convert the time from hours to seconds
    // *60=minutes*60= seconds => *360
    double convert_time_from_hours_to_seconds()
    {
        return this->time * 360;
    }
};

class MyList {
    Movie* movies;
    string description;
    size_t moviesCount, capacity;

    // TODO: Resize your movie array when full
    void resize()
    {
        this->capacity = this->capacity * 2;
        Movie* tmp = new Movie[this->capacity];
        for (int i = 0; i < this->moviesCount; i++)
        {
            tmp[i] = this->movies[i];
        }
        delete[] this->movies;

    }
public:
    MyList() {}

    // Custom constructor
    MyList(Movie* movies, string description, size_t moviesCount, size_t capacity) {
        this->description = description;
        this->moviesCount = moviesCount;
        this->capacity = capacity;

        this->movies = new Movie[this->capacity];
        for (int i = 0; i < this->moviesCount; i++) {
            this->movies[i] = movies[i];
        }
    }

    // TODO: Implement the copy constructor
    MyList(const MyList& myList)
    {
        this->description = myList.description;
        this->moviesCount = myList.moviesCount;
        this->capacity = myList.capacity;
        this->movies = new Movie[this->moviesCount];
        for (int i = 0; i < this->moviesCount; i++)
        {
            this->movies[i] = myList.movies[i];
        }

    }

    MyList& operator= (const MyList& list) {
        if (this != &list) {
            this->description = list.description;
            this->moviesCount = list.moviesCount;
            this->capacity = list.capacity;

            delete[] this->movies;

            this->movies = new Movie[this->capacity];
            for (int i = 0; i < this->moviesCount; i++) {
                this->movies[i] = list.movies[i];
            }
        }
        return *this;
    }

    // TODO: Add getters and setters

    string get_description()
    {
        return this->description;
    }
    void set_description(string new_description)
    {
        this->description = new_description;
    }

    size_t get_moviesCount()
    {
        return this->moviesCount;
    }
    void set_moviesCount(size_t cnt)
    {
        this->moviesCount = cnt;
    }

    size_t get_capacity()
    {
        return this->capacity;
    }
    void set_capacity(size_t capacity)
    {
        this->capacity = capacity;
    }

    Movie* get_movies()
    {
        return this->movies;
    }
    void set_movies(Movie* new_movies)
    {
        for (int i = 0; i < this->moviesCount; i++)
        {
            this->movies[i] = new_movies[i];
        }
    }

    // TODO: Add movie the movie array.
    // If successful -> 0, if there are error/s -> -1
    // You should think what to do when the size of the array movies reaches the capacity
    int add(string name)
    {
        if (this->moviesCount == this->capacity)
        {
            this->resize();
        }

        for (int i = 0; i < this->moviesCount; i++)
        {
            if (this->movies[i].get_name() == name)
            {
                return -1;
            }
        }

        this->movies[this->moviesCount].set_name(name);
        this->moviesCount++;
        return 0;
       
    }

};

// Write your code here if you want to test it.
// Only the code for the classes will be graded.
// The code in the main function will NOT be graded.
// If it is written good, you might recieve bonus points.
int main() {
    return 0;
}