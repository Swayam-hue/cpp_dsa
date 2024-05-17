#include <iostream>
using namespace std;
int top =-1;
int const MAX = 5;
int stc_arr[MAX];

bool isEmpty(int x){
    if (x == -1)
        return true;
    else
        return false;
}

bool isFull(int x){
    if (x == MAX -1)
        return true;
    else
        return false;
}
void push(int x){
    if (isFull(top) == true){
        cout << "Stack is full." << endl;
    }
    else {
        top += 1;
        stc_arr[top] = x;
    }
}

int pop(){
    if (isEmpty(top) == true){
        cout << "Stack underflow. Stack is empty.\n";
        exit(1);
    }
    else {
    int x = stc_arr[top];
    top = top - 1;
    return x;
    }
}

void print(){
    if (isEmpty(top) == true){
        cout << "Stack Underflow!.\n";
        return;
    }
    
    for (int i = top; i>=0; i--)
        cout << stc_arr[i] << " ";
}

int main(){
    int data;
    push(2);
    push(3);
    pop();
    pop();
    pop();
    print();
}

