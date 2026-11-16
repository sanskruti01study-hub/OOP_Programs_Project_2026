#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(T a)
    {
        if (top == 4)
        {
            cout << "Stack full" << endl;
        }
        else
        {
            top++;
            arr[top] = a;
            cout << "Pushed: " << a << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack empty" << endl;
        }
        else
        {
            cout << "Element popped: " << arr[top] << endl;
            top--;
        }
    }
};

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();

    return 0;
}
