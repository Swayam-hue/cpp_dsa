#include <iostream>
using namespace std;

int fac (int n){
    if (n == 1)
        return 1;
    else
        return n*fac(n-1);
}

int main(){
    int n;
    cout << "Enter the number : \n";
    cin >> n;
    cout << "The factorial of " << n << " is " << fac(n);
}