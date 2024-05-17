//Write a program to implement a stack in an array stack_arr[] with stack_arr[0] as the top element and operation : push, pop, peek, isEmpty, isFull.

#include <iostream>
using namespace std;
int const MAX = 5;
int stack_arr[MAX];
int first = -1;

bool isEmpty(int x){
    if (x == -1)
        return true;
    else
        return false;
}

bool isFull(int x){
    if (x == MAX - 1)
        return true;
    else
        return false;
}

int peek(){
    if (isEmpty(first) == true){
        cout << "Stack is empty.\n";
        return 0;
    }
        return stack_arr[0];

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


int pop2(){ //instead of deleting the value at index 0 we shift all the elements to left and decrease 'first' by 1 so that no duplicate elements are left
    if (isEmpty(first) == true){
        cout << "Stack is empty. No more elements can be deleted.\n";
        return 0;
    }
    int value = stack_arr[0];
    for (int i = 0; i<first; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first -= 1;
    return value;
}

void print(){
    for(int i = 0; i<=first; i++)
        cout << stack_arr[i] << " ";
    printf("\n");
}

int main(){
    int ch;
    do{
    int value;
    cout << "Enter the operation to be performed : \n";
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Print all the elements of the stack" << endl;
    cout << "4. Print the top element of the stack." << endl;
    cout << "5. Quit" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Enter the value to be pushed : \n";
        cin >> value;
        push(value);
        break;
    case 2:
        pop2();
        break;
    case 3:
        print();
        break;
    case 4:
        cout << "The top most element is : " << peek() << endl;
        break;
    case 5:
        return 0;
    default:
        cout << "Invalid choice , please try again.\n";
        break;
    }
    } while(ch != 5);  
}