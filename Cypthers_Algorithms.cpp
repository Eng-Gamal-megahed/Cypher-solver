// File: CS112_A2_T4_S11,S12_20231167_20231039_20231200.cpp
// Purpose: a program that have a variety of encryption and decryption ways to be more secured when talking to someone.
// Author: Mostafa Ehab Mostafa Akl (20231167) (mostafaehabakl@gmail.com) , Section 12 , Did 6)Polybius Square Cipher , 7)Morse Code Cipher, 8)XOR Cipher.
//         Gamal Megahed Sayed Mohamed (20231039) (eng.gamalmegahed@gmail.com), Section 12 , Did 3)Vignere Cipher , 4)Baconian Cipher ,5)Simple Substitution Cipher , 9)Rail Fence Cipher.
//         Walid Adel Mordy Rohyem (20231200) (khattabadel112005@gmail.com), Section 11 , Did 0) Affine cipher , 1)Route Cipher , 2)Atbash Cipher.

#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <bitset>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <iomanip>
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

string removeMultipleChars(const string &str)
{
    unordered_set<char> seenChars;
    string result;

    for (char ch : str)
    {
        if (seenChars.find(ch) == seenChars.end())
        {
            result += ch;
            seenChars.insert(ch);
        }
    }

    return result;
}

void route_cipher()
{
    cout << SYSTEM_COLOR << "Welcome to my cipher (Route cipher)" << RESET_COLOR << endl;
    while (true)
    {
        // Input the message

        int chose;
        cout << SYSTEM_COLOR << "1) Encrypt the message.\n2) Decrypt the message.\n3) Exit: " << RESET_COLOR;
        cin >> chose;
        while (cin.fail() || (chose != 1 && chose != 2 && chose != 3))
        {
            cout << SYSTEM_COLOR << "Invalid input! PLease, Follow the instructions." << RESET_COLOR << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << SYSTEM_COLOR << "1) Encrypt the message.\n2) Decrypt the message.\n3) Exit: " << RESET_COLOR;
            cin >> chose;
        }
        if (chose == 1)
        {
            cout << SYSTEM_COLOR << "Please, Enter your message: " << RESET_COLOR;
            cin.ignore();
            string orgi_message;
            getline(cin, orgi_message);
            string orgi_message2 = "";
            for (char ch : orgi_message)
            {
                if (isalpha(ch))
                {
                    orgi_message2 += toupper(ch);
                }
            }
            // Handle the errors
            cout << SYSTEM_COLOR << "Enter your key number (The number has to be greater than zero): " << RESET_COLOR;
            // Input the key
            int key;
            cin >> key;
            while (cin.fail() || key <= 0)
            {
                cout << SYSTEM_COLOR << "Invalid input! Please, Follow the instructions." << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Enter your key number again (The number has to be greater than zero): " << RESET_COLOR;
                cin >> key;
            }
            int rrows;
            if (orgi_message.size() % key == 0)
            {
                rrows = orgi_message2.size() / key;
            }
            else
            {
                rrows = orgi_message2.size() / key + 1;
            }
            // Create the board
            const int rows = rrows;
            const int columns = key;
            char board[rows][columns];

            int ch_index = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int ii = 0; ii < columns; ii++)
                {
                    if (ch_index < orgi_message2.size())
                    {
                        board[i][ii] = orgi_message2[ch_index];
                        ch_index++;
                    }
                    else
                    {
                        board[i][ii] = 'X'; // Fill remaining space with spaces
                    }
                }
            }
            //===============================================================
            string result = ""; //* we have spaces
            int top = key - 1;
            int bottom = rrows - 1, left = 0, right = 0;
            while (left <= bottom && right <= top)
            {
                for (int i = left; i <= bottom; i++)
                {
                    result += board[i][top];
                }
                top -= 1;
                for (int ii = top; ii >= right; ii--)
                {
                    result += board[bottom][ii];
                }
                bottom -= 1;
                for (int iii = bottom; iii >= right; iii--)
                {
                    result += board[iii][left];
                }
                right += 1;
                for (int iiii = right; iiii <= top; iiii++)
                {
                    result += board[left][iiii];
                }
                left += 1;
            }
            cout << SYSTEM_COLOR << result << RESET_COLOR << endl;
            cin.ignore();
        }
        // decrypt the message
        else if (chose == 2)
        {
            cout << SYSTEM_COLOR << "Please, Enter your message: " << RESET_COLOR;
            cin.ignore();
            string orgi_message;
            getline(cin, orgi_message);
            string orgi_message2 = "";
            for (char ch : orgi_message)
            {
                if (isalpha(ch))
                {
                    orgi_message2 += toupper(ch);
                }
            }
            // Handle the errors
            cout << SYSTEM_COLOR << "Enter your key number (The number has to be greater than zero): " << RESET_COLOR;
            // Input the key
            int key;
            cin >> key;
            while (cin.fail() || key <= 0)
            {
                cout << SYSTEM_COLOR << "Invalid input! Please, Follow the instructions." << RESET_COLOR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << SYSTEM_COLOR << "Enter your key number again (The number has to be greater than zero): " << RESET_COLOR;
                cin >> key;
            }
            int rrows;
            if (orgi_message.size() % key == 0)
            {
                rrows = orgi_message2.size() / key;
            }
            else
            {
                rrows = orgi_message2.size() / key + 1;
            }
            // Create the board
            const int rows = rrows;
            const int columns = key;
            char board[rows][columns];

            int ch_index = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int ii = 0; ii < columns; ii++)
                {
                    if (ch_index < orgi_message2.size())
                    {
                        board[i][ii] = orgi_message2[ch_index];
                        ch_index++;
                    }
                    else
                    {
                        board[i][ii] = 'X'; // Fill remaining space with spaces
                    }
                }
            }
            // ========================================================
            int top = key - 1;
            int bottom = rrows - 1, left = 0, right = 0, k = 0;
            while (left <= bottom && right <= top)
            {
                for (int i = left; i <= bottom; i++)
                {
                    board[i][top] = orgi_message2[k];
                    k += 1;
                }
                top -= 1;
                for (int ii = top; ii >= right; ii--)
                {
                    board[bottom][ii] = orgi_message2[k];
                    k += 1;
                }
                bottom -= 1;
                for (int iii = bottom; iii >= right; iii--)
                {
                    board[iii][left] = orgi_message2[k];
                    k += 1;
                }
                right += 1;
                for (int iiii = right; iiii <= top; iiii++)
                {
                    board[left][iiii] = orgi_message2[k];
                    k += 1;
                }
                left += 1;
            }
            string result2 = "";
            for (int i = 0; i < rrows; i++)
            {
                for (int ii = 0; ii < key; ii++)
                {
                    if (board[i][ii] != 'X')
                        result2 += board[i][ii];
                }
            }
            cout << SYSTEM_COLOR << result2 << RESET_COLOR << endl;
            cin.ignore();
        }
        else
            break;
    }
}

