//
// Created by Gamal on 3/17/2024.
//
#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <bitset>

using namespace std;
string SYSTEM_COLOR;
string RESET_COLOR = "\033[0m";
string BOLD = "\033[1;37m";
string RED = "\033[1;31m";
string BLUE = "\033[1;34m";
string YELLOW = "\033[1;33m";
string WHITE = "\033[1;37m";
string GREEN = "\033[1;32m";
string CYAN = "\033[1;36m";
string PURPLE = "\033[1;35m";

// A map to help convert text to morse code.
map<char, string> Dic = {
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'+', ".-.-."}, {'=', "-...-"}, {'/', "-..-."}, {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {' ', " "}};
int get_int(const string& message = "")
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
    else player_color = PURPLE;
    return player_color;
}
void cont();
int encode();
int decode();
// A map to help convert morse code to text.
map<string, char> reversed_Dic = {
    {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'}, {"-----", '0'}, {" ", ' '}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {".-.-.", '+'}, {"-...-", '='}, {"-..-.", '/'}, {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}};
int Morse_Code()
{ // main
    string choice;
    // Welcoming statement.
    cout << SYSTEM_COLOR << "Morse Code Translator, which encrypts text to Morse code and decrypts Morse code to text.\n"
         << RESET_COLOR;
    while (true)
    {
        // Take from the user the operation that s/he wants.
        cout << SYSTEM_COLOR << "Which operation do you want to do : \na) Encrypt \nb) Decrypt\n"
             << RESET_COLOR;
        getline(cin, choice);
        if (choice == "a" || choice == "A")
        {
            encode();
            break;
        }
        else if (choice == "b" || choice == "B")
        {
            decode();
            break;
        }
        else
        {
            cout << RED << "Please, enter a valid input: " << RESET_COLOR << endl;
        }
    }
    return 0;
}

// cont function asks the user if he wants to continue or not.
void cont()
{
    string cont_option;
    while (true)
    {
        cout << SYSTEM_COLOR << "\nDo you want to do another operation ?\na)YES\nb)NO" << RESET_COLOR << endl;
        getline(cin, cont_option);
        if (cont_option == "a" || cont_option == "A")
        {
            // The program will start again.
            Morse_Code();
        }
        else if (cont_option == "b" || cont_option == "B")
        {
            // End program.
            return;
        }
        else
        {
            cout << RED << "Please, enter a valid input: " << RESET_COLOR;
        }
    }
}
// encode function encrypts text to Morse code.
int encode()
{
    string encrypt_stat;
    string encrypted_stat;
    cout << SYSTEM_COLOR << "Any non-English letters or non-English numbers will be converted to a space." << RESET_COLOR << endl;
    cout << SYSTEM_COLOR << "Please enter your statement you want to encrypt:" << RESET_COLOR;
    getline(cin, (encrypt_stat));
    // Iterate on the user input and replace every character with its Morse Code.
    for (int i = 0; i < encrypt_stat.size(); i++)
    {
        encrypted_stat.append(Dic[tolower(encrypt_stat[i])] + " ");
    }
    cout << SYSTEM_COLOR << "The encrypted statement is :" << endl
         << encrypted_stat << RESET_COLOR;
    cont();
    return 0;
}
// decode function decrypts Morse code to text.
int decode()
{
    string decrypt_stat;
    string decrypted_stat = "";
    cout << SYSTEM_COLOR << "Please enter your statement you want to decrypt:" << RESET_COLOR;
    getline(cin, decrypt_stat);
    string x = "";
    int counter = 0;
    // Iterate on the user input and replace every Morse Code to its character.
    for (char i : decrypt_stat)
    {
        if (i == ' ')
        {
            // if there are two spaces.
            if (x == "")
            {
                counter++;
                if (counter == 2)
                {
                    decrypted_stat += " "; // Space between words
                    counter = 0;
                }
                x = "";
            }
            else
            {
                decrypted_stat += reversed_Dic[x];
                x = "";
            }
        }
        // if the input is't a Morse Code.
        else if ((i != '-') && (i != '.'))
        {
            cout << SYSTEM_COLOR << "The statement is not a Morse Code.\nPlease choose a correct operation." << RESET_COLOR << endl;
            x = "";
            Morse_Code();
        }
        else
        {
            x += i;
        }
    }
    if (!x.empty())
    {
        decrypted_stat += reversed_Dic[x];
    }
    cout << SYSTEM_COLOR << "The decrypted statement is:" << decrypted_stat << RESET_COLOR;
    cont();
    return 0;
}
string get_string(string message = "")
{
    string word;
    cout << SYSTEM_COLOR << message << RESET_COLOR;
    getline(cin, word);
    while (cin.fail())
    {
        cout << RED << "Invalid Input! Please, follow the instructions\n"
             << RESET_COLOR;
        cin.clear();
        getline(cin, word);
    }
    return word;
}

string remove_spaces_chars(string input)
{
    string result;
    for (char c : input)
    {
        if (isalpha(c))
        {
            result += c;
        }
    }
    return result;
}

// Encrypts a message using Rail Fence cipher with a specified key
string Rail_fence(string message, int key)
{
    // Remove spaces and non-alphabetic characters from the message
    message = remove_spaces_chars(message);
    string cyphered_message = "";

    // Encrypt based on the chosen key
    if (key == 3)
    {
        for (int i = 0; i < message.length(); i += 4)
        {
            cyphered_message += message[i];
        }
        for (int i = 1; i < message.length(); i += 2)
        {
            cyphered_message += message[i];
        }
        for (int i = 2; i < message.length(); i += 4)
        {
            cyphered_message += message[i];
        }
    }
    else if (key == 4)
    {
        for (int i = 0; i < message.length(); i += 6)
        {
            cyphered_message += message[i];
        }
        for (int i = 1, j = 0; i < message.length(); j++)
        {
            cyphered_message += message[i];
            (j % 2 == 0) ? i += 4 : i += 2;
        }
        for (int i = 2, j = 0; i < message.length(); j++)
        {
            cyphered_message += message[i];
            (j % 2 == 0) ? i += 2 : i += 4;
        }
        for (int i = 3; i < message.length(); i += 6)
        {
            cyphered_message += message[i];
        }
    }

    return cyphered_message;
}

// Decrypts a Rail Fence ciphered message with a specified key
string Rail_fence_decrypt(string cyphered_message, int key)
{
    // Initialize a string to store the decrypted message
    string decrypted_message(cyphered_message.length(), ' ');
    int index = 0;

    // Decrypt based on the chosen key
    if (key == 3)
    {
        for (int i = 0; i < cyphered_message.length(); i += 4)
        {
            decrypted_message[i] = cyphered_message[index++];
        }
        for (int i = 1; i < cyphered_message.length(); i += 2)
        {
            decrypted_message[i] = cyphered_message[index++];
        }
        for (int i = 2; i < cyphered_message.length(); i += 4)
        {
            decrypted_message[i] = cyphered_message[index++];
        }
    }
    else if (key == 4)
    {
        for (int i = 0; i < cyphered_message.length(); i += 6)
        {
            decrypted_message[i] = cyphered_message[index++];
        }
        for (int i = 1, j = 0; i < cyphered_message.length(); j++)
        {
            decrypted_message[i] = cyphered_message[index++];
            (j % 2 == 0) ? i += 4 : i += 2;
        }
        for (int i = 2, j = 0; i < cyphered_message.length(); j++)
        {
            decrypted_message[i] = cyphered_message[index++];
            (j % 2 == 0) ? i += 2 : i += 4;
        }
        for (int i = 3; i < cyphered_message.length(); i += 6)
        {
            decrypted_message[i] = cyphered_message[index++];
        }
    }

    return decrypted_message;
}

// Executes Rail Fence cipher operations
int Rail_fence_code()
{
    int choice;
    string text;
    int key;

    // Welcome message
    cout << SYSTEM_COLOR << "Welcome to my Rail-fence cipher\n"
         << RESET_COLOR;
    while (true)
    {
        // User prompt for encryption, decryption, or exit
        cout << SYSTEM_COLOR << "What do you want to do ?\n"
             << RESET_COLOR
             << "(1) Encrypt a message\n"
             << "(2) Decrypt a message\n"
             << "(3) Exit\n"
             << "Enter your choice:";
        choice = get_int();

        // Perform the chosen operation
        if (choice == 1)
        {
            text = get_string("Enter the message to encrypt:");
            key = get_int("Choose a key from 3 or 4 only:");
            cout << SYSTEM_COLOR << "The cyphered message is:" << Rail_fence(text, key) << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 2)
        {
            text = get_string("Enter the message to decrypt:");
            key = get_int("Choose a key from 3 or 4 only:");
            cout << SYSTEM_COLOR << "The decrypted message is:" << Rail_fence_decrypt(text, key) << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 3)
        {
            cout << SYSTEM_COLOR << "Thanks for using my cipher🥰\n"
                 << RESET_COLOR;
            break;
        }
        else
        {
            cout << RED << "Invalid choice, please follow the instructions\n"
                 << RESET_COLOR;
        }
    }

    return 0;
}

int Affine_Cipher()
{
    string SYSTEM_COLOR, RESET_COLOR;
    // welcome message ( welcome at our program if you want to cipher your message.)
    cout << SYSTEM_COLOR << "Welcome to my affine cipher to encrypt and decrypt your messages." << RESET_COLOR << endl;
    cout << SYSTEM_COLOR << "\nThis program to encrypt or decrypt your messages." << RESET_COLOR << endl;
    // string alphabet as uppercase
    string upp_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (true)
    {
        int choice;
        cout << SYSTEM_COLOR << "(1) Encrypt the message.\n(2) Decrypt the message\n(3) END: " << RESET_COLOR;
        cin >> choice;
        while (cin.fail() || (choice != 1 && choice != 2 && choice != 3))
        {
            cout << RED << "Invalid input! Please, Follow the instructions." << RESET_COLOR << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << SYSTEM_COLOR << "(1) Encrypt the message.\n(2) Decrypt the message\n(3) END: " << RESET_COLOR;
            cin >> choice;
        }
        // Encrypt the message.
        if (choice == 1)
        {
            // get the values of ( a , b ) show a message (you have to insert two keys)
            cout << SYSTEM_COLOR << "To encrypt your message you have to insert two keys." << RESET_COLOR << endl;
            int a, b;
            //+ (the first key has to be coprime with the length of the alphabet that it has to be less than or equal to 26 )
            cout << SYSTEM_COLOR << "Please, Enetr the first key (a): " << RESET_COLOR;
            cin >> a;
            while (cin.fail() || a <= 0)
            { // return 1,2,13,26
                cout << RED << "Invalid input! Please, Follow the instructions" << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Please, Enetr the first key (a): " << RESET_COLOR;
                cin >> a;
            }
            //+ ( the second key it has to be an integer number any integer number)
            cout << SYSTEM_COLOR << "Please, Enter the second key (b) which is any integer number: " << RESET_COLOR;
            cin >> b;
            while (cin.fail() || b <= 0)
            { // check if the second key can be a negative number
                cout << RED << "Invalid input! Please, Follow the instructions." << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Please, Enter the second key (b) which is any integer number: " << RESET_COLOR;
                cin >> b;
            }
            //(1)read string and then make it upper case
            string orgi_message;
            cout << SYSTEM_COLOR << "Please, Enter your message you want to encrypt: " << RESET_COLOR;
            cin.ignore();
            getline(cin, orgi_message);
            // make it uppercase.
            for (char &ch : orgi_message)
            {
                ch = toupper(ch);
            }
            //****Encryption**** e(x)=(ax+b) mod 26
            // e = (ax+b) and you will keep going on repeating this stage untill you find that the mod is less than 25
            int e, x, y;
            string encrypted_letter;
            // make an empty string like string2=""; to add the encrypted message to it again.
            encrypted_letter = "";
            //(2)loop untill the the end if the size. andyou can also use for each ( & var :)
            for (char &cha : orgi_message)
            { // try to get the index (x)
                //(4)encrypt=string[new_index]

                for (int i = 0; i <= 25; i++)
                {
                    if (upp_alpha[i] == cha)
                    {
                        x = i;
                        e = (a * x + b) % 26; // e(x) encryption number
                        while (e > 25)
                        {
                            e %= 26;
                        }
                        encrypted_letter += upp_alpha[e];
                    }
                }
            }
            cout << SYSTEM_COLOR << "The encrypted message is: " << encrypted_letter << RESET_COLOR << endl;
        }
        else if (choice == 2)
        {
            // get the values of ( a , b ) show a message (you have to insert two keys)
            cout << SYSTEM_COLOR << "To decrypt your message you have to insert three keys." << RESET_COLOR << endl;
            int a, b, c;
            //+ (the first key has to be coprime with the length of the alphabet that it has to be less than or equal to 26 )
            cout << SYSTEM_COLOR << "Please, Enetr the first key (a): " << RESET_COLOR;
            cin >> a;
            while (cin.fail() || a <= 0)
            { // return 1,2,13,26
                cout << RED << "Invalid input! Please, Follow the instructions" << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Please, Enetr the first key (a): " << RESET_COLOR;
                cin >> a;
            }
            //+ ( the second key it has to be an integer number any integer number)
            cout << SYSTEM_COLOR << "Please, Enter the second key (b) which is any integer number: " << RESET_COLOR;
            cin >> b;
            while (cin.fail() || b <= 0)
            { // check if the second key can be a negative number
                cout << RED << "Invalid input! Please, Follow the instructions." << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Please, Enter the second key (b) which is any integer number: " << RESET_COLOR;
                cin >> b;
            }

            cout << SYSTEM_COLOR << "Please, Enter the key (c): " << RESET_COLOR;
            cin >> c;
            while (cin.fail() || ((c * a) % 26) != 1 || c <= 0)
            { // check if the second key can be a negative number
                cout << RED << "Invalid input! Please, Follow the instructions." << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Please, Enter the third key (c): " << RESET_COLOR;
                cin >> c;
            }
            //(1)read string and then make it upper case
            string orgi_message;
            cout << SYSTEM_COLOR << "Please, Enter your message you want to decrypt: " << RESET_COLOR;
            cin.ignore();
            getline(cin, orgi_message);
            // make it uppercase.
            for (char &ch : orgi_message)
            {
                ch = toupper(ch);
            }
            // decipher the message c*(y-b) mod 26
            int e, x, y;
            int d;
            string deciphered_message;
            deciphered_message = "";
            //(2)loop untill the the end if the size. andyou can also use for each ( & var :)
            for (char &cha : orgi_message)
            { // try to get the index (x)
                //(4)encrypt=string[new_index]
                for (int i = 0; i <= 25; i++)
                {
                    if (upp_alpha[i] == cha)
                    {
                        y = i;
                        d = c * (y - b) % 26; // e(x) encryption number
                        while (d > 25)
                        {
                            d %= 26;
                        }
                        if (d < 0)
                        {
                            d += 26;
                        }
                        deciphered_message += upp_alpha[d];
                    }
                }
            }
            cout << SYSTEM_COLOR << "The decrypted message is: " << deciphered_message << RESET_COLOR << endl;
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            cout << RED << "Invalid input! PLease, Follow the instructions." << RESET_COLOR << endl;
        }
        cout << "\n=========================================" << endl;
    }

    return 0;
}

string Decrypt_Vignere(string key, string message)
{
    string decrypted_message;
    for (int i = 0; i < message.size(); i++)
    {
        if (isalpha(message[i]))
        {
            int value = ((message[i] - key[i]) + 26) % 26;
            decrypted_message += (value + 'A');
        }
        else
        {
            decrypted_message += message[i];
        }
    }
    return decrypted_message;
}

string Encrypt_Vignere(string key, string message)
{
    string cyphered_message;
    for (int i = 0; i < message.size(); i++)
    {
        if (isalpha(message[i]))
        {
            int value = ((message[i] + key[i]) - 2 * 'A') % 26;
            cyphered_message += (value + 'A');
        }
        else
        {
            cyphered_message += message[i];
        }
    }
    return cyphered_message;
}

void Vignere()
{
    int choice;
    string message, output_message, key;
    cout << SYSTEM_COLOR << "***Welcome to Vigenere Cipher ***\nWhat do you want to do?\n"
         << RESET_COLOR;
    while (true)
    {
        cout << SYSTEM_COLOR << "(1) Encrypt a message\n"
             << "(2) Decrypt a message\n"
             << "(3) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice:");
        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << RED << "Invalid choice! Please, follow the instructions\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "What do you want to do?\n"
                 << "(1) Encrypt a message\n"
                 << "(2) Decrypt a message\n"
                 << "(3) Exit\n"
                 << RESET_COLOR;
            choice = get_int("Enter your choice:");
        }

        if (choice == 1)
        {
            message = get_string("enter the message:");
            cout << RED << "Note that key must have only alphabet letters any other characters will be removed\n"
                 << RESET_COLOR;
            key = get_string("enter the key:");
            key = remove_spaces_chars(key);
            while (key == "")
            {
                cout << RED << "Invalid key, please follow the instructions\n"
                     << RESET_COLOR;
                key = get_string("enter the key:");
                key = remove_spaces_chars(key);
            }
            for (char &c : message)
            {
                c = toupper(c);
            }
            for (char &c : key)
            {
                c = toupper(c);
            }
            for (int i = 0; i < message.size(); i += key.size())
            {
                if (message.size() > key.size())
                {
                    key += key;
                }
            }
            output_message = Encrypt_Vignere(key, message);
            cout << SYSTEM_COLOR << "The encrypted message : " << output_message << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 2)
        {
            message = get_string("enter the message:");
            cout << RED << "Note that key must have only alphabet letters any other characters will be removed\n"
                 << RESET_COLOR;
            key = get_string("enter the key:");
            key = remove_spaces_chars(key);
            while (key == "")
            {
                cout << RED << "Invalid key, please follow the instructions\n"
                     << RESET_COLOR;
                key = get_string("enter the key:");
                key = remove_spaces_chars(key);
            }
            for (char &c : message)
            {
                c = toupper(c);
            }
            for (char &c : key)
            {
                c = toupper(c);
            }
            for (int i = 0; i < message.size(); i += key.size())
            {
                if (message.size() > key.size())
                {
                    key += key;
                }
            }
            output_message = Decrypt_Vignere(key, message);
            cout << SYSTEM_COLOR << "The decrypted message : " << output_message << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 3)
        {
            break;
        }
    }
}
string Decrypt_Baconian(string message) {
    string decrypted_message;

    for (char &c : message) {
        if (c == 'a') {
            c = '0';
        } else if (c == 'b') {
            c = '1';
        }
    }
    for (int i = 0; i < message.size() - 4; i += 5) {
        while(message[i] == ' '){
            decrypted_message += ' ';
            i++;
        }
        int value = stoi(message.substr(i, 5), nullptr, 2);
        decrypted_message += char(value + 'A');
    }
    return decrypted_message;
}


