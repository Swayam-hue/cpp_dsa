#include <iostream>
#include <string>
using namespace std;

double addition(double x, double y){
    return x+y;
}

double substraction(double x, double y){
    return x-y;
}

double multi(double x, double y){
    return x*y;
}

double div(double x, double y){
    return x/y;
}

int main(){
    char ch;
    double x, y, result = 0;
    cout << "Enter the operation to be performed : " << endl;
    cin >> ch;
    cout << "Enter the numbers : ";
    cin >> x;
    cin >> y;
    switch(ch)
    {
        case '+':
            result = addition(x, y);
            cout << "The sum is : " << result;
            break;
        case '-':
            result = substraction(x, y);
            cout << "The difference is : " << result;
            break;
        case '*':
            result = multi(x, y);
            cout << "The product is : " << result;
            break;
        case '/':
            result = div(x, y);
            cout << "The dividend is : " << result;
            break;
        default:
            cout << "Operation unable!";

    }
    return 0;
}