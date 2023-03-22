#include <iostream>
using namespace std;

#define fout(n, a) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define fin(n, a) for(int i = 0; i < n; i++) cin>>a[i];
typedef long long int ll;

pair<int, int>  missing_and_repeating_nos_1(int a[], int n){
    int max = INT32_MIN;
    for(int i = 0; i < n; i++) if(max < a[i]) max = a[i];
    int cnt[max + 1] = {0};
    pair<int, int> p;
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    for(int i = 0; i < max + 1; i++){
        if(cnt[i] == 0) p.first = i;
        if(cnt[i] == 2) p.second = i;
    }
    if(max == n - 1) p.first = n;
    return p;
}

pair<int, int>  missing_and_repeating_nos_2(int a[], int n){
    int max = INT32_MIN;
    pair<int, int> pair;
    int s = n*(n+1)/2;
    int s2 = n*(n+1)*((2*n)+1)/6;
    for(ll i = 0; i < n; i++){
        s -= a[i];
        s2 -= (a[i]*a[i]);
    }
    pair.first = (s + (s2/s))/2;
    pair.second = pair.first - s;
    return pair;
}

int main(){
    int n;
    pair<int, int> p1, p2, p3;
    cin>>n;
    int arr[n];
    fin(n,arr);
    p1 = missing_and_repeating_nos_1(arr, n);
    p2 = missing_and_repeating_nos_2(arr, n);
    cout<<"Using count sort: "<<p1.first<<" "<<p1.second<<endl;
    cout<<"Using Maths Formula: "<<p2.first<<" "<<p1.second<<endl;
    return 0;
}