#include <iostream>
using namespace std;

int main() {
    // char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    // char ch[] = "hello";
    // cout << ch << endl; // prints the string


    char str[6];
    cout << "Enter a string: ";
    
    cin.getline(str, 6, '$'); // to read a string with spaces
    // cin >> str;

    for(char c: str) {
        cout << c << " ";
    }
    cout << "You entered: " << str << endl;
    cout << "Length of string: " << strlen(str) << endl;
    cout << "First character: " << str[0] << endl;
    cout << "Last character: " << str[strlen(str)-1] << endl;
   
    return 0;
}