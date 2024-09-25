#include <iostream>
#include <string.h>

using namespace std;

const long double LIGHT_SPEED = 299792;

//============================================================================
// Homework on basic classes Planet & SolarSystem
//============================================================================

class Planet
{
    string name;
    double distanceToSun;
    double weight;
    double diameter;
    bool isAvailableForVisit;
public:
    Planet() {}
    /**
     * @brief Construct a new Planet object
     *
     * @param name
     * @param distanceToSun
     * @param diameter
     * @param weight
     * @param isAvailableForVisit
     */
    Planet(string name, double distanceToSun, double diameter, double weight, bool isAvailableForVisit)
    {
        if (distanceToSun > 0)
            this->distanceToSun = distanceToSun;
        if (diameter > 0)
            this->diameter = diameter;
        if (weight > 0)
            this->weight = weight;
        if (name.length() <= 50)
            this->name = name;
        this->isAvailableForVisit = true;
    }

    /**
     * @brief Copy constructor for a new Planet object
     *
     * @param planet
     */
    Planet(const Planet& planet)
    {
        this->name = planet.get_name();
        this->diameter = planet.get_diameter();
        this->distanceToSun = planet.get_distance();
        this->weight = planet.get_weight();
        this->isAvailableForVisit = planet.get_is_available();
    }

    /**
     * @brief Destroy the Planet object
     *
     */
    ~Planet() {}

    // Rewrite the code to throw an exception
    // saying self-assignment is not allowed
    // if this == &planet
    Planet& operator=(const Planet& planet) {
        if (this != &planet) {
            this->name = planet.name;
            this->distanceToSun = planet.distanceToSun;
            this->diameter = planet.diameter;
            this->weight = planet.weight;
            this->isAvailableForVisit = planet.isAvailableForVisit;
        }
        return *this;
    }

    //TODO add getters and setters for ALL fields 

    double get_distance()const
    {
        return this->distanceToSun;
    }
    void set_distance(double new_distance)
    {
        this->distanceToSun = new_distance;
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
        return this->name;
    }
    void set_name(string name)
    {
        this->name = name;
    }


    double get_diameter()const
    {
        return this->diameter;
    }
    void set_diameter(double new_diameter)
    {
        this->diameter = new_diameter;
    }

    bool get_is_available()const
    {
        return this->isAvailableForVisit;
    }
    void set_is_available(int new_visited)
    {
        this->isAvailableForVisit = new_visited;
    }

    /**
     * @brief Display contents of Planet object, use this
     *
     */
    void print()
    {
        cout << "Name: " << this->name << endl;
        cout << "Distance to sun: " << this->distanceToSun << endl;
        cout << "Diameter: " << this->diameter << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "Is available for visit: " << this->isAvailableForVisit << endl;
    }

    /**
     * @brief Calculates seconds to the Sun
     *
     * @return double
     */
    double getSecondsToSun()
    {
        return this->distanceToSun * LIGHT_SPEED;
    }
};

class SolarSystem {

    //Array of planets, planets count, capacity, name
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

        delete[] this->system;
        this->system = temp;

    }

