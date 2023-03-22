#include<iostream>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];

void count_sort(int a[], int n){
    int max = INT32_MIN;
    for(int i = 0; i < n; i++) if(max < a[i]) max = a[i];
    int cnt[++max] = {0};
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    for(int i = 0; i < max - 1; i++) cnt[i+1] += cnt[i];
    int arr[n] = {0};
    for(int i = n-1; i >= 0; i--) arr[--cnt[a[i]]] = a[i];
    for(int i = 0; i < n; i++) a[i] = arr[i];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fin(n,arr);
    count_sort(arr, n);
    fout(n, arr);
    cout<<endl;
    return 0;
}