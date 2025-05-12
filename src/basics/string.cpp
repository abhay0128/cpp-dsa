#include <iostream>
#include <string>
using namespace std;

int main() {

    string str = "cppmaster";  //dynamic-> resize at runtime while char array is static

    reverse(str.begin(), str.end());
    // getline(cin, str); // to read a string with spaces
    cout << str << endl;
    str= "dsamster";
    cout << str << endl;
    return 0;
}