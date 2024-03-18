#include <iostream>
#include <map>
#include <string>
using namespace std;

string debacon(string mssg)
{
    string newOne = "";
    map <string, char > decipher =
            {
                    { "aaaaa", 'A' }, { "aaaab", 'B' }, { "aaaba", 'C' }, { "aaabb", 'D' }, { "aabaa", 'E' },
                    { "aabab", 'F' }, { "aabba", 'G' }, { "aabbb", 'H' }, { "abaaa", 'I' }, { "abaab", 'J' },
                    { "ababa", 'K' }, { "ababb", 'L' }, { "abbaa", 'M' }, { "abbab", 'N' }, { "abbba", 'O' },
                    { "abbbb", 'P' }, { "baaaa", 'Q' }, { "baaab", 'R' }, { "baaba", 'S' }, { "baabb", 'T' },
                    { "babaa", 'U' }, { "babab", 'V' }, { "babba", 'W' }, { "babbb", 'X' }, { "bbaaa", 'Y' },
                    { "bbaab", 'Z' }, { " ", ' ' }
            };

    for (int i = 0; i < mssg.length() - 4; i += 5)
    {
        string thing = mssg.substr(i, 5);
        newOne += decipher[thing];
    }
    return newOne;
}

string bacon(string mssg )
{
    string newOne = "";
    map <char, string> cipher =
            {
                    { 'A', "aaaaa" }, { 'B', "aaaab" }, { 'C', "aaaba" }, { 'D', "aaabb" }, { 'E', "aabaa" },
                    { 'F', "aabab" }, { 'G', "aabba" }, { 'H', "aabbb" }, { 'I', "abaaa" }, { 'J', "abaab" },
                    { 'K', "ababa" }, { 'L', "ababb" }, { 'M', "abbaa" }, { 'N', "abbab" }, { 'O', "abbba" },
                    { 'P', "abbbb" }, { 'Q', "baaaa" }, { 'R', "baaab" }, { 'S', "baaba" }, { 'T', "baabb" },
                    { 'U', "babaa" }, { 'V', "babab" }, { 'W', "babba" }, { 'X', "babbb" }, { 'Y', "bbaaa" },
                    { 'Z', "bbaab" } , {' ', " "}
            };

    for (char i : mssg)
    {
        newOne += cipher[i];
    }

    return newOne;
}

int main()
{
    char flag;
    string mssg;

    cout << "give me ur message: ";
    getline(cin, mssg);
    for (char& c : mssg)
    {
        c = toupper(c);
    }
    cout << "A) encrypt     B)decrypt" << endl;
    cin >> flag;

    if (flag == 'a' || flag == 'A')
    {
        cout << bacon(mssg);
    }
    else if(flag == 'b'|| flag == 'B')
    {
        cout << debacon(mssg);
    }

    return 0;
}