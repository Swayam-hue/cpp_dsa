//This is a program to convert an infix expression to postfix using stacks.

#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 100;
char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

int space (char c){
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

bool isEmpty(){
    if (top == -1)
        return true;
    else
        return false;
}

bool isFull(){
    if (top == MAX - 1)
        return true;
    else
        return false;
}

void push(char x){
    if (isFull() == true){
        cout << "Stack is full.\n";
        exit(1);
    }
    else{
        top += 1;
        stack[top] = x;
    }
}

char pop(){
    if (isEmpty() == true){
        cout << "Stack is empty. Nothing to be removed.\n";
        exit(1);
    }
    else{
        char res = stack[top]; //This cannot be written as return stack[top]; top -= 1; as return is the last statement executed by the function and this top -= 1 will never be executed.
        top = top - 1;
        return res; //The shorter for of this is return stack[top--];
    }
}

int precedence(char symbol){
    switch (symbol)
    {
    //Higher value means higher precedence
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void inTopost(){
    int j = 0, i = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        if (space(symbol) == 0){ //If symbol is not a whitespace
            switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while ( (isEmpty() == false) && (precedence(stack[top]) >= precedence(symbol)) )
                postfix[j++] = pop();
            push(symbol);
            break;
        
        default:
            postfix[j++] = symbol;
            break;
        }   
        }
    }
    while(isEmpty() == false)
        postfix[j++] = pop();
    postfix[j] = '\0';  
}

int main(){
    cout << "Enter the infix expression : \n";
    gets(infix);
    inTopost();
    cout << "Postfix expresion : " << postfix << endl;
}