//
// Created by Gamal on 3/17/2024.
//
#include <iostream>
#include <string>
#include <limits>
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

string Decrypt_Vignere(string key, string message) {
    string decrypted_message;
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i])) {
            int value = ((message[i] - key[i]) + 26) % 26;
            decrypted_message += (value + 'A');
        } else {
            decrypted_message += message[i];
        }
    }
    return decrypted_message;
}

string get_string(string message = "")
{
    string word;
    cout << BOLD << message << RESET_COLOR;
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

string Encrypt_Vignere(string key, string message) {
    string cyphered_message;
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i])) {
            int value = ((message[i] + key[i]) - 2 * 'A') % 26;
            cyphered_message += (value + 'A');
        } else {
            cyphered_message += message[i];
        }
    }
    return cyphered_message;
}

void Vignere() {
    int choice;
    string message, output_message, key;
    cout << SYSTEM_COLOR << "***Welcome to Vigenere Cipher ***\nWhat do you want to do?\n" << RESET_COLOR;
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
            key = get_string("enter the key");
            for (char &c : message) {
                c = toupper(c);
            }
            for (char &c : key) {
                c = toupper(c);
            }
            for (int i = 0; i < message.size(); i += key.size()) {
                if (message.size() > key.size()) {
                    key += key;
                }
            }
            output_message = Encrypt_Vignere(key, message);
            cout << SYSTEM_COLOR << "The encrypted message : " << output_message << "\n" << RESET_COLOR;
        } else if (choice == 2) {
            message = get_string("enter the message:");
            key = get_string("enter the key");
            for (char &c : message) {
                c = toupper(c);
            }
            for (char &c : key) {
                c = toupper(c);
            }
            for (int i = 0; i < message.size(); i += key.size()) {
                if (message.size() > key.size()) {
                    key += key;
                }
            }
            output_message = Decrypt_Vignere(key, message);
            cout << SYSTEM_COLOR << "The decrypted message : " << output_message << "\n" << RESET_COLOR;
        } else if (choice == 3) {
            break;
        }
    }
}
int main()
{
    Vignere();
}