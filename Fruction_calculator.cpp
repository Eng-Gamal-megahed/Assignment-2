//
// Created by Gamal on 3/14/2024.
//
#include <iostream>
#include <string>
#include <regex>
#include <limits>
using namespace std;
int findGCF(int num1 , int num2)
{
    int mininum = min(num1 , num2);
    for(int i = mininum ; i>=1 ; i-- )
    {
        if((num1 % i == 0) && (num2 % i == 0))
        {
            return i;
        }
    }
    return 1;
}

int main ()
{
    while (true)
{
        regex rational("(-?(([1-9]+[0-9]*)|0)(/[1-9]+[0-9]*)?)(( (\\+|-|\\*) -?(((([1-9]+[0-9]*)|0)(/[1-9]+[0-9]*)?))|(( / -?)(([1-9]+[0-9]*))(/[1-9]+[0-9]*)?)))");
        int intnum1_prt1 , intnum1_prt2 , intnum2_prt1 , intnum2_prt2 , GCF , result_prt1 , result_prt2 , whole;
        string expression , num1 , num1_prt1 , num1_prt2 , num2 , num2_ptr1 , num2_prt2;
        char operation;
        bool valid , isminus_frst = false , isminus_scnd = false , foundslash = false , foundoperator = false;
        cout << "put space before and after the operator\n";
        cout << "Enter the expression :";
        getline(cin , expression);


    valid = regex_match(expression , rational);
        while(!valid){
            cout << "Invalid number please follow the instructions\nEnter the expression :";
            getline(cin , expression);
            valid = regex_match(expression , rational);
        }
        for (int i = 0 ; i < expression.size() ; i ++)
        {

            if(i != 0)
            {
                if((expression[i] == '+' || expression[i] == '*' || expression[i] == '-'  || expression[i] == '/') && (expression[i-1] == ' ' && expression[i+1] == ' '))            {
                    operation = expression[i];
                    foundoperator= true;
                }
            }
            if(!foundoperator && expression[i] != ' ')
            {
                num1 += expression[i];
            }

            else if(foundoperator && expression[i] != ' ')
            {
                num2 += expression[i];
            }
        }
        num2.erase(0,1);
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
        (isminus_scnd)? intnum2_prt1*=-1 : intnum2_prt1*=1 ;


        if (operation == '+')
        {
            result_prt1 = ((intnum1_prt1 * intnum2_prt2) + (intnum2_prt1 * intnum1_prt2));
            result_prt2 = (intnum1_prt2 * intnum2_prt2);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1),abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if(whole){cout << whole << " " ;}
            if(result_prt1 != 0)
            {
                cout << result_prt1 << "/" << result_prt2<<endl;
            }
            else
                cout << 0 << endl;

        }
        else if (operation == '-')
        {
            result_prt1 = ((intnum1_prt1 * intnum2_prt2) - (intnum2_prt1 * intnum1_prt2));
            result_prt2 = (intnum1_prt2 * intnum2_prt2);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1),abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if(whole){cout << whole << " " ;}
            if(result_prt1 != 0)
            {
                cout << result_prt1 << "/" << result_prt2<<endl;
            }
            else
                cout << 0 << endl;
        }
        else if (operation == '*'){
            result_prt1=(intnum1_prt1 * intnum2_prt1);
            result_prt2=(intnum1_prt2 * intnum2_prt2);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1),abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if (whole){ cout << whole << " " ;}
            else if (result_prt1 != 0){
                cout<< result_prt1 << "/" << result_prt2 << endl;
            }
        }
        else if (operation == '/'){
            result_prt1=(intnum1_prt1 * intnum2_prt2);
            result_prt2=(intnum1_prt2 * intnum2_prt1);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1),abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if (whole){cout << whole << " " ;}
            else if (result_prt1 != 0){
                cout<< result_prt1 << "/" << result_prt2 << endl;
            }
        }
        int choose;
        cout<<"1) Another operation\n2) Exit\n ";
        cin>>choose;
        while (cin.fail() || (choose!=1 && choose!=2)){
            cout<<"Invalid input! PLease, Follow the instructions."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n1) Another operation\n2) Exit\n ";
            cin>>choose;
        }
        if (choose==2){
            break;
        }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return 0 ;
}
