#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<conio.h>
using namespace std;

int main()
{
	string str,newstr="";
	cout<<"Enter the string :";
	cin>>str;
	for(size_t i = 0; i < str.size(); ++i)
	{
	if(int(str[i])>=65 && int(str[i])<=90)
		newstr += char(int(str[i])+32);
	else if(int(str[i])>=97 && int(str[i])<=122)
		newstr += char(int(str[i])-32);
	}
	cout<<newstr;
	getch();
	return 0;
}
