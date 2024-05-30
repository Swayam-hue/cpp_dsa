#include <iostream>
using namespace std;

const int MAX = 50;
int top = -1;
int stack_fac[MAX];

bool isFull(int num) {
    return num == MAX - 1;
}

bool isEmpty(int num) {
    return num == -1;
}

void push(int data) {
    if (isFull(top)) {
        cout << "Stack is full. No more elements can be pushed.\n";
        return;
    }
    top += 1;
    for (int i = top; i > 0; i--) {
        stack_fac[i] = stack_fac[i - 1];
    }
    stack_fac[0] = data;
}

int pop() {
    if (isEmpty(top)) {
        cout << "Stack is empty. No more elements can be deleted.\n";
        return 0;
    }
    int value = stack_fac[0];
    for (int i = 0; i < top; i++) {
        stack_fac[i] = stack_fac[i + 1];
    }
    top -= 1;
    return value;
}

void prime_fact(int num) {
    int i = 2;
    while (num != 1) {
        while (num % i == 0) {
            push(i);
            num /= i;
        }
        i++;
    }
    cout << "Prime factors in descending order are as follows:\n";
    while (!isEmpty(top)) {
        cout << pop() << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter the number to be factored:\n";
    cin >> num;
    prime_fact(num);
    return 0;
}
