#include <iostream>
#include <map>
#include <string>
using namespace std;

// A map to help convert text to morse code.
map <char,string> Dic = {
        {'a',".-"}     ,   {'b',"-..."},
        {'c',"-.-."}   ,   {'d',"-.."},
        {'e',"."}      ,   {'f',"..-."},
        {'g',"--."}    ,   {'h',"...."},
        {'i',".."}     ,   {'j',".---"},
        {'k',"-.-"}    ,   {'l',".-.."},
        {'m',"--"}     ,   {'n',"-."},
        {'o',"---"}    ,   {'p',".--."},
        {'q',"--.-"}   ,   {'r',".-."},
        {'s',"..."}    ,   {'t',"-"},
        {'u',"..-"}    ,   {'v',"...-"},
        {'w',".--"}    ,   {'x',"-..-"},
        {'y',"-.--"}   ,   {'z',"--.."},
        {'0',"-----"}  ,   {'1',".----"},
        {'2',"..---"}  ,   {'3',"...--"},
        {'4',"....-"}  ,   {'5',"....."},
        {'6',"-...."}  ,   {'7',"--..."},
        {'8',"---.."}  ,   {'9',"----."}
};
// A map to help convert morse code to text.
map <string ,char> reversed_Dic = {
        {".-", 'a'}    ,   {"-...", 'b'},
        {"-.-.", 'c'}  ,   {"-..", 'd'},
        {".", 'e'}     ,   {"..-.", 'f'},
        {"--.", 'g'}   ,   {"....", 'h'},
        {"..", 'i'}    ,   {".---", 'j'},
        {"-.-", 'k'}   ,   {".-..", 'l'},
        {"--", 'm'}    ,   {"-.", 'n'},
        {"---", 'o'}   ,   {".--.", 'p'},
        {"--.-", 'q'}  ,   {".-.", 'r'},
        {"...", 's'}   ,   {"-", 't'},
        {"..-", 'u'}   ,   {"...-", 'v'},
        {".--", 'w'}   ,   {"-..-", 'x'},
        {"-.--", 'y'}  ,   {"--..", 'z'},
        {" ",' '}      ,   {"-----", '0'},
        {".----", '1'} ,   {"..---", '2'},
        {"...--", '3'} ,   {"....-", '4'},
        {".....", '5'} ,   {"-....", '6'},
        {"--...", '7'} ,   {"---..", '8'},
        {"----.", '9'}
};

int encode ();
int decode ();
void cont ();

int main (){
    string choice ;
    // Welcoming statement.
    cout << "Welcome to Morse Code Translator, which encrypts text to Morse code and decrypts Morse code to text.\n" ;
    while (true) {
        // Take from the user the operation that s/he wants.
        cout << "Which operation do you want to do : \n a) Encrypt \n b) Decrypt\n";
        getline(cin, choice);
        if (choice == "a" or choice == "A") {
            encode();
            break;
        } else if (choice == "b" or choice == "B") {
            decode();
            break;
        } else { cout << "Please, enter a valid input: " << endl; }
    }

}


// cont function asks the user if he wants to continue or not.
void cont (){
    string cont_option;
    while (true) {
        cout << "\nDo you want to continue ?\na)YES\nb)NO" << endl;
        getline(cin, cont_option);
        if (cont_option == "a" or cont_option == "A") {
            // The program will start again.
            main();
        } else if (cont_option == "b" or cont_option == "B") {
            // End program.
            exit(0);
        } else { cout << "Please, enter a valid input: " ; }

    }
}
// encode function encrypts text to Morse code.
int encode() {
    string encrpt_stat;
    string encrypted_stat ;
    cout << "Any non-English letters or non-English numbers will be converted to a space." << endl;
    cout << "Please enter your statement you want to encrypt:";
    getline(cin, (encrpt_stat));
    // Iterate on the user input and replace every character with its Morse Code.
    for (int i =0 ; i < encrpt_stat.size() ; i++){
        encrypted_stat.append(Dic[tolower(encrpt_stat[i]) ] + " ");
    }
    cout << "The encrypted statement is :" << endl << encrypted_stat;
    cont();
    return 0;
}
// decode function decrypts Morse code to text.
int decode() {
    string decrypt_stat;
    string decrypted_stat = "";
    cout << "Please enter your statement you want to decrypt:";
    getline(cin, decrypt_stat);
    string x ="";
    // Iterate on the user input and replace every Morse Code to its character.
    for (char i : decrypt_stat) {
        if (i == ' ') {
            // if there are two spaces.
            if (x == "") {
                decrypted_stat += " ";     // Space between words
                x = "";
            } else {
                decrypted_stat += reversed_Dic[x];
                x = "";
            }
        }
        // if the input is't a Morse Code.
        else if ((i != '-') && (i != '.')){
            cout << "The statement is not a morse code.Please choose a correct operation." << endl;
            x = "";
            main();
        }
        else {
            x += i;
        }

    }
    if (!x.empty()) {
        decrypted_stat += reversed_Dic[x];
    }

    cout << "The decrypted statement is:" << decrypted_stat;
    cont();
    return 0;
}