string Encrypt_Baconian(string message) {
    string cyphered_message;
    for (char c : message)
    {
        bitset<5> binaryNumber(c-1);
        cyphered_message += binaryNumber.to_string();
    }
    for (char &c : cyphered_message )
    {
        if(c == '0')
        {
            c = 'a';
        }
        else if(c == '1')
        {
            c = 'b';
        }
    }
    return cyphered_message;
}

void Baconian() {
    int choice;
    string message, output_message, key;
    cout << SYSTEM_COLOR << "***Welcome to Baconian Cipher ***\nWhat do you want to do?\n" << RESET_COLOR;
    while (true) {
        cout << SYSTEM_COLOR << "(1) Encrypt a message\n"
             << "(2) Decrypt a message\n"
             << "(3) Exit\n" << RESET_COLOR;
        choice = get_int("Enter your choice:");
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << RED << "Invalid choice! Please, follow the instructions\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "What do you want to do?\n"
                 << "(1) Encrypt a message\n"
                 << "(2) Decrypt a message\n"
                 << "(3) Exit\n" << RESET_COLOR;
            choice = get_int("Enter your choice:");
        }

        if (choice == 1) {
            message = get_string("enter the message:");
            output_message = Encrypt_Baconian(message);
            cout << SYSTEM_COLOR << "The encrypted message :" << output_message << "\n" << RESET_COLOR;
        } else if (choice == 2) {
            message = get_string("enter the message:");
            output_message = Decrypt_Baconian(message);
            cout << SYSTEM_COLOR << "The decrypted message :" << output_message << "\n" << RESET_COLOR;
        } else if (choice == 3) {
            break;
        }
    }
}
int main()
{
    int choice;
    cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n"
         << RESET_COLOR;
    SYSTEM_COLOR = color();
    cout << "\n============\n";
    while (true)
    {
        cout << SYSTEM_COLOR << "1) Rail Cipher\n2) Morse Code\n3)Affine Cipher \n4) Vignere Cipher\n5)Baconian Cipher\n6) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice: ");
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
            cout << RED << "Invalid input! PLease, Follow the instructions.\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "1) Rail Cipher\n2) Morse Code\n3)Affine Cipher \n4) Vignere Cipher\n5)Baconian Cipher\n6) Exit\n"
                 << RESET_COLOR;
            choice = get_int("Enter your choice: ");
        }

        if (choice == 1)
        {
            Rail_fence_code();
        }
        else if (choice == 2)
        {
            Morse_Code();
        }
        else if (choice == 3)
        {
            Affine_Cipher();
        }
        else if (choice == 4)
        {
            Vignere();
        }
        else if (choice == 5)
        {
            Baconian();
        }
        else if (choice == 6)
        {
            cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
            break;
        }
        else
        {
            cout << RED << "Invalid choice, please follow the instructions\n"
                 << RESET_COLOR;
        }
    }

    return 0;
}