//==============================================
void atbash_cipher()
{
    while (true)
    {
        // encryption or decryption
        int chose;
        cout << SYSTEM_COLOR << "1) Encrypt your message.\n2) Decrypt your message.\n3) Exit: " << RESET_COLOR;
        cin >> chose;
        // handling the errors
        while (cin.fail() || (chose != 1 && chose != 2 && chose != 3))
        {
            cout << SYSTEM_COLOR << "Invalid input! Please, Follow the instructions.<< RESET_COLOR" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << SYSTEM_COLOR << "1) Encrypt your message.\n2) Decrypt your message.\n3) Exit: " << RESET_COLOR;
            cin >> chose;
        }
        if (chose == 1 || chose == 2)
        {
            // use the postion of the alhabet to spicify the index.
            string upp_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            // Enter the message.
            cout << SYSTEM_COLOR << "Enter your message: " << RESET_COLOR;
            string orgi_message;
            cin.ignore();
            getline(cin, orgi_message);
            // make it uppercase
            for (char &ch : orgi_message)
            {
                ch = toupper(ch);
            }
            string encrypt_result = "";
            // start the encryption and the decryption and remeber they are the same.
            for (char ch : orgi_message)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (upp_alpha[i] == ch)
                    {
                        // 25 - index
                        encrypt_result += upp_alpha[25 - i];
                        break;
                    }
                }
            }
            cout << SYSTEM_COLOR << encrypt_result << RESET_COLOR << endl;
        }
        else
            break;
    }
}

