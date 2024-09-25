#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class NumberValidator {
public:
    static vector<int> readNumbers(const string& line)
    {
        istringstream input_line(line);
        int a, b, c;
        vector<int> nums;
        if (input_line >> a >> b >> c)
        {
            nums.at(0) = a;
            nums.at(1) = b;
            nums.at(2) = c;
        }
        else
        {
            input_line >> a >> b;
            nums.at(0) = a;
            nums.at(1) = b;
        }

        return nums;
    }
    static bool isValid(vector<int> sides)
    {
        for (int i = 0; i < sides.size(); i++)
        {
            if (sides.at(i) <= 0)
                return 0;
        }
        return 1;
    }
    static bool isTriangle(int a, int b, int c)
    {
        if ((a < b + c) && (b < a + c) && (c < a + b))
            return 1;
        return 0;
    }
};

class Figure {
public:
    double calculateArea(int a, int b) const
    {

    }
    double calculatePerimeter(int a, int b) const
    {

    }
};

class Rectangle : public Figure {
public:

    double calculateArea(int a, int b) const
    {
        return a * b;
    }
    double calculatePerimeter(int a, int b) const
    {
        return 2 * (a + b);
    }
};

class Triangle : public Figure {
public:
    double calculateArea(int a, int b, int c) const
    {
        NumberValidator valid;
        vector<int> nums;
        nums.at(0) = a;
        nums.at(1) = b;
        nums.at(2) = c;
        if (valid.isTriangle(a,b,c) && valid.isValid(nums))
        {
            int p = (a + b + c) / 2;
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
    }
    double calculatePerimeter(int a, int b, int c) const
    {
        NumberValidator valid;
        vector<int> nums;
        nums.at(0) = a;
        nums.at(1) = b;
        nums.at(2) = c;
        if (valid.isTriangle(a, b, c) && valid.isValid(nums))
        {
            return a + b + c;
        }
    }
};

int main() 
{
    ifstream input_file;
    input_file.open("input.txt", ios::in);
    ofstream output_file;
    output_file.open("output.txt", ios::out);
    if (input_file.is_open())
    {
        string line;
        getline(input_file, line);
        istringstream input_line(line);
        while(getline(input_file, line))
        {
            NumberValidator valid;
            vector<int> nums = valid.readNumbers(line);
            if (valid.isValid(nums))
            {
                if (nums.size() == 3)
                {
                    int a= nums.at(0);
                    int b = nums.at(1);
                    int c = nums.at(2);
                    if (valid.isTriangle(a,b,c))
                    {
                        Triangle t;
                        double S = t.calculateArea(a, b, c);
                        double P = t.calculatePerimeter(a, b, c);
                        output_file << S << "," << P << endl;
                    }
                    else
                    {
                        output_file << "One or more of the sides do not meet the condition to create a triangle!" << endl;
                    }
                }
                else
                {
                    int a = nums.at(0);
                    int b = nums.at(1);
                    Rectangle rect;
                    double S = rect.calculateArea(a, b);
                    double P = rect.calculatePerimeter(a, b);
                    output_file << S << "," << P << endl;
                }
            }
            else
            {
                output_file << "One or more of the sides are not valid!"<< endl;
            }
        }


    }

    input_file.close();

    return 0;
}