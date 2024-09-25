#include <iostream>

using namespace std;

class Person
{
	string first_name;
	string last_name;
	int age;
	float height;
	string gender;
public:
	int get_age()
	{
		return this->age;
	}
	void set_age(int new_age)
	{
		this->age = new_age;
	}

	float get_height()
	{
		return this->height;
	}
	void set_height(float new_height)
	{
		this->height = new_height;
	}

	string get_first_name()
	{
		return this->first_name;
	}
	void set_first_name(string name)
	{
		this->first_name = name;
	}
	string get_last_name()
	{
		return this->last_name;
	}
	void set_last_name(string name)
	{
		this->last_name = name;
	}
	string get_gender()
	{
		return this->gender;
	}
	void set_gender(string gender)
	{
		this->gender = gender;
	}
};

int main()
{
	Person* person = new Person();
	person->get_age(), person->set_age(16);
	person->get_height(), person->set_height(1.75);
	person->get_first_name(), person->set_first_name("Kaloyan");
	person->get_last_name(), person->set_last_name("Sotirov");
	person->get_gender(), person->set_gender("male");

	cout << "Hi! I am " << person->get_first_name() << " " << person->get_last_name();
	cout << "\t";
	cout << "Age: " << person->get_age() << " " << "Height: " << person->get_height() << " " << "Gender: " << person->get_gender();

}