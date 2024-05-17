#include <iostream>
using namespace std;
int first = -1, n;


bool isFull(int x){
    if (x == n - 1)
        return true;
    else
        return false;
}

void push(int data){
    if (isFull(first) == true){
        cout << "Stack is full. No more elements can be pushed.\n";
        return;
    }
    first += 1;
    for (int i = first; i>0; i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}

void isPrime(int n){
    int i = 2;
    while(n != 1){
        while(n%i == 0){
            push(i);
            n = n/i;
        }
        i++;
    }
    print();
}

void print(){
    cout << "The prime factors are : \n";
    while(first != -1){
        cout << stack_arr[first] << " ";
        first -= 1;
    }
    
}

int main(){
    cout << "Enter the number whose prime factors are to be obtained : \n";
    cin >> n;
    int stack_arr[n];
    isPrime(n);
}

/*bool isPrime(int n){
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
            if (stack_arr[j] < stack_arr[j+1]){   //bubble sorting in descending order
                int temp = stack_arr[j];
                stack_arr[j] = stack_arr[j+1];
                stack_arr[j+1] = temp;
            }
        }
    }

    cout << "The prime factors of " << n << " are : \n";
    for(int i = 0; i<=first; i++){
        if(stack_arr[i] != stack_arr[i+1])
            cout << stack_arr[i] << " ";
        else
            continue;
    }
}*/