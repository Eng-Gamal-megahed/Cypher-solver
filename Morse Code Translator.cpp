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
        {'8',"---.."}  ,   {'9',"----."},
        {'+',".-.-."}  ,   {'=',"-...-"},
        {'/',"-..-."}  ,   {'.',".-.-.-"},
        {',',"--..--"} ,   {'?',"..--.."},
        {' '," "}
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
        {"-----", '0'} ,   {" ",' '},
        {".----",'1'}  ,   {"..---", '2'},
        {"...--",'3'}  ,   {"....-", '4'},
        {".....",'5'}  ,   {"-....", '6'},
        {"--...",'7'}  ,   {"---..", '8'},
        {"----.",'9'}  ,   {".-.-.",'+'},
        {"-...-",'='}  ,   {"-..-.",'/'},
        {".-.-.-",'.'} ,   {"--..--",','},
        {"..--..",'?'}
};
int encode ();
int decode ();
void cont ();
int Morse_Code() { //main
    string choice;
    // Welcoming statement.
    cout << SYSTEM_COLOR << "Morse Code Translator, which encrypts text to Morse code and decrypts Morse code to text.\n" << RESERT_COLOR;
    while (true) {
        // Take from the user the operation that s/he wants.
        cout << SYSTEM_COLOR << "Which operation do you want to do : \na) Encrypt \nb) Decrypt\n" << RESERT_COLOR;
        getline(cin, choice);
        if (choice == "a" or choice == "A") {
            encode();
            break;
        } else if (choice == "b" or choice == "B") {
            decode();
            break;
        } else { cout << SYSTEM_COLOR << "Please, enter a valid input: " <<  RESERT_COLOR << endl; }
    }
}

// cont function asks the user if he wants to continue or not.
void cont (){
    string cont_option;
    while (true) {
        cout << SYSTEM_COLOR << "\nDo you want to do another operation ?\na)YES\nb)NO" <<  RESERT_COLOR << endl;
        getline(cin, cont_option);
        if (cont_option == "a" or cont_option == "A") {
            // The program will start again.
            Morse_Code();
        } else if (cont_option == "b" or cont_option == "B") {
            // End program.
            exit(0);
        } else { cout << SYSTEM_COLOR << "Please, enter a valid input: " <<  RESERT_COLOR; }
    }
}
// encode function encrypts text to Morse code.
int encode() {
    string encrpt_stat;
    string encrypted_stat ;
    cout << SYSTEM_COLOR << "Any non-English letters or non-English numbers will be converted to a space." <<  RESERT_COLOR << endl;
    cout << SYSTEM_COLOR << "Please enter your statement you want to encrypt:" <<  RESERT_COLOR;
    getline(cin, (encrpt_stat));
    // Iterate on the user input and replace every character with its Morse Code.
    for (int i =0 ; i < encrpt_stat.size() ; i++){
        encrypted_stat.append(Dic[tolower(encrpt_stat[i]) ] + " ");
    }
    cout << SYSTEM_COLOR << "The encrypted statement is :" << endl << encrypted_stat <<  RESERT_COLOR;
    cont();
    return 0;
}
// decode function decrypts Morse code to text.
int decode() {
    string decrypt_stat;
    string decrypted_stat = "";
    cout << SYSTEM_COLOR << "Please enter your statement you want to decrypt:" <<  RESERT_COLOR;
    getline(cin, decrypt_stat);
    string x ="";
    int counter = 0;
    // Iterate on the user input and replace every Morse Code to its character.
    for (char i : decrypt_stat) {
        if (i == ' ') {
            // if there are two spaces.
            if (x == "") {
                if (counter == 2) {
                    decrypted_stat += " ";     // Space between words
                    counter = 0;
                }
                x = "";
            }
            else {
                decrypted_stat += reversed_Dic[x];
                x = "";
            }
        }
        // if the input is't a Morse Code.
        else if ((i != '-') && (i != '.')){
            cout << SYSTEM_COLOR << "The statement is not a Morse Code.\nPlease choose a correct operation." <<  RESERT_COLOR << endl;
            x = "";
            Morse_Code();
        }
        else {
            x += i;
        }
    }
    if (!x.empty()) {
        decrypted_stat += reversed_Dic[x];
    }
    cout << SYSTEM_COLOR << "The decrypted statement is:" << decrypted_stat <<  RESERT_COLOR;
    cont();
    return 0;
}

int main(){
    Morse_Code();
