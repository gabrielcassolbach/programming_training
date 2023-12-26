#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef long long int ll;

int v[MAX];

ll sum_v(int n){
    ll sum = 0;
    for(int i = 0; i < n; i++)  
        sum += v[i];
    return sum;
}

// Simulation part.
bool trik(ll mid, int n){
    ll k = mid;
    bool entered = false;
    for(int i = 1; i < n; i++){
        entered = true;
        if((v[i] - v[i - 1]) > k) return false;
        if((v[i] - v[i - 1]) == k) --k;
    }   
    if(!entered) {return false;}
    return true;
}

// Scan all the range of values using binary search.
void binary_search(int n){
    ll lo, hi, mid, k;
    lo = 1; 
    hi = sum_v(n);
    k = hi + 1;
    while(lo <= hi){
        printf("lo: %d & hi: %d & k: %d\n", lo, hi, k);
        mid = lo + (hi - lo) / 2; // mid = 5 000 001.
        if(trik(mid, n))
            {/*printf("returned true\n");*/ k = mid; hi = mid - 1;}
        else 
            {/*printf("returned false\n");*/lo = mid + 1;} 
    }
    printf("%lld\n", k);
}

int main(){
    int t, n, test_cases = 0;
    scanf("%d", &t);
    while(t--){
        test_cases++;
        memset(v, 0, sizeof v);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        printf("Case %d: ", test_cases);
        binary_search(n);
    }
    return 0;
}
