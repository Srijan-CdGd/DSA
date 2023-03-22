#include <iostream>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];

// This is the function used to merge all the nodes that are formed after division and work in a regressive manner.

void merge(int arr[], int s, int mid, int e){
    int temp[e+1] = {0};
    int x = s, y = mid + 1;
    int k = 0;

    while(x <= mid && y <= e){
        if(arr[x] > arr[y]) temp[k++] = arr[y++];
        else temp[k++] = arr[x++];
    }

    while(x <= mid) temp[k++] = arr[x++];
    while(y <= e )temp[k++] = arr[y++];

    for(int i = s, j = 0; i <= e; i++, j++) arr[i] = temp[j];
}

void divide(int arr[], int s, int e){
    int mid = s + (e - s)/2;
    if(s >= e) return;
    divide(arr, s, mid);
    divide(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fin(n,arr);
    divide(arr, 0, n - 1);
    fout(n, arr);
    cout<<endl;
    return 0;
}