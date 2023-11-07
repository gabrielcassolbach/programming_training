/*I - Investigating Zeroes and Ones*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef long long ll;

int n, s[MAX];
ll p[MAX];
 
ll answer(){
    ll ans; int ctr = 0;
    (s[0] == 1) ? p[0] = 0 : p[0] = 1;
    for(int i = 1; i < n; i++) 
        {(s[i] == 1) ? p[i] = 0 : p[i] = p[i-1] + 1;} 
    ans = 0;
    for(int i = 0; i < n; i++){
        ctr += s[i];
        if(s[i]) {
            ans++;    
            printf("i=%d and answer is %lld\n", i, ans);
            if((i-1) >= 0 && p[i-1]) ans += p[i-1];
            if(p[i+1]){
                int k = i + 2;
                while(p[k] && k < n) k++;
                ans += p[k-1];
            }
            if(p[i+1] == )            
        }
        printf("i=%d and answer is %lld\n", i, ans);
    }
    return ans;
}

void lerValores(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
}

int main(){
    lerValores();
    printf("%lld\n", answer());
    return 0;
}