//==============================

// A map to help convert text to morse code.
map<char, string> Dic = {
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'+', ".-.-."}, {'=', "-...-"}, {'/', "-..-."}, {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {' ', " "}};
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
        cout << SYSTEM_COLOR << "Which operation do you want to do : \na) Encrypt \nb) Decrypt\nC) Exit\n"
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
        else if (choice == "c" or choice == "C")
        {
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
    cout << SYSTEM_COLOR << "Please enter your statement you want to decrypt: " << RESET_COLOR;
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
string remove_chars(string input)
{
    string result;
    for (char c : input)
    {
        if (isalpha(c) || isspace(c))
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

// This function decrypts a message using Vigenere cipher
string Decrypt_Vignere(string key, string message)
{
    string decrypted_message;
    for (int i = 0; i < message.size(); i++)
    {
        if (isalpha(message[i]))
        {
            // Calculate the value for decryption
            int value = ((message[i] - key[i]) + 26) % 26;
            decrypted_message += (value + 'A');
        }
        else
        {
            decrypted_message += message[i]; // Preserve non-alphabetic characters
        }
    }
    return decrypted_message;
}

// This function encrypts a message using Vigenere cipher
string Encrypt_Vignere(string key, string message)
{
    string cyphered_message;
    for (int i = 0; i < message.size(); i++)
    {
        if (isalpha(message[i]))
        {
            // Calculate the value for encryption
            int value = ((message[i] + key[i]) - 2 * 'A') % 26;
            cyphered_message += (value + 'A');
        }
        else
        {
            cyphered_message += message[i]; // Preserve non-alphabetic characters
        }
    }
    return cyphered_message;
}

// This function provides a menu-driven interface for using Vigenere cipher
void Vignere()
{
    int choice;
    string message, output_message, key;
    cout << SYSTEM_COLOR << "***Welcome to Vigenere Cipher ***\nWhat do you want to do?\n"
         << RESET_COLOR;
    while (true)
    {
        // Display menu options and process user input
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
            // Get message and key for encryption
            message = get_string("enter the message:");
            cout << RED << "Note that key must have only alphabet letters any other characters will be removed\n"
                 << RESET_COLOR;
            key = get_string("enter the key:");
            key = remove_spaces_chars(key); // Remove spaces and non-alphabetic characters from the key
            while (key == "")
            {
                cout << RED << "Invalid key, please follow the instructions\n"
                     << RESET_COLOR;
                key = get_string("enter the key:");
                key = remove_spaces_chars(key);
            }
            // Convert message and key to uppercase
            for (char &c : message)
            {
                c = toupper(c);
            }
            for (char &c : key)
            {
                c = toupper(c);
            }
            // Ensure key is repeated to match the length of the message
            for (int i = 0; i < message.size(); i += key.size())
            {
                if (message.size() > key.size())
                {
                    key += key;
                }
            }
            // Encrypt the message and display the result
            output_message = Encrypt_Vignere(key, message);
            cout << SYSTEM_COLOR << "The encrypted message : " << output_message << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 2)
        {
            // Get message and key for decryption
            message = get_string("enter the message:");
            cout << RED << "Note that key must have only alphabet letters any other characters will be removed\n"
                 << RESET_COLOR;
            key = get_string("enter the key:");
            key = remove_spaces_chars(key); // Remove spaces and non-alphabetic characters from the key
            while (key == "")
            {
                cout << RED << "Invalid key, please follow the instructions\n"
                     << RESET_COLOR;
                key = get_string("enter the key:");
                key = remove_spaces_chars(key);
            }
            // Convert message and key to uppercase
            for (char &c : message)
            {
                c = toupper(c);
            }
            for (char &c : key)
            {
                c = toupper(c);
            }
            // Ensure key is repeated to match the length of the message
            for (int i = 0; i < message.size(); i += key.size())
            {
                if (message.size() > key.size())
                {
                    key += key;
                }
            }
            // Decrypt the message and display the result
            output_message = Decrypt_Vignere(key, message);
            cout << SYSTEM_COLOR << "The decrypted message : " << output_message << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 3)
        {
            break; // Exit the program
        }
    }
}

// This function decrypts a message encrypted using Baconian cipher
string Decrypt_Baconian(string message)
{
    string decrypted_message;

    // Convert 'a' to '0' and 'b' to '1' for binary conversion
    for (char &c : message)
    {
        if (c == 'a')
        {
            c = '0';
        }
        else if (c == 'b')
        {
            c = '1';
        }
    }

    // Extract 5-bit binary chunks and convert them back to characters
    for (int i = 0; i < message.size() - 4; i += 5)
    {
        // Handle spaces if present
        while (message[i] == ' ')
        {
            decrypted_message += ' ';
            i++;
        }
        // Convert binary to integer and then to corresponding character
        int value = stoi(message.substr(i, 5), nullptr, 2);
        decrypted_message += char(value + 'A');
    }
    return decrypted_message;
}

// This function encrypts a message using Baconian cipher
string Encrypt_Baconian(string message)
{
    string cyphered_message;
    // Convert characters to 5-bit binary representation
    for (char c : message)
    {
        bitset<5> binaryNumber(c - 1);                // Convert character to 5-bit binary
        cyphered_message += binaryNumber.to_string(); // Append binary representation to cyphered_message
    }
    // Replace '0' with 'a' and '1' with 'b'
    for (char &c : cyphered_message)
    {
        if (c == '0')
        {
            c = 'a';
        }
        else if (c == '1')
        {
            c = 'b';
        }
    }
    return cyphered_message;
}

// This function provides a menu-driven interface for using Baconian cipher
void Baconian()
{
    int choice;
    string message, output_message, key;
    cout << SYSTEM_COLOR << "***Welcome to Baconian Cipher ***\nWhat do you want to do?\n"
         << RESET_COLOR;
    while (true)
    {
        // Menu options
        cout << SYSTEM_COLOR << "(1) Encrypt a message\n"
             << "(2) Decrypt a message\n"
             << "(3) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice:");
        // Validate choice
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
            // Get message from user and encrypt it
            message = get_string("enter the message:");
            message = remove_chars(message);
            output_message = Encrypt_Baconian(message);
            cout << SYSTEM_COLOR << "The encrypted message :" << output_message << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 2)
        {
            // Get message from user and decrypt it
            message = get_string("enter the message:");
            message = remove_chars(message);
            output_message = Decrypt_Baconian(message);
            cout << SYSTEM_COLOR << "The decrypted message :" << output_message << "\n"
                 << RESET_COLOR;
        }
        else if (choice == 3)
        {
            // Exit the program
            break;
        }
    }
}

