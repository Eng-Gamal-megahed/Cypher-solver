
#include <iostream>
using namespace std;
// 2D array of alphabetic letters.
char table [5][5] = {{'A','B','C','D','E'},
                     {'F','G','H','I','K'},
                     {'L','M','N','O','P'},
                     {'Q','R','S','T','U'},
                     {'V','W','X','Y','Z'}};
// prototypes.
int encode();
int decode();
// function to make sure if the input is integers only.
bool checker_num(string num, int range ) {
        // not in range if the key especially is not 5 digits.
        if (range != num.size() ){
            return false;
        }
        // if there are unwanted wrong characters.
        for (int i = 0; i <= num.size()-1; i++) {
            if (!isdigit(num[i])) {
                return false;
            }
        }
        return true;
}
// function to make sure if the input is alphabetic letters only.
bool alpha_checker(string message){
    // if there are unwanted wrong characters.
    for (char character : message){
        if (!isalpha(character) && character != ' ' ){
            return false;
        }
    }
    return true;
}

int main(){
    string choice;
    // Welcoming statement.
    cout << "Welcome to \"Polybius Square Cipher\" \n" ;
    while (true) {
        // Take from the user the operation that s/he wants.
        cout << "\nWhich operation do you want to do : \nA) Encrypt \nB) Decrypt\nC) Exit\n" ;
        getline(cin, choice);
        if (choice == "a" or choice == "A") {
            encode();
        } else if (choice == "b" or choice == "B") {
            decode();
        }else if (choice == "c" or choice == "C"){
            exit(0);
        }
        else { cout << "Please, enter a valid input." ; }
    }
}

int encode(){
    string encrypt_mes,key,encrypted_mes;

    cout << "Please enter the message you want to encrypt:";
    getline(cin, (encrypt_mes));

    // asks the user again if s/he entered an invalid input.
    while (!alpha_checker(encrypt_mes)) {
        cout << "invalid input the message should contain alphabetic characters only.\n";
        cout << "Please enter the message you want to encrypt:";
        getline(cin, encrypt_mes);
    }

    cout << "Please, enter the key of the encryption:";
    getline(cin,key);

    // asks the user again if s/he entered an invalid input.
    while (!checker_num(key,5)) {
        cout <<"Please, enter a valid input,\nthe key should contain integers only with range of 5:";
        getline(cin, key);
    }
    // compare the letters in the message with the key.
    for (char letter : encrypt_mes){
        // j and i in the same position.
        if (toupper(letter) == 'J' ){
            letter = 'I';
        }
        // using nested loops to convert and know the wanted indexes.
        for (int i = 0 ; i <= 4 ;i++ ){
            for (int j = 0 ; j <= 4 ;j++ ){

                 if ( toupper(letter) == table[i][j] ){
                    encrypted_mes += key[i];
                    encrypted_mes += key[j];

                }

            }

        }

    }
    cout << "The encrypted message is:\n" << encrypted_mes;
    return 0;
}

int decode(){
    string decrypt_mes,key,decrypted_mes;
    int first_pos,second_pos  ;
    cout << "Please enter your message you want to decrypt:";
    getline(cin, (decrypt_mes));

    // asks the user again if s/he entered an invalid input.
    while (!checker_num(decrypt_mes,decrypt_mes.size())) {
        cout << "Please, enter a valid input,\nthe encrypted message should contain integers only:";
        getline(cin, decrypt_mes);
    }

    cout << "Please, enter the key of the decryption:";
    getline(cin,key);

    // asks the user again if s/he entered an invalid input.
    while (!checker_num(key,5)) {
        cout << "Please, enter a valid input,\nthe key should contain integers only with range of 5:";
        getline(cin, key);
    }
    // using the numbers of the key to know the index to use after equaling with the encrypted message.
    for (int index = 0; index <= decrypt_mes.size()-1;index+=2){
        for (int i = 0; i <= key.size()-1;i++){
            if (decrypt_mes[index] == key[i]){
                first_pos = i;
            }
            if (decrypt_mes[index+1] == key[i]){
                second_pos = i;
            }
        }
        decrypted_mes += table[first_pos][second_pos];
    }
    cout << "The decrypted message is:\n" << decrypted_mes;
    return 0;
}
