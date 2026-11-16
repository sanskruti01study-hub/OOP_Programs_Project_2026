#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string URN;

public:
    Person(string n = "", int a = 0, string u = "")
    {
        name = n;
        age = a;
        URN = u;
    }

    void display_person()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "URN: " << URN << endl;
    }
};

// Single Inheritance
class Student : public Person
{
protected:
    string rollno;
    string course;
    float cgpa;

public:
    Student(string n = "", int a = 0, string u = "",
            string r = "", string c = "", float g = 0.0)
        : Person(n, a, u)
    {
        rollno = r;
        course = c;
        cgpa = g;
    }

    void display_student()
    {
        display_person();
        cout << "Roll No: " << rollno << endl;
        cout << "Course: " << course << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

// Multilevel Inheritance
class GraduateStudent : public Student
{
private:
    string thesisTopic;
    string researchArea;
    string supervisor;

public:
    GraduateStudent(string n = "", int a = 0, string u = "",
                    string r = "", string c = "", float g = 0.0,
                    string t = "", string ra = "", string s = "")
        : Student(n, a, u, r, c, g)
    {
        thesisTopic = t;
        researchArea = ra;
        supervisor = s;
    }

    void display_graduate_student()
    {
        display_student();
        cout << "Thesis: " << thesisTopic << endl;
        cout << "Research: " << researchArea << endl;
        cout << "Supervisor: " << supervisor << endl;
    }
};

int main()
{
    GraduateStudent s1("Arjun S", 20, "URN2021B",
                      "B1", "BTech", 8.7,
                      "AI", "ML", "Dr. Sharma");

    s1.display_graduate_student();

    return 0;
}
