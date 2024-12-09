#include <iostream>
#include <string>
#include <limits>
using namespace std;

string SYSTEM_COLOR = "";
string RESET_COLOR = "";
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
    while (cin.fail() || (num != 3 && num != 4))
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

string Rail_fence(string message, int key)
{
    message = removeSpaces(message);
    string cyphered_message = "";
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
        return cyphered_message;
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
string Rail_fence_decrypt(string cyphered_message, int key)
{
    string decrypted_message(cyphered_message.length(), ' ');
    int index = 0;

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

int main()
{
    char choice;
    string text;
    int key;
    cout << BOLD << "Welcome to my Rail-fence cipher\n";
    while (true)
    {

        cout << BOLD << "What do you want to do ?\n"
             << "(1) Encrypt a message\n"
             << "(2) Decrypt a message\n"
             << "(3) Exit\n"
             << "Enter your choice:";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == '1')
        {
            text = get_string("Enter the message to encrypt:");
            key = get_int("Chose a key from 3 or 4 only:");
            cout << "The cyphered message is:" << Rail_fence(text, key) << "\n";
        }
        else if (choice == '2')
        {
            text = get_string("Enter the message to decrypt:");
            key = get_int("Chose a key from 3 or 4 only:");
            cout << "The decrypted message is:" << Rail_fence_decrypt(text, key) << "\n";
        }
        else if (choice == '3')
        {
            cout << "Thanks to use my cypher🥰";
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