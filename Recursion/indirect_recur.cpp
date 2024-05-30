//WAP to print numbers from 1 to 10 in such a way that if the number is even, subtract 1 from it but if it is odd add 1 to it.
#include <iostream>
using namespace std;
int n = 1;

void odd();
void even();

void odd(){
    if (n <= 10){
        cout << n+1 << " ";
        n++;
        even();
    }
    return;
}

void even(){
    if (n <= 10){
        cout << n-1 << " ";
        n++;
        odd();
    }
    return;
}

int main(){
    odd();
}