#include <iostream>
using namespace std;
int R = 0;

int rev(int n){
    if (n == 0)
        return R;
    R = (R*10) + (n%10);
    return rev(n/10);
}

int main(){
    int ans = rev(1234);
    cout << ans;
}