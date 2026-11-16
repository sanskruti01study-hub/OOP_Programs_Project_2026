#include <iostream>
#include <string>
using namespace std;

class vehicle
{
private:
string brand;
int price;
public:
void input()
{
cout<<"enter brand:";
cin>>brand;
cout<<"enter price:";
cin>>price;
}
void display()
{
cout<<endl;
cout<<"brand:"<<brand<<endl;
cout<<"price:"<<price<<endl;
}
};
int main()
{
vehicle v;
v.input();
v.display();
return 0;
}
