#include <bits/stdc++.h>
using namespace std;

// Expected output: 3656158440062976

#define MAX 20 
#define LENGTH 1123456

typedef long long int ll;

int numbers[MAX]; ll quantity[LENGTH]; ll values[LENGTH]; 

ll number_in(ll k){
    int pos; ll sum = 0;
    for(int n = 0; n < LENGTH; n++) {sum += (ll)quantity[n]; if(sum >= k) return values[n];} 
    return -1;
}

ll formula(int i, int n){ 
    ll pos = 0;
    for(int l = 0; l <= i; l++) 
        pos += (numbers[l]*(pow(n, l)));
    return pos;
}

void set_parameters(int i, int d, int k){
    for(int n = 0; n < LENGTH; n++) values[n] = formula(i, n + 1);
    for(int n = 0; n < LENGTH; n++) quantity[n] = (ll)(d*(n+1));
}

int main(){
    int tc, i, d;
    ll k; 
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &i);
        for(int j = 0; j <= i; j++) scanf("%d", &numbers[j]);
        scanf("%d", &d); scanf("%lld", &k);
        set_parameters(i, d, k);
        printf("%lld\n", number_in(k));
    }   
    return 0;
}

