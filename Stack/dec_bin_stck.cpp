#include <iostream>
using namespace std;

const int MAX = 50;
int bin_stck[MAX];
int first = -1;

bool isFull(int x){
    return (x == MAX - 1);
}

bool isEmpty(int x){
    return (x == -1);
}

void push(int data){
    if (isFull(first) == true){
        cout << "Stack is full.\n";
        exit(0);
    }
    first += 1;
    for (int i = first; i > 0; i--){
        bin_stck[i] = bin_stck[i-1];
    }
    bin_stck[0] = data;
}

void pop(){
    if(isEmpty(first) == true){
        cout << "Stack is empty.n\n";
        exit(0);
    }
    for (int i = 0; i<first; i++){
        bin_stck[i] = bin_stck[i+1];
    }
}

void print(){
    cout << "The binary equivalent is : \n";
    for (int i = 0; i<first; i++){
        cout << bin_stck[i] << " ";
    }
}

void dec_to_bin(int data){
    while(data != 0){
        int d = data%2;
        push(d);
        data = data/2;
    }
}

int main(){
    int x;
    cout << "Enter the decimal number : \n";
    cin >> x;
    dec_to_bin(x);
    print();
}
