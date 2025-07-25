#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define f first
#define s second

typedef long long ll;

ll dp[MAX][MAX];

// on hold


ll comb(int a, int b){ 
    cout << a << " " << b  << "\n";
    if(dp[a][b] != -1) return dp[a][b]; 
    if(a == b || b == 0) return 1; 
    if(b > a/2)
        b = (a-b);
    cout << a << " " << b  << "\n";
    return dp[a][b] = (comb(a, b-1)*((a-b+1)))/b;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, p, s; cin >> n >> m >> p >> s;
    vector<int> v(n + 1); vector<pair<int, int>> v_m; 

    memset(dp, -1 ,sizeof(dp));
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < m; i++){
        int val1, val2; cin >> val1 >> val2; 
        v_m.push_back(min(val1, val2), max(val2, val1));
    }   
    
    ll x = 0;
    for(int i = 0; i <= n-p-s; i++) {
        x += comb(n-p-s, i);
    }
    ll total = x * p * s;

    cout << "x: " << x << '\n';
    
    // calcula quantidade de combinacoes inadequadas
    ll y = 0;
    // 1 2 3 4  --> p = 1. s = 1. 
    // i.f <= 2 
    for(auto val : v_m) {
        // Pao + Salsicha
        if(val.f <= p && (val.s > p && val.s <= p+s)){
            y += x;
        }
        // Pao + aleatorio
        else if(val.f <= p && val.s > p+s){

        // Salsicha + aleatorio
        }else if((val.f > p && val.f <= p+s) && val.s > p+s){

        }else{  // aleatorio + aleatorio

        }
    }

    cout << x - y << "\n";
    
    return 0;
}

/*

Para cada possibilidade:

1) O pao
2) A salsicha
3) Todas as combinacoes possiveis com os N-P-S ingredientes aleatorios

O calculo de
possibilidades (sem contar as excecoes) = P * S * (X),

onde por exemplo, para 10 ingredientes aleatorios, tem-se:
X = (10 1) + (10 2) + (10 3) + (10 4) + ... + (10 10)

Para contar as excecoes, basta conta-las e subtrai-las do total
 
-> primeiro caso de teste: (N 2)

*/


// 0 1 2 3 4 5 6 7 8 9

// 3 4

// 0 1 2 34 5 6 7 8 9

// 34 e faz todas as combinacoes para 0 1 2 5 6 7 8 9

// (8 0) + (8 1) + ... + (8 8)

// caso (8 0) é o caso com só 3 e 4
// caso (8 8) é o caso com tudo