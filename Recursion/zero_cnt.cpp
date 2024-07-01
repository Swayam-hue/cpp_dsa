#include <iostream>
using namespace std;
int c = 0;

int zero_cnt(int n){
    if (n == 0)
        return c;
    if(n%10 == 0)
        c++;
    return zero_cnt(n/10);
}

int main(){
    int ans = zero_cnt(1020030);
    cout << ans;
}