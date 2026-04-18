#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{
    struct person
    {
        string name;
        int age;
        string address;
    };
    person p1;
    cout<<"Enter the name :";
    cin>>p1.name;
    cout<<"Enter the age :";
    cin>>p1.age;
    cout<<"Enter the address :";
    cin>>p1.address;
    cout<<"Name :"<<p1.name<<endl;
    cout<<"Age :"<<p1.age<<endl;
    cout<<"Address :"<<p1.address<<endl;
    getch();
    return 0;
}
