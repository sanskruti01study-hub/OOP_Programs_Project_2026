#include <iostream>
using namespace std;

class Complex
{
    float real, imag;

public:
    Complex()
    {
        real = imag = 0;
    }

    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c)
    {
        return Complex(real + c.real,
                      imag + c.imag);
    }

    Complex operator*(Complex c)
    {
        return Complex(real * c.real - imag * c.imag,
                      real * c.imag + imag * c.real);
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);

    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;

    cout << "Addition: ";
    c3.display();

    cout << "Multiplication: ";
    c4.display();

    return 0;
}