// This function finds the index of a character in an array
int get_index(char x, char array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == x)
            return i;
    }
    return -1; // If character not found, return -1
}

// This function decrypts a message using Simple Substitution cipher
string Decrypt_Simple_Substitution(string message, string key, char alphabets[])
{
    string decrypted_message;

    // Create a key for the substitution cipher
    char alphabets_key[26];
    int index = key.size();
    for (int i = 0; i < key.size(); ++i)
    {
        alphabets_key[i] = key[i];
    }
    // Populate remaining alphabets not present in the key
    for (int i = 0; i < 26; ++i)
    {
        if (find(alphabets_key, alphabets_key + key.size(), alphabets[i]) == alphabets_key + key.size())
        {
            alphabets_key[index] = alphabets[i];
            index++;
        }
    }
    // Decrypt each character in the message
    for (char c : message)
    {
        if (c == ' ')
        {
            decrypted_message += c;
            continue;
        }
        decrypted_message += alphabets[get_index(c, alphabets_key, 26)];
    }
    return decrypted_message;
}

// This function encrypts a message using Simple Substitution cipher
string Encrypt_Simple_Substitution(string message, string key, char alphabets[])
{
    string cyphered_message;
    // Create a key for the substitution cipher
    char alphabets_key[26];
    int index = key.size();
    for (int i = 0; i < key.size(); ++i)
    {
        alphabets_key[i] = key[i];
    }
    // Populate remaining alphabets not present in the key
    for (int i = 0; i < 26; ++i)
    {
        if (find(alphabets_key, alphabets_key + key.size(), alphabets[i]) == alphabets_key + key.size())
        {
            alphabets_key[index] = alphabets[i];
            index++;
        }
    }
    // Encrypt each character in the message
    for (char c : message)
    {
        if (c == ' ')
        {
            cyphered_message += c;
            continue;
        }
        cyphered_message += alphabets_key[get_index(c, alphabets, 26)];
    }
    return cyphered_message;
}

