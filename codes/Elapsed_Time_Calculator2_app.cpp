

#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>
using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    Time s_time;
    Time e_time;
    Time el_time;

    cout << "Enter the start time: ";
    cin >> s_time.hours >> s_time.minutes >> s_time.seconds;

    cout << "Enter the end time: ";
    cin >> e_time.hours >> e_time.minutes >> e_time.seconds;

    el_time.hours = e_time.hours - s_time.hours;
    el_time.minutes = e_time.minutes - s_time.minutes;
    el_time.seconds = e_time.seconds - s_time.seconds;

    if(el_time.seconds < 0)
    {
        el_time.seconds += 60;
        el_time.minutes--;
    }   
    if(el_time.minutes < 0)
    {
        el_time.minutes += 60;
        el_time.hours--;
    }
    if(el_time.hours < 0)
    {
        el_time.hours += 24;
    }
    cout << "Elapsed time: " << el_time.hours << ":" << el_time.minutes << ":" << el_time.seconds << endl;
    getch();
    return 0;   
}