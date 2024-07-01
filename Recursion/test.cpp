#include <iostream>
using namespace std;
int x = 1;

void fun(int n){
    if(x == n){
        cout << x << " ";
        return;
    }
    cout << x << " ";
    x++;
    fun(n-1);
}

int main(){
    fun(5);
}