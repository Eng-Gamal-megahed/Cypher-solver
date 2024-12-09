
#include <iostream>
#include <string>
#include <limits>
#include <bitset>
#include <algorithm>
using namespace std;

string SYSTEM_COLOR = "\033[0m";
string RESET_COLOR = "\033[0m";
string BOLD = "\033[1;37m";
string RED = "\033[1;31m";
string BLUE = "\033[1;34m";
string YELLOW = "\033[1;33m";
string WHITE = "\033[1;37m";
string BLACK = "\033[1;30m";
string GREEN = "\033[1;32m";
string CYAN = "\033[1;36m";
string PURPLE = "\033[1;35m";
string BG_BLACK = "\033[40m";
string BG_WHITE = "\033[47m";

int get_int(string message = "")
{
    int num = 0;
    cout << BOLD << message << RESET_COLOR;
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
    while (color != 1 && color !=2 && color != 3 && color != 4 && color != 5 && color != 6 )
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
    else if (color == 6)
        player_color = PURPLE;
    return player_color;
}
string removeSpaces(string input)
{
    string result;
    for (char c : input)
    {
        if (c != ' ')
        {
            result += c;
        }
    }
    return result;
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
int get_index(char x, char array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == x)
            return i;
    }
    return -1;
}

string Decrypt_Simple_Substitution(string message , string key , char alphabets[]) {
    string decrypted_message;

    char alphabets_key[26];
    int index = key.size();
    for (int i = 0; i < key.size(); ++i) {
        alphabets_key[i] = key[i];
    }
    for (int i = 0; i < 26; ++i) {
        if(find(alphabets_key , alphabets_key + key.size() , alphabets[i]) == alphabets_key + key.size())
        {
            alphabets_key[index] = alphabets[i];
            index++;
        }
    }
    for(char c : message)
    {
        if(c == ' ')
        {
            decrypted_message += c;
            continue;
        }
        decrypted_message += alphabets[get_index(c , alphabets_key , 26)];
    }
    return decrypted_message;
}

string Encrypt_Simple_Substitution(string message , string key , char alphabets[]) {
    string cyphered_message;
    char alphabets_key[26];
    int index = key.size();
    for (int i = 0; i < key.size(); ++i) {
        alphabets_key[i] = key[i];
    }
    for (int i = 0; i < 26; ++i) {
        if(find(alphabets_key , alphabets_key + key.size() , alphabets[i]) == alphabets_key + key.size())
        {
            alphabets_key[index] = alphabets[i];
            index++;
        }
    }
    for(char c : message)
    {
        if(c == ' ')
        {
            cyphered_message += c;
            continue;
        }
        cyphered_message += alphabets_key[get_index(c , alphabets , 26)];
    }
    return cyphered_message;
}


void Simple_Substitution() {
    int choice;
    string message, output_message, key;
    char alphabets[26];

    for (int i = 0; i < 26; ++i) {
        alphabets[i] = 'a' + i;
    }


    cout << SYSTEM_COLOR << "***Welcome to Simple Substitution Cipher ***\nWhat do you want to do?\n" << RESET_COLOR;
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
            for (char &c : message )
            {
                c = tolower(c);
            }
            key = get_string("enter the key:");
            for (char &c : key )
            {
                c = tolower(c);
            }
            output_message = Encrypt_Simple_Substitution(message , key , alphabets);
            cout << "The encrypted message :" << output_message << "\n";
        } else if (choice == 2) {
            message = get_string("enter the message:");
            for (char &c : message )
            {
                c = tolower(c);
            }
            key = get_string("enter the key:");
            for (char &c : key )
            {
                c = tolower(c);
            }
            output_message = Decrypt_Simple_Substitution(message , key , alphabets);
            cout << "The decrypted message :" << output_message << "\n";
        } else if (choice == 3) {
            break;
        }
    }
}
int main()
{
    char alphabets[26];

    for (int i = 0; i < 26; ++i) {
        alphabets[i] = 'a' + i;
    }
    Simple_Substitution();
}