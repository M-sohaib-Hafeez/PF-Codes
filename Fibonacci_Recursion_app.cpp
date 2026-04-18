//Write a program to print fabinacci series using function recursion


#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<conio.h>
int fibonacci(int n);
using namespace std;
int main()
{
    int n;
    int sum=0;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Fibonacci series: ";
    for(int i=0;i<n;i++)
    {
        cout<<fibonacci(i)<<" ";
        sum=sum+fibonacci(i);
    }
    cout<<"\nSum of the series: "<<sum; 
    getch();
    return 0;
}

int fibonacci(int n)
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else
    return fibonacci(n-1)+fibonacci(n-2);
}