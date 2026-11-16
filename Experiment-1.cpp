
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 5;
    float c = 3.14f;
    char ch = 's';
    bool isTrue = true;

    cout << "Sum: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;

    cout << "Float value: " << c << endl;
    cout << "Character: " << ch << endl;

    cout << boolalpha;
    cout << "Boolean value: " << isTrue << endl;

    return 0;
}
