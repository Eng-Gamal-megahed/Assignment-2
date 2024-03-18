//
// Created by Gamal on 3/14/2024.
//
#include <iostream>
#include <string>
#include <regex>
#include <limits>
using namespace std;

string SYSTEM_COLOR = "\033[1m";
string RESET_COLOR = "\033[0m";
string BOLD = "\033[1;37m";
string RED = "\033[1;31m";
string BLUE = "\033[1;34m";
string YELLOW = "\033[1;33m";
string WHITE = "\033[1;37m";
string GREEN = "\033[1;32m";
string CYAN = "\033[1;36m";
string PURPLE = "\033[1;35m";

int get_int(const string &message = "")
{
    int num = 0;
    cout << SYSTEM_COLOR << message << RESET_COLOR;
    cin >> num;
    while (cin.fail())
    {
        cout << RED << "Invalid Input! Please, follow the instructions\n"
             << RESET_COLOR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << message << RESET_COLOR;
        cin >> num;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}

int findGCF(int num1, int num2)
{
    int mininum = min(num1, num2);
    for (int i = mininum; i >= 1; i--)
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            return i;
        }
    }
    return 1;
}
string color()
{
    int color;
    string player_color;
    cout << BOLD << "Chose system color \n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
         << RESET_COLOR;
    color = get_int();
    while (color != 1 && color != 2 && color != 3 && color != 4 && color != 5 && color != 6)
    {
        cout << RED << "Invalid color. Please choose again\n"
             << RESET_COLOR;
        cout << BOLD << "What is your favorite color?\n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
             << RESET_COLOR;
        color = get_int();
    }
    if (color == 1)
        player_color = BLUE;
    else if (color == 2)
        player_color = YELLOW;
    else if (color == 3)
        player_color = WHITE;
    else if (color == 4)
        player_color = GREEN;
    else if (color == 5)
        player_color = CYAN;
    else
        player_color = PURPLE;
    return player_color;
}