// This function provides a menu-driven interface for using Simple Substitution cipher
void Simple_Substitution()
{
    int choice;
    string message, output_message, key;
    char alphabets[26];

    // Initialize the array of alphabets
    for (int i = 0; i < 26; ++i)
    {
        alphabets[i] = 'a' + i;
    }

    // Display menu and process user input
    cout << SYSTEM_COLOR << "***Welcome to Simple Substitution Cipher ***\nWhat do you want to do?\n"
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
            // Get user input for encryption
            message = get_string("enter the message:");
            for (char &c : message)
            {
                c = tolower(c);
            }
            key = get_string("enter the key:");
            for (char &c : key)
            {
                c = tolower(c);
            }
            key = removeMultipleChars(key);
            // Encrypt the message and display the result
            output_message = Encrypt_Simple_Substitution(message, key, alphabets);
            cout << "The encrypted message :" << output_message << "\n";
        }
        else if (choice == 2)
        {
            // Get user input for decryption
            message = get_string("enter the message:");
            for (char &c : message)
            {
                c = tolower(c);
            }
            key = get_string("enter the key:");
            for (char &c : key)
            {
                c = tolower(c);
            }
            key = removeMultipleChars(key);

            // Decrypt the message and display the result
            output_message = Decrypt_Simple_Substitution(message, key, alphabets);
            cout << "The decrypted message :" << output_message << "\n";
        }
        else if (choice == 3)
        {
            // Exit the program
            break;
        }
    }
}
//===============================================================================================================
// 2D array of alphabetic letters.
char table[5][5] = {{'A', 'B', 'C', 'D', 'E'},
                    {'F', 'G', 'H', 'I', 'K'},
                    {'L', 'M', 'N', 'O', 'P'},
                    {'Q', 'R', 'S', 'T', 'U'},
                    {'V', 'W', 'X', 'Y', 'Z'}};
// prototypes.
int encode_6();
int decode_6();
// function to make sure if the input is integers only.
bool checker_num(string num, int range)
{
    // not in range if the key especially is not 5 digits.
    if (range != num.size())
    {
        return false;
    }
    // if there are unwanted wrong characters.
    for (int i = 0; i <= num.size() - 1; i++)
    {
        if (!isdigit(num[i]))
        {
            return false;
        }
    }
    return true;
}
// function to make sure if the input is alphabetic letters only.
bool alpha_checker(string message)
{
    // if there are unwanted wrong characters.
    for (char character : message)
    {
        if (!isalpha(character) && character != ' ')
        {
            return false;
        }
    }
    return true;
}

int Polybius_Square()
{
    string choice;
    // Welcoming statement.
    cout << SYSTEM_COLOR << "Welcome to \"Polybius Square Cipher\" \n"
         << RESET_COLOR;
    while (true)
    {
        // Take from the user the operation that s/he wants.
        cout << SYSTEM_COLOR << "\nWhich operation do you want to do : \nA) Encrypt \nB) Decrypt\nC) Exit\n"
             << RESET_COLOR;
        getline(cin, choice);
        if (choice == "a" || choice == "A")
        {
            encode_6();
        }
        else if (choice == "b" || choice == "B")
        {
            decode_6();
        }
        else if (choice == "c" || choice == "C")
        {
            break;
        }
        else
        {
            cout << RED << "Please, enter a valid input." << RESET_COLOR;
        }
    }
    return 0;
}

