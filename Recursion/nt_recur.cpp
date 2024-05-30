//A recursive function is said to be non-recursive if the recursive call is not the last thing done by the function. After returning back, there is something left to evaluate.
#include <iostream>
using namespace std;

void fun(int n){
    if (n == 0)
        return;
    else
        fun(n-1);
    cout << n << " ";
}

int main(){
    
    fun(3);
    return 0;
}