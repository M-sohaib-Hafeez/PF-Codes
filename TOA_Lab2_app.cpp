#include <iostream>
#include<conio.h>
#include <stdio.h>
#include<String.h>

using namespace std;

int main(){
    char Input [100];
    system("cls");
    cout<<"Enter a string to validate (input String should be of 0s and 1s)\n  ";
    fgets(Input, sizeof(Input), stdin);
    int i=-1;
    q:
    i++;
    if(Input[i]=='0'){
        goto q0;
    }
    else if(Input[i]=='1'){
        goto q1;
    }
    else if(Input[i]=='\0'){
        goto Invalid;
    }
    else{
        goto Wrong;
    }
    q0:
    i++;
    if(Input[i]=='0'){
        goto q0;
    }
    else if(Input[i]=='1'){
        goto q1;
    }
    else if(Input[i]=='\0'){
        goto Valid;
    }
    else{
        goto Wrong;
    }
    q1:
    i++;
    if(Input[i]=='0'){
        goto q2;
    }
    else if(Input[i]=='1'){
        goto q0;
    }
    else if(Input[i]=='\0'){
        goto Invalid;
    }
    else{
        goto Wrong;
    }
    q2:
    i++;
    if(Input[i]=='0'){
        goto q1;
    }
    else if(Input[i]=='1'){
        goto q2;
    }
    else if(Input[i]=='\0'){
        goto Invalid;
    }
    else{
        goto Wrong;
    }
    Valid:
    cout<<"\n Output: Valid String";
    goto exit;
    Invalid:
    cout<<"\n Output: Invalid String";
    goto exit;
    Wrong:
    cout<<"\n Please enter a valid string consisting of 0s and 1s only.";
    exit:
    getch();
    return 0;
}