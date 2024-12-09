
#include <iomanip> // for setw and setfill
#include <sstream> // for stringstream
#include <iostream>
using namespace std;

string charToHex(char character) {
    stringstream stream;
    stream << hex << setw(2) << setfill('0') << static_cast<int>(character);
    return stream.str();
}

// string to ASCII format string
string hexTochar(string hex){
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
int decode();
int encode();

int main(){
    string choice;
    // Welcoming statement.
    cout << "Welcome to \"XOR Cipher\" \n" ;
    while (true) {
        // Take from the user the operation that s/he wants.
        cout << "\nWhich operation do you want to do : \nA) Encrypt \nB) Decrypt\nC) Exit\n" ;
        cin >> choice;
        if (choice == "a" or choice == "A") {
            encode();
        } else if (choice == "b" or choice == "B") {
            decode();
        }else if (choice == "c" or choice == "C"){
            exit(0);
        }
        else { cout << "Please, enter a valid input."; }
    }
}
int encode (){
    string encrypt_mes,encrypted_mes,hex_mes;
    char key;
    cout << "Please enter the message you want to encrypt:";
    cin.ignore();
    getline(cin, (encrypt_mes));
    cout << "Please, enter the key of the encryption:";
    cin >> key;
    // XOR operation on every bit in every character in the message.
    for (char letter : encrypt_mes){
        encrypted_mes += letter ^ key;
    }
    cout <<"\nThe encrypted message with characters is:\n" << encrypted_mes << endl;
    // to convert the encrypted message to hexadecimal.
    for (char character : encrypted_mes){
        hex_mes += charToHex(character);
    }
    cout << "The encrypted message with hexadecimal value is:\n" << hex_mes << endl;
    return 0;
}

int decode(){
    string choice,decrypt_mes,decrypted_mes,hex_mes;
    char key;
    while (true) {
        // Take from the user the kind of value that s/he wants.
        cout << "\nWhat kind of message you want to decrypt : \nA) Characters \nB) Hexadecimal\n" ;
        cin >> choice;
        if (choice == "a" or choice == "A") {
            cout << "Please enter the message you want to decrypt:";
            cin.ignore();
            getline(cin, (decrypt_mes));
            break;
        } else if (choice == "b" or choice == "B") {
            cout << "Please enter the message you want to decrypt:";
            cin.ignore();
            getline(cin, (hex_mes));
            // covert the hexadecimal value to characters.
            decrypt_mes = hexTochar(hex_mes);
            break;
        }else { cout << "Please, enter a valid input."; }
    }
    cout << "Please, enter the key of the encryption:";
    cin >> key;
    // XOR operation on every bit in every character in the message.
    for (char letter : decrypt_mes){
        decrypted_mes += letter ^ key;
    }
    cout << "\nThe encrypted message with characters is:" << decrypted_mes << endl;
    return 0;
}