public:
    /**
     * @brief Construct a new SolarSystem object.
     * Creating empty solar system with the planetsCount as capacity
     *
     * @param planetsCount
     */
    SolarSystem(size_t planetsCount)
    {
        this->planets_count = 0;
        this->system_capacity = planetsCount;
        this->system_size = 0;
        this->system = new Planet[this->system_capacity];
    }

    /**
     * @brief Construct a new SolarSystem object.
     * Creating solar system with name, planetsCount as capacity
     * and copying the Planet objects from planets
     *
     * @param planets
     * @param planetsCount
     */
    SolarSystem(Planet* planets, size_t planetsCount, string name)
    {
        this->system = new Planet[planetsCount];
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
    SolarSystem& operator=(const SolarSystem& solarSystem) {}

    /**
     * @brief Get the planetsCount
     *
     * @return size_t
     */
    size_t getPlanetsCount()const
    {
        return this->planets_count;
    }

    /**
     * @brief Get a planet at the provided index.
     * Throw exception if the index is invalid.
     *
     * @param index
     * @return const Planet&
     */
    const Planet& at(int index)const
    {
        if (index < 0)
        {
            throw "Index can't be negative!";
        }

        if (index > this->system_size)
        {
            throw "Index should be within the size of the system";
        }

        return this->system[index];
    };

    /**
     * @brief  Adding a Planet to a SolarSystem.
     * If the planet you are trying to add exists - throw an exception.
     * Otherwise, return 0.
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
                throw "This planet exist";
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
     * @brief Remove a planet from the array.
     * If the planet can't be found - throw an exception.
     * Otherwise return 0
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
        throw "The planet can't be found";
    }

    /**
     * @brief Change the isAvailableForVisit field of the planet and make it not available for visits.
     * A.k.a visit the planet.
     * Throw exception if you can't visit the planet.
     * Otherwise, return 1.
     *
     * @param name
     * @return int
     */
    int visitPlanet(string name)
    {
        for (int i = 0; i < this->planets_count; i++)
        {
            if (this->system[i].get_name() == name)
            {
                if (this->system[i].get_is_available() == false)
                {
                    throw "The planet has been visited";
                }


                if (this->system[i].get_is_available() == true)
                {
                    this->system[i].set_is_available(false);
                    return 1;
                }

            }
        }
        throw "The planet isn't in the Solar system";
        return 0;
    }
};

int main()
{
    // Implement ALL the methods!!!
    // Create a dynamic menu to show that all the functionalities are working.
    // You should expect input until the user hits 'q'.

    char hit_q;
    SolarSystem* solar_system = NULL;
    Planet* planet = new Planet();
    do
    {
        cout << "Enter 1 to create solar system (Note: create it without planets)" << endl;
        cout << "Enter 2 to add planets to the solar system" << endl;
        cout << "Enter 3 to remove planets from the solar system" << endl;
        cout << "Enter 4 to visit a planet" << endl;
        cout << "Enter 5 to Quit" << endl;
        int num;
        string name, planet_name;
        double distance, diameter, weight;
        cout << "Enter: " << endl;
        cin >> num;
        switch (num)
        {
        case 1:
            system("clear");
            solar_system = new SolarSystem(2);
            break;

        case 2:
            system("clear");
            if (solar_system == NULL)
            {
                cout << "First make solar system then add planets" << endl;
                break;
            }
            cout << "Name: " << endl;
            cin >> name;
            cout << "Distance to sun: " << endl;
            cin >> distance;
            cout << "Diameter: " << endl;
            cin >> diameter;
            cout << "Weight: " << endl;
            cin >> weight;
            system("clear");

            planet = new Planet(name, distance, diameter, weight, true);
            try
            {
                solar_system->add(*planet);
            }
            catch (const char* msg)
            {
                cerr << msg << endl;
            };
            break;

        case 3:
            system("clear");
            cout << "Planet name that you want to remove: " << endl;
            cin >> name;
            try
            {
                solar_system->remove(name);
            }
            catch (const char* msg)
            {
                cerr << msg << endl;
            };

            break;

        case 4:
            system("clear");
            cout << "Enter planet name: " << endl;
            cin >> planet_name;
            try
            {
                solar_system->visitPlanet(planet_name);
            }
            catch (const char* msg)
            {
                cerr << msg << endl;
            };
            break;
        case 5:
            hit_q = 'q';
            break;
        default:
            cout << "Please enter number from 1 to 5" << endl;
        };


    } while (hit_q != 'q');
    // Your menu has to have the following options printed before
    // selecting a choice every time:
    // 1. Create solar system (Note: create it without planets)
    // 2. Add planets to the solar system
    // 3. Remove planets from the solar system
    // 4. Visit a planet
    // Press 'q' if you want to exist or choose an option:
    return 0;
}