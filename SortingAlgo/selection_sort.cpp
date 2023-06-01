#include<bits/stdc++.h>

using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];

void selection_sort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min = INT16_MAX;
        int min_ind = i;
        for(int j = i; j < n; j++) {
            if(min > *(a+j)) {
                min = *(a+j);
                min_ind = j;
            }
        }
        swap(*(a + min_ind), *(i + a));
    }
}

int main(){
    int n;
    cout << "Length of the array: ";
    cin >> n;
    int a[n];
    fin(n, a);
    selection_sort(a, n);
    fout(n, a);
}