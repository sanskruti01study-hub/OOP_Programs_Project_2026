#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int age;

public:
    // Default Constructor
    Student()
    {
        name = "Unknown";
        age = 0;
    }

    // Parameterized Constructor
    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    // Copy Constructor
    Student(const Student &s)
    {
        name = s.name;
        age = s.age;
    }
};

int main()
{
    Student a;
    Student b("A", 9);
    Student c(b);

    return 0;
}
