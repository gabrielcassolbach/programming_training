#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int v[MAX];

int sum_v(int n){
    int sum = 0;
    for(int i = 0; i < n; i++)  
        sum += v[i];
    return sum;
}

void binary_search(int n){
    int lo, hi, mid, k;
    lo = 1;
    hi = sum_v(n);
    k = hi + 1;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(trik(mid, n)){
            k = mid;
            
        }

    }
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        binary_search(n);
    }
    return 0;
}