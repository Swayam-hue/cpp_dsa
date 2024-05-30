#include <iostream>
using namespace std;


int findSecondMaxElement(int n, int a[]){
    int max = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n-i-1; j++){
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return a[n-1-1];
}

int main(){
    int n;
    cout << "Enter the size of the array : \n";
    cin >> n;
    int a[n];
    cout << "ENter the elements of the array : \n";
    for (int i = 0; i<n; i++)
        cin >> a[i];
    int max2 = findSecondMaxElement(n, a);
    cout << max2;
    return 0;
}