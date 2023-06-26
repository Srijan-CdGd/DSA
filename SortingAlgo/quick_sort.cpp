#include <bits/stdc++.h>

using namespace std;

#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];
#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";

int partition(int a[], int l, int h){
    int pivot = a[l];
    int i = l;
    for(int j = l; j <= h; j++){
        if(a[j] < pivot){
            swap(a[++i], a[j]);
        }
    }
    swap(a[i], a[l]);
    return i;
}

void quick_sort(int a[], int l, int h){
    if(l < h){
        int parti = partition(a, l, h);
        quick_sort(a, l, parti-1);
        quick_sort(a, parti+1, h);
    }
}

int main(){
    int n;
    cout<<"Number of the elements in array: ";
    cin >> n;
    int a[n];
    fin(n, a);
    quick_sort(a, 0, n-1);
    fout(n, a);
    return 0;
}