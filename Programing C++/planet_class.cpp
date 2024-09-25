#include<iostream>
#include <string>

using namespace std;

//============================================================================
// Homework on basic class
//============================================================================

class Planet 
{
    string planet_name;
    double distance_to_sun;
    double weight;
    double diameter;
public:
    Planet(string name, double distance_to_sun, double diameter, double weight)
    {
        if (distance_to_sun > 0)
            this->distance_to_sun = distance_to_sun;
        if (diameter > 0)
            this->diameter = diameter;
        if (weight > 0)
            this->weight = weight;
        if (name.length() <= 50)
            this->planet_name = name;
    }
    ~Planet()
    {
       this->planet_name=this->planet_name.erase();
       this->diameter = 0;
       this->distance_to_sun = 0;
       this->weight = 0;
    }

    //TODO add getters and setters

    void print()
    {
        cout << "Name: " << this->planet_name << endl;
        cout << "Distance to sun: " << this->distance_to_sun <<" km" << endl;
        cout << "Diameter: " << this->diameter <<" km" << endl;
        cout << "Weight: " << this->weight <<" kg"<< endl;
    }

    double get_seconds_to_sun()
    {
        long double light_speed = 299792;
        return this->distance_to_sun * light_speed;
    }
};

int main() 
{

    //Get all the parameters from the console
    //Make sure that the values are valid!
    //Then create an object of type Planet and test all the methods.
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

    Planet* p = new Planet(name,distance,diameter,weight);

    p->print();

    cout << "Seconds from the planet to the Sun: " << p->get_seconds_to_sun() << " s" << endl;

    return 0;
}