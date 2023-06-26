#include <bits/stdc++.h>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<*(a + i)<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>*(a + i);

void recursive_insertion_sort(int *a, int i, int n){
    if(i == n) return;
    
    int k = *(a+i);
    int j = i - 1;
    while(j >= 0 && *(a+j) > k){
        swap(*(a+j+1), *(a+j)); 
        j--;
    }
    recursive_insertion_sort(a, i+1, n);

}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    fin(n, a);
    recursive_insertion_sort(a, 0, n);
    fout(n,a);
}