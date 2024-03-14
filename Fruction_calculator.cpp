//
// Created by Gamal on 3/14/2024.
//
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main ()
{
    regex rational("-?(([1-9]+[0-9]*)|0)(/[1-9]+[0-9]*)?");
    int intnum1_prt1 , intnum1_prt2 , intnum2_prt1 , intnum2_prt2;
    string num1 , num1_prt1 , num1_prt2 , num2 , num2_ptr1 , num2_prt2;
    char chose;
    bool valid , isminus_frst , isminus_scnd , foundslash = false;
    cout << "Enter the first number :";
    cin >> num1;
    valid = regex_match(num1 , rational);
    while(!valid){
        cout << "Invalid number please follow the instructions\nEnter the first number :";
        cin >> num1;
        valid = regex_match(num1 , rational);
    }
    cout << "Enter the first number :";
    cin >> num2;
    valid = regex_match(num2 , rational);
    while(!valid){
        cout << "Invalid number please follow the instructions\nEnter the first number :";
        cin >> num2;
        valid = regex_match(num2 , rational);
    }
    if(num1[0] == '-')
    {
        isminus_frst = true;
        num1.erase(0,1);
    }
    if(num2[0] == '-')
    {
        isminus_scnd = true;
        num2.erase(0,1);
    }
    for (char c : num1) {
        if (c != '/' && !foundslash)
        {
            continue;
        }
        else
            foundslash = true;
        if(foundslash)
        {
            num1_prt2 += c;
        }
    }
    num1_prt2.erase(0,1);
    intnum1_prt2 = stoi(num1_prt2);
    foundslash = false;
    for (char c : num2) {
        if (c != '/' && !foundslash)
        {
            continue;
        }
        else
            foundslash = true;
        if(foundslash)
        {
            num2_prt2 += c;
        }
    }
    num2_prt2.erase(0,1);
    intnum2_prt2 = stoi(num2_prt2);
    foundslash = false;
    for (char c : num1) {
        if (c == '/') {
            foundslash = true;
            break;
        }
        if (!foundslash) {
            num1_prt1 += c;
        }
    }
    intnum1_prt1 = stoi(num1_prt1);
    (isminus_frst)? intnum1_prt1*=-1 : intnum1_prt2*=1 ;
    foundslash =false;
    for (char c : num2) {
        if (c == '/') {
            foundslash = true;
            break;
        }
        if (!foundslash) {
            num2_ptr1 += c;
        }
    }
    intnum2_prt1 = stoi(num2_ptr1);
    (isminus_frst)? intnum2_prt1*=-1 : intnum2_prt2*=1 ;

    cout << "1)Addition\n2)Subtraction\n";
    cin >> chose;

    if (chose == '1')
    {
        cout << (intnum1_prt1 * intnum2_prt2) + (intnum2_prt1 * intnum1_prt2) << "/" << (intnum1_prt2 * intnum2_prt2);
    }
    if (chose == '2')
    {
        cout << (intnum1_prt1 * intnum2_prt2) - (intnum2_prt1 * intnum1_prt2) << "/" << (intnum1_prt2 * intnum2_prt2);
    }
    return 0 ;
}