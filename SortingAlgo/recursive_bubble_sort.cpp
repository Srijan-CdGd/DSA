#include <bits/stdc++.h>
using namespace std;

# define fout(n, a) for(int i = 0; i < n; i++){cout<<a[i]<<" ";}
# define fin(n, a) for(int i = 0; i < n; i++){cin>>a[i];}

void recursive_bubble_sort(int*a, int i){
    if(i == 0) return;
    for(int j = i; j >= 0; j--){
        if(*(a+i) < *(a+j)) swap(*(a+i), *(a+j));
    }
    recursive_bubble_sort(a, i-1);
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];

    fin(n, a);
    recursive_bubble_sort(a, n-1);
    fout(n, a);
    cout<<endl;

    return 0;
}