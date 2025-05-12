#include <iostream>
using namespace std;

int main(){
    int num = 27;
    bool isPrime = true;
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            isPrime = false;
            break;
        }
    }
    if(isPrime){
        cout << num << " is a prime number." << endl;
    } else{
        cout << num << " is not a prime number." << endl;
    }
    return 0;
}