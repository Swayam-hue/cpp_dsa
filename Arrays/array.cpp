#include <iostream>
using namespace std;


int maxElement(int n, int a[]){
    int max = 0;
    for (int i = 0; i<n; i++){
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main(){
    int n;
    cout << "Enter the size of the array : \n";
    cin >> n;
    int a[n];
    cout << "ENter the elements of the array : \n";
    for (int i = 0; i<n; i++)
        cin >> a[i];
    int max = maxElement(n, a);
    for (int j = 0; j<n; j++){
        if (a[j] == max)
            a[j] = 0;
    }

    int max2 = maxElement(n, a);
    cout << "The second largest element is : " << max2;
}