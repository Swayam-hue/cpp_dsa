#include <iostream>
using namespace std;
int sum = 0;

int POD(int n){
    if (n == 0)
        return 1;
    return (n%10) * POD(n/10);
}

int main(){
    int ans = POD(134);
    cout << ans;
}