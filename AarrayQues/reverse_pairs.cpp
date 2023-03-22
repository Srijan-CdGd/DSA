#include <iostream>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];

int merge(int arr[], int s, int mid, int e){
    int j = mid + 1, c = 0;
    for(int i = s; i <= mid; i++){
        while(j <= e && arr[i] > arr[j] * 2) j++;
    c += j - mid - 1;
    }
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
    return c;
}

int divide(int arr[], int s, int e){
    int mid = s + (e - s)/2;
    int c = 0;
    if(s >= e) return 0;
    c += divide(arr, s, mid);
    c += divide(arr, mid + 1, e);
    c += merge(arr, s, mid, e);
    return c;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fin(n,arr);
    cout<<divide(arr, 0, n - 1)<<endl;
    cout<<endl;
    return 0;
}