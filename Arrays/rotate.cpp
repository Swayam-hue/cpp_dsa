#include <iostream>
using namespace std;

void rotate_by_k(int n, int a[], int k){
    int temp;
    while (k!=0){
        temp = a[0];
        int copy = n - 1;
        int i = 0;
        while (copy >= 0){
            a[i] = a[i+1];
            copy --;
            i++;
        }
        a[copy - 1] = temp;
        k--;
    }
    for (int i = 0; i<n; i++)
        cout << a[i] << " ";
}

int main(){
    int n;
    cout << "Enter the size of the array : \n";
    cin >> n;
    int a[n];
    cout << "ENter the elements of the array : \n";
    for (int i = 0; i<n; i++)
        cin >> a[i];
    int k;
    cout << "Rotate by : \n";
    cin >> k;
    rotate_by_k(n, a, k);
}