int main()
{
    while (true)
    {
        regex rational("([-+]?(([0-9]+)|0)(\\/[-+]?[1-9]+[0-9]*)?)(( (\\+|-|\\*) [-+]?(((([0-9]+)|0)(\\/[-+]?[0-9]+)?))|(( \\/ -?)(([1-9]+[0-9]*))(\\/[-+]?[1-9]+[0-9]*)?)))");
        int intnum1_prt1, intnum1_prt2, intnum2_prt1, intnum2_prt2, GCF, result_prt1, result_prt2, whole;
        string expression, num1, num1_prt1, num1_prt2, num2, num2_ptr1, num2_prt2;
        char operation;
        bool valid, isminus_frst = false, isminus_scnd = false, foundslash = false, foundoperator = false;
        cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n";
        SYSTEM_COLOR = color();
        cout << SYSTEM_COLOR << "put space before and after the operator\n";
        cout << "Enter the expression :" << RESET_COLOR;
        getline(cin, expression);

        valid = regex_match(expression, rational);
        while (!valid)
        {
            cout << RED << "Invalid number please follow the instructions\nEnter the expression :" << RESET_COLOR;
            getline(cin, expression);
            valid = regex_match(expression, rational);
        }
        for (int i = 0; i < expression.size(); i++)
        {

            if (i != 0)
            {
                if ((expression[i] == '+' || expression[i] == '*' || expression[i] == '-' || expression[i] == '/') && (expression[i - 1] == ' ' && expression[i + 1] == ' '))
                {
                    operation = expression[i];
                    foundoperator = true;
                }
            }
            if (!foundoperator && expression[i] != ' ')
            {
                num1 += expression[i];
            }

            else if (foundoperator && expression[i] != ' ')
            {
                num2 += expression[i];
            }
        }
        num2.erase(0, 1);
        if (num1[0] == '-')
        {
            isminus_frst = true;
            num1.erase(0, 1);
        }
        if (num2[0] == '-')
        {
            isminus_scnd = true;
            num2.erase(0, 1);
        }
        for (char c : num1)
        {
            if (c != '/' && !foundslash)
            {
                continue;
            }
            else
                foundslash = true;
            if (foundslash)
            {
                num1_prt2 += c;
            }
        }
        num1_prt2.erase(0, 1);
        if (num1_prt2.size() > 0)
        {
            intnum1_prt2 = stoi(num1_prt2);
        }
        else
            intnum1_prt2 = 1;
        foundslash = false;
        for (char c : num2)
        {
            if (c != '/' && !foundslash)
            {
                continue;
            }
            else
                foundslash = true;
            if (foundslash)
            {
                num2_prt2 += c;
            }
        }

        num2_prt2.erase(0, 1);
        if (num2_prt2.size() > 0)
        {
            intnum2_prt2 = stoi(num2_prt2);
        }
        else
            intnum2_prt2 = 1;
        foundslash = false;
        for (char c : num1)
        {
            if (c == '/')
            {
                foundslash = true;
                break;
            }
            if (!foundslash)
            {
                num1_prt1 += c;
            }
        }
        intnum1_prt1 = stoi(num1_prt1);
        (isminus_frst) ? intnum1_prt1 *= -1 : intnum1_prt2 *= 1;
        foundslash = false;
        for (char c : num2)
        {
            if (c == '/')
            {
                foundslash = true;
                break;
            }
            if (!foundslash)
            {
                num2_ptr1 += c;
            }
        }
        intnum2_prt1 = stoi(num2_ptr1);
        (isminus_scnd) ? intnum2_prt1 *= -1 : intnum2_prt1 *= 1;

        if (operation == '+')
        {
            result_prt1 = ((intnum1_prt1 * intnum2_prt2) + (intnum2_prt1 * intnum1_prt2));
            result_prt2 = (intnum1_prt2 * intnum2_prt2);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1), abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if (whole)
            {
                cout << whole << " ";
            }
            if (result_prt1 != 0)
            {
                cout << SYSTEM_COLOR << result_prt1 << "/" << result_prt2 << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (operation == '-')
        {
            result_prt1 = ((intnum1_prt1 * intnum2_prt2) - (intnum2_prt1 * intnum1_prt2));
            result_prt2 = (intnum1_prt2 * intnum2_prt2);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1), abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if (whole)
            {
                cout << whole << " ";
            }
            if (result_prt1 != 0)
            {
                cout << SYSTEM_COLOR << result_prt1 << "/" << result_prt2 << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (operation == '*')
        {
            result_prt1 = (intnum1_prt1 * intnum2_prt1);
            result_prt2 = (intnum1_prt2 * intnum2_prt2);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1), abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if (whole)
            {
                cout << whole << " ";
            }
            if (result_prt1 != 0)
            {
                cout << SYSTEM_COLOR << result_prt1 << "/" << result_prt2 << endl;
            }
            else
                cout << 0 << endl;

        }
        else if (operation == '/')
        {
            result_prt1 = (intnum1_prt1 * intnum2_prt2);
            result_prt2 = (intnum1_prt2 * intnum2_prt1);
            whole = result_prt1 / result_prt2;
            GCF = findGCF(abs(result_prt1), abs(result_prt2));
            result_prt1 /= GCF;
            result_prt2 /= GCF;
            result_prt1 %= result_prt2;
            if (whole)
            {
                cout << whole << " ";
            }
            if (result_prt1 != 0)
            {
                cout << SYSTEM_COLOR << result_prt1 << "/" << result_prt2 << endl;
            }
            else
                cout << 0 << endl;
        }
        int choose;
        cout << SYSTEM_COLOR << "1) Another operation\n2) Exit\n ";
        cin >> choose;
        while (cin.fail() || (choose != 1 && choose != 2))
        {
            cout << RED << "Invalid input! PLease, Follow the instructions." << SYSTEM_COLOR << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << SYSTEM_COLOR << "\n1) Another operation\n2) Exit\n ";
            cin >> choose;
        }
        if (choose == 2)
        {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
