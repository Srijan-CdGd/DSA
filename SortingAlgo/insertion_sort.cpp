#include<bits/stdc++.h>

using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<*(a + i)<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>*(a + i);

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int k = *(a+i);
        int j = i - 1;
        while(j >= 0 && *(a+j) > k){
            swap(*(a+j+1), *(a+j)); 
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    fin(n, a);
    insertion_sort(a, n);
    fout(n, a);
    return 0;
}