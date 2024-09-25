#include <iostream>
#include <string>

using namespace std;

//============================================================================
// Homework on basic classes Planet & SolarSystem
//============================================================================

class Planet {
    //TODO add fields for name, distanceToSun, diameter, weight, isAvailableForVisit
    string planet_name;
    double distance_to_sun;
    double weight;
    double diameter;
    int visited;

public:
    Planet() {}
    /**
     * @brief Construct a new Planet object
     *
     * @param name
     * @param distanceToSun
     * @param diameter
     * @param weight
     */
    Planet(string name, double distanceToSun, double diameter, double weight)
    {
        if (distance_to_sun > 0)
            this->distance_to_sun = distance_to_sun;
        if (diameter > 0)
            this->diameter = diameter;
        if (weight > 0)
            this->weight = weight;
        if (name.length() <= 50)
            this->planet_name = name;
        this->visited = 0;
    }

    /**
     * @brief Copy constructor for a new Planet object
     *
     * @param planet
     */
    Planet(const Planet& planet) 
    {
        this->planet_name = planet.get_name();
        this->diameter = planet.get_diameter();
        this->distance_to_sun = planet.get_distance();
        this->weight = planet.get_weight();
    }

    /**
     * @brief Destroy the Planet object
     *
     */
    ~Planet() {}

    // Read about predefining operators
    // What would happen if you delete it
    // and try to copy an object with '='?
    Planet& operator=(const Planet& planet) {
        if (this != &planet) {
            this->planet_name = planet.planet_name;
            this->distance_to_sun = planet.distance_to_sun;
            this->diameter = planet.diameter;
            this->weight = planet.weight;
        }
        return *this;
    }

    //TODO add getters and setters for ALL fields 

    double get_distance()const
    {
        return this->distance_to_sun;
    }
    void set_distance(double new_distance)
    {
        this->distance_to_sun = new_distance;
    }

    double get_weight()const
    {
        return this->weight;
    }
    void set_weight(double new_weight)
    {
        this->weight = new_weight;
    }

    string get_name() const
    {
        return this->planet_name;
    }
    void set_first_name(string name)
    {
        this->planet_name = name;
    }


    double get_diameter()const
    {
        return this->diameter;
    }
    void set_diameter(double new_diameter)
    {
        this->diameter = new_diameter;
    }

    int get_visited()
    {
        return this->visited;
    }
    void set_visited(int new_visited)
    {
        this->visited = new_visited;
    }

    /**
     * @brief Display contents of Planet object, use this
     *
     */
    void print()
    {
        cout << "Name: " << this->planet_name << endl;
        cout << "Distance to sun: " << this->distance_to_sun << endl;
        cout << "Diameter: " << this->diameter << endl;
        cout << "Weight: " << this->weight << endl;
    }

    /**
     * @brief Calculates seconds to the sun
     *
     * @return double
     */
    double getSecondsToSun()
    {
        long double light_speed = 299792;
        return this->distance_to_sun * light_speed;
    }
};

class SolarSystem {

    //Array of planets, planets count, array size, capacity

    Planet* system;
    int planets_count;
    int system_size;
    int system_capacity;

    /**
     * @brief Resizing the array with double capacity.
     * The resize method is private! Why?
     *
     */
    void resize()
    {
        this->system_capacity *= 2;
        Planet* temp;
        temp = new Planet[this->system_capacity];

        for (int i = 0; i < this->system_capacity; i++)
        {
            if (this->system_size > i)
            {
                temp[i] = this->system[i];
            }
        }

        delete [] this->system;
        this->system = temp;

    }
public:
    /**
     * @brief Construct a new SolarSystem object.
     * Creating empty library with the planetsCount as capacity
     *
     * @param planetsCount
     */
    SolarSystem(size_t planetsCount)
    {
        this->planets_count = 0;
        this->system_capacity = planetsCount;
        this->system_size = 0;
    }

    /**
     * @brief Construct a new SolarSystem object.
     * Creating solar system with planetsCount as capacity
     * and copying the Planet objects from planets
     *
     * @param planets
     * @param planetsCount
     */
    SolarSystem(Planet* planets, size_t planetsCount)
    {
        for (int i = 0; i < planetsCount; i++)
        {
            this->system[i] = planets[i];
        }

        this->planets_count = planetsCount;
        this->system_capacity = planetsCount;
        this->system_size = planetsCount;
    }


