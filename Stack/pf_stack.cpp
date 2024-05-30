#include <iostream>
using namespace std;

bool isPrime(int n){
    int c = 0;
    for(int i = 1; i<=n; i++){
        if (n%i==0)
            c++;
    }
    if (c==2)
        return true;
    else
        return false;
}


int main(){
    cout << "Enter the number whose prime factors are to be obtained : \n";
    int n;
    cin >> n;
    int stack_arr[n], first = -1;
    for (int i = 1; i<n; i++){
        if ((n%i == 0) && isPrime(i)==true){
            first += 1;
            stack_arr[first] = i;
        }
    }

    for (int i = 0; i<=first; i++){
        for (int j = 0; j<=first - i - 1; j++){
            if (stack_arr[j] < stack_arr[j+1]){ //bubble sorting in descending order
                int temp = stack_arr[j];
                stack_arr[j] = stack_arr[j+1];
                stack_arr[j+1] = temp;
            }
        }
    }

    cout << "The prime factors of the number " << n << " in descending order are : \n";
    for(int i = 0; i<=first; i++){
        if(stack_arr[i] != stack_arr[i+1])
            cout << stack_arr[i] << " ";
        else
            continue;
    }
}