int encode_6()
{
    string encrypt_mes, key, encrypted_mes;

    cout << SYSTEM_COLOR << "Please enter the message you want to encrypt:" << RESET_COLOR;
    getline(cin, (encrypt_mes));

    // asks the user again if s/he entered an invalid input.
    while (!alpha_checker(encrypt_mes))
    {
        cout << RED << "invalid input the message should contain alphabetic characters only.\n"
             << RESET_COLOR;
        cout << SYSTEM_COLOR << "Please enter the message you want to encrypt:" << RESET_COLOR;
        getline(cin, encrypt_mes);
    }

    cout << SYSTEM_COLOR << "Please, enter the key of the encryption:" << RESET_COLOR;
    getline(cin, key);

    // asks the user again if s/he entered an invalid input.
    while (!checker_num(key, 5))
    {
        cout << RED << "Please, enter a valid input,\nthe key should contain integers only with range of 5:" << RESET_COLOR;
        getline(cin, key);
    }
    // compare the letters in the message with the key.
    for (char letter : encrypt_mes)
    {
        // j and i in the same position.
        if (toupper(letter) == 'J')
        {
            letter = 'I';
        }
        // using nested loops to convert and know the wanted indexes.
        for (int i = 0; i <= 4; i++)
        {
            for (int j = 0; j <= 4; j++)
            {

                if (toupper(letter) == table[i][j])
                {
                    encrypted_mes += key[i];
                    encrypted_mes += key[j];
                }
            }
        }
    }
    cout << SYSTEM_COLOR << "The encrypted message is:\n"
         << encrypted_mes << RESET_COLOR;
    return 0;
}

int decode_6()
{
    string decrypt_mes, key, decrypted_mes;
    int first_pos, second_pos;
    cout << SYSTEM_COLOR << "Please enter your message you want to decrypt:" << RESET_COLOR;
    getline(cin, (decrypt_mes));

    // asks the user again if s/he entered an invalid input.
    while (!checker_num(decrypt_mes, decrypt_mes.size()))
    {
        cout << RED << "Please, enter a valid input,\nthe encrypted message should contain integers only:" << RESET_COLOR;
        getline(cin, decrypt_mes);
    }

    cout << SYSTEM_COLOR << "Please, enter the key of the decryption:" << RESET_COLOR;
    getline(cin, key);

    // asks the user again if s/he entered an invalid input.
    while (!checker_num(key, 5))
    {
        cout << RED << "Please, enter a valid input,\nthe key should contain integers only with range of 5:" << RESET_COLOR;
        getline(cin, key);
    }
    // using the numbers of the key to know the index to use after equaling with the encrypted message.
    for (int index = 0; index <= decrypt_mes.size() - 1; index += 2)
    {
        for (int i = 0; i <= key.size() - 1; i++)
        {
            if (decrypt_mes[index] == key[i])
            {
                first_pos = i;
            }
            if (decrypt_mes[index + 1] == key[i])
            {
                second_pos = i;
            }
        }
        decrypted_mes += table[first_pos][second_pos];
    }
    cout << SYSTEM_COLOR << "The decrypted message is:\n"
         << decrypted_mes << RESET_COLOR;
    return 0;
}
//=========================================================================================

string charToHex(char character)
{
    stringstream stream;
    stream << hex << setw(2) << setfill('0') << static_cast<int>(character);
    return stream.str();
}

// string to ASCII format string
string hexTochar(string hex)
{
    // initialize the character string as empty.
    string decrypted_mes_char = "";
    for (int i = 0; i < hex.length(); i += 2)
    {
        // extract two characters from hex string
        string part = hex.substr(i, 2);

        // change it into base 16 and typecast as the character
        char convert = char(stoul(part, nullptr, 16));

        // add this char to final string of characters.
        decrypted_mes_char += convert;
    }
    return decrypted_mes_char;
}
// prototypes
int decode_9();
int encode_9();

