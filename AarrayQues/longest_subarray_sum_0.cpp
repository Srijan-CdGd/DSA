#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];
#define fl(n) for(int i = 0; i < n; i++)

int longest_subarray_sum_0(int arr[], int n){
    int maxE = 0, s = 0;
    unordered_map<int, int> m;
    fl(n){
        s += arr[i];
        if(s == 0)maxE = i + 1;
        else{
            if(m.count(s) != NULL)
                maxE = max(maxE, i - m[s]);
            else
                m[s] = i;
        }
    }
    return maxE;
}

int main(){
    int n, a;
    cin>>n;
    int arr[n];
    fin(n,arr);
    a = longest_subarray_sum_0(arr, n);
    cout<<a<<endl;
    return 0;
}