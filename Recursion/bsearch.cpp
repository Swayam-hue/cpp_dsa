#include <iostream>
using namespace std;

int recur_bs(int a[], int key, int s, int e){
    if (s > e)
        return -1;
    
    int mid = s + (e - s)/2;

    if(key == a[mid])
        return mid;

    if (key < a[mid])
        return recur_bs(a, key, s, mid-1);
    
    if (key > a[mid])
        return recur_bs(a, key, mid+1, e);
}

int main(){
    int a[] = {10, 20, 30, 44, 66, 80, 90, 87};
    int key = 66;
    int ans = recur_bs(a, key, 0, sizeof(a)/sizeof(a[0]));
    cout << ans;
}