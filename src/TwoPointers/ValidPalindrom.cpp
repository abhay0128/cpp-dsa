#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int left = 0, right = s.size() - 1;
    bool isPalindrome = true;

    while (left < right) {
        while(left < right && !isalnum(s[left])) {
            left++;
        }
        while(left < right && !isalnum(s[right])) {
            right--;
        }
        if (s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}