int XOR()
{
    string choice;
    // Welcoming statement.
    cout << SYSTEM_COLOR << "Welcome to \"XOR Cipher\" \n"
         << RESET_COLOR;
    while (true)
    {
        // Take from the user the operation that s/he wants.
        cout << SYSTEM_COLOR << "\nWhich operation do you want to do : \nA) Encrypt \nB) Decrypt\nC) Exit\n"
             << RESET_COLOR;
        cin >> choice;
        if (choice == "a" || choice == "A")
        {
            encode_9();
        }
        else if (choice == "b" || choice == "B")
        {
            decode_9();
        }
        else if (choice == "c" || choice == "C")
        {
            break;
        }
        else
        {
            cout << RED << "Please, enter a valid input." << RESET_COLOR;
        }
    }
    return 0;
}
int encode_9()
{
    string encrypt_mes, encrypted_mes, hex_mes;
    char key;
    cout << SYSTEM_COLOR << "Please enter the message you want to encrypt:" << RESET_COLOR;
    cin.ignore();
    getline(cin, (encrypt_mes));
    cout << SYSTEM_COLOR << "Please, enter the key of the encryption:" << RESET_COLOR;
    cin >> key;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // XOR operation on every bit in every character in the message.
    for (char letter : encrypt_mes)
    {
        encrypted_mes += letter ^ key;
    }
    cout << SYSTEM_COLOR << "\nThe encrypted message with characters is:\n"
         << encrypted_mes << RESET_COLOR << endl;
    // to convert the encrypted message to hexadecimal.
    for (char character : encrypted_mes)
    {
        hex_mes += charToHex(character);
    }
    cout << SYSTEM_COLOR << "The encrypted message with hexadecimal value is:\n"
         << hex_mes << RESET_COLOR << endl;
    return 0;
}

int decode_9()
{
    string choice, decrypt_mes, decrypted_mes, hex_mes;
    char key;
    while (true)
    {
        // Take from the user the kind of value that s/he wants.
        cout << SYSTEM_COLOR << "\nWhat kind of message you want to decrypt : \nA) Characters \nB) Hexadecimal\n"
             << RESET_COLOR;
        cin >> choice;
        if (choice == "a" || choice == "A")
        {
            cout << SYSTEM_COLOR << "Please enter the message you want to decrypt:" << RESET_COLOR;
            cin.ignore();
            getline(cin, (decrypt_mes));
            break;
        }
        else if (choice == "b" || choice == "B")
        {
            cout << SYSTEM_COLOR << "Please enter the message you want to decrypt:" << RESET_COLOR;
            cin.ignore();
            getline(cin, (hex_mes));
            // covert the hexadecimal value to characters.
            decrypt_mes = hexTochar(hex_mes);
            break;
        }
        else
        {
            cout << SYSTEM_COLOR << "Please, enter a valid input." << RESET_COLOR;
        }
    }
    cout << SYSTEM_COLOR << "Please, enter the key of the encryption:" << RESET_COLOR;
    cin >> key;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // XOR operation on every bit in every character in the message.
    for (char letter : decrypt_mes)
    {
        decrypted_mes += letter ^ key;
    }
    cout << SYSTEM_COLOR << "\nThe encrypted message with characters is:" << decrypted_mes << RESET_COLOR << endl;
    return 0;
}
//==========================================================================================
int main()
{
    int choice;
    cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n"
         << RESET_COLOR;
    SYSTEM_COLOR = color();
    cout << "\n============\n";
    while (true)
    {
        cout << SYSTEM_COLOR << "Which cipher do you want?\n0) Affine Cipher.\n1) Route Cipher.\n2) Atbash Cipher.\n3) Vignere Cipher.\n4) Baconian Cipher.\n5) Simple Substitution.\n6) Polybius Square Cipher.\n7) Morse Code.\n8) XOR Cipher.\n9) Rail-fence Cipher.\n10) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice: ");
        while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10)
        {
            cout << RED << "Invalid input! PLease, Follow the instructions.\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "Which cipher do you want?\n0) Affine Cipher.\n1)Route Cipher.\n2)Atbash Cipher.\n3) Vignere Cipher.\n4) Baconian Cipher.\n5)Simple Substitution.\n6)Polybius Square Cipher.\n7) Morse Code.\n8) XOR Cipher.\n9) Rail-fence Cipher.\n10) Exit\n"
                 << RESET_COLOR;
            choice = get_int("Enter your choice: ");
        }

        if (choice == 0)
        {
            Affine_Cipher();
        }
        else if (choice == 1)
        {
            route_cipher();
        }
        else if (choice == 2)
        {
            atbash_cipher();
        }
        else if (choice == 3)
        {
            Vignere();
        }
        else if (choice == 4)
        {
            Baconian();
        }
        else if (choice == 5)
        {
            Simple_Substitution();
        }
        else if (choice == 6)
        {
            Polybius_Square();
        }
        else if (choice == 7)
        {
            Morse_Code();
        }
        else if (choice == 8)
        {
            XOR();
        }
        else if (choice == 9)
            Rail_fence_code();
        else if (choice == 10)
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