    /**
     * @brief Construct a new SolarSystem object. Copy constructor
     *
     * @param other
     */
    SolarSystem(const SolarSystem& other) 
    {
        this->system = other.system;
        this->planets_count = other.planets_count;
        this->system_size = other.system_size;
        this->system_capacity = system_capacity;
    }

    /**
     * @brief Predefine the '=' operator
     *
     * @param solarSystem
     * @return SolarSystem&
     */
    SolarSystem& operator=(const SolarSystem& solarSystem); //Write it if you want, it is almost the same as the copy constructor

    /**
     * @brief Get the lanetsCount
     *
     * @return size_t
     */
    size_t getPlanetsCount()const
    {
        return this->planets_count;
    }

    /**
     * @brief Get a planet at the provided index. Validate the index
     *
     * @param index
     * @return const Planet&
     */
    const Planet& at(size_t index)const
    {
        if (index >= 0)
        {
            return this->system[index];
        }
    }

    /**
     * @brief  Adding a Planet to a SolarSystem.
     Check if a Planet with this name already exists in the solarSystem, if so return -1, else return 0.
     *
     * @param planet
     * @return int
     */
    int add(const Planet& planet)
    {
        int i = 0;
        for (; i < this->planets_count; i++)
        {
            if (this->system[i].get_name() == planet.get_name())
            {
                return -1;
            }
        }

        if (this->system_size == this->system_capacity)
        {
            this->resize();
        }

        this->system[i] = planet;
        this->system_size += 1;
        this->planets_count += 1;

        return 0;
    }

    /**
     * @brief Remove a planet from the array. Return -1 if not found, else return 0
     *
     * @param name
     * @return int
     */
    int remove(string name)
    {
        for (int i = 0; i < this->planets_count; i++)
        {
            if (this->system[i].get_name() == name)
            {
                this->planets_count -= 1;
                this->system_size -= 1;
                for (int j = i; j < this->planets_count; j++)
                {
                    this->system[j] = this->system[j + 1];
                }
                return 0;
            }
        }
        return -1;
    }

    /**
     * @brief Change the isAvailableForVisit field of the book.
     * Aka visit the planet. Validate if the planet is available
     *
     * @param name
     * @return int
     */
    int visitPlanet(string name) // return 1 for successful visited
    {
        for (int i = 0; i < this->planets_count; i++)
        {
            if (this->system[i].get_name() == name)
            {
                if (this->system[i].get_visited() == 0)
                {
                    this->system[i].set_visited(1);
                    return 1;
                }
                return 0;
            }
        }
        return 0;
    }
};

int main() 
{

    //Get all the parameters from the console
    //Make sure that the values are valid!
    //Then create an object of type Planet and test all the methods.

    int i = 0;
    string name;
    double diameter, distance, weight;

    cout << "Planet name: " << endl;
    cin >> name;
    cout << "Distance to sun: " << endl;
    cin >> distance;
    cout << "Diameter of the planet: " << endl;
    cin >> diameter;
    cout << "Weight of the planet: " << endl;
    cin >> weight;
    Planet* p = new Planet(name, distance, diameter, weight);


    cout << "Planet name: " << endl;
    cin >> name;
    cout << "Distance to sun: " << endl;
    cin >> distance;
    cout << "Diameter of the planet: " << endl;
    cin >> diameter;
    cout << "Weight of the planet: " << endl;
    cin >> weight;
    Planet* p2 = new Planet(name, distance, diameter, weight);


    cout << "Planet name: " << endl;
    cin >> name;
    cout << "Distance to sun: " << endl;
    cin >> distance;
    cout << "Diameter of the planet: " << endl;
    cin >> diameter;
    cout << "Weight of the planet: " << endl;
    cin >> weight;
    Planet* p3 = new Planet(name, distance, diameter, weight);

    Planet* planets = 0;
    size_t cnt = 3;
    SolarSystem* s = new SolarSystem(planets, cnt);

    s->add(*p);
    s->add(*p2);
    s->add(*p3);

    return 0;
}
