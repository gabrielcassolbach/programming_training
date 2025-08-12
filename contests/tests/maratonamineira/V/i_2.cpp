#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int n, k; 
vector<int> v;


// Tabela min_cost com i, j [onde i e j representam mesas]

// min_cost[i,j] = custo minimo para levar todos os pratos de [i,j] até uma única mesa de i, j

// dp[n, k], onde 
// 1) n representa o numero de mesas (da esquerda para a direita) de 0 até n
// 2) k representa a quantidade maxima de pilhas escolhidas

// testar iterativamente de m = 0 até n-1
// calcular dp[m, k-1] + min_cost[m+1, n]
// onde dp[m, k-1] representa o custo de tempo para levar todos os pratos das mesas 0 até m em k-1 pilhas
// min_cost[m+1, n] representa o custo de tempo para levar todos os pratos das mesas m+1 até n em 1 pilha
// entao, dp[m, k-1] + min_cost[m+1, n] representa o custo de tempo para levar todos os pratos das mesas 0 até n em k pilhas
// dp[n, k] = min desses valores

// por padrao, dp[n_i, 0] = 0

// resposta final é dp[N, K]



int main(){
    fastio;
    cin >> n >> k; v.resize(n);

    for(int i = 0; i < n; i++) 
        cin >> v[i];




    return 0;
}