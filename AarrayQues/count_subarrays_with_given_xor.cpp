#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];
#define fl(n) for(int i = 0; i < n; i++)

int count_subarrays_with_given_xor(int arr[], int n, int x){

    return 0;
}

int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    fin(n,arr);
    cout<<count_subarrays_with_given_xor(arr, n, x)<<endl;
    return 0;
}