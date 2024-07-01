#include<iostream>
using namespace std;

bool sorted(int a[], int index, int size){
    if (index == size - 1)
        return true;
    
    return (a[index] < a[index+1] && sorted(a, index+1, size));
}

int main(){
    int a[] = {1,2,3,4,6};
    int size = sizeof(a)/sizeof(a[0]);
    bool ans = sorted(a, 0, size);
    cout << ans;
}