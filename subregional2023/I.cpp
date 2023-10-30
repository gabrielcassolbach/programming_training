/*I - Investigating Zeroes and Ones*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef long long ll;

int n, s[MAX];
ll p[MAX];
 
/*
s = {0, 1, 0}.
auxs = {1, 0, 1}
(0, 1); (1); (1, 0); (0, 1, 0); 

Ao chegar no terceiro valor, serão acrescidas duas possibilidades:
    (1, 0) e (0, 1, 0).
*/

ll answer(){
    ll ans = 0;
    (s[0] == 1) ? (p[0] = 1) : (p[0] = 0); 
    for(int i = 1; i < n; i++){         
        if(s[i] == 0) p[i] += p[i-1] + 1; 
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
