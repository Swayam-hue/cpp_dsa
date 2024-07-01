#include <iostream>
using namespace std;
int sum = 0;

int SumofDigits(int n){
    if (n == 0)
        return 0;
    return (n%10) + SumofDigits(n/10);
}

int main(){
    int ans = SumofDigits(1342);
    cout << ans;
}