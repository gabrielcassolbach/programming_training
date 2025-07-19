#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 1e18

int main() {
    fastio;

    vector<long long> input;
    
    int n, k; cin >> n >> k;

    input.resize(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> input[i];
    }

    vector<long long> sum_cost(n+1, 0);
    vector<long long> sum_distance_cost(n+1, 0);

    for(int i = 1; i <= n; i++) {
        sum_cost[i] = sum_cost[i-1] + input[i];
        sum_distance_cost[i] = sum_distance_cost[i-1] + i * input[i];
    }

    vector<vector<long long>> min_cost(n+1, vector<long long>(n+1));

    // calcula min_cost
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            long long min_cost_cell = INF;
            for(int l = i; l <= j; l++) {
                // pela esquerda
                long long left_cost = l * (sum_cost[l] - sum_cost[i-1]) - (sum_distance_cost[l] - sum_distance_cost[i-1]);
                // pela direita
                long long right_cost = (sum_distance_cost[j] - sum_distance_cost[l-1]) - l * (sum_cost[j] - sum_cost[l-1]);

                long long total_cost = left_cost + right_cost;

                if(min_cost_cell > total_cost)
                    min_cost_cell = total_cost;
            }

            min_cost[i][j] = min_cost_cell;
            // cout << i << ", " << j << ": " << min_cost[i][j] << "\n";
        }
    }

    vector<vector<long long>> dp(n+1, vector<long long>(k+1, INF));
    for(int i = 0; i <= k; i++){
        dp[0][i] = 0;
    }

    // calcular dp
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int l = 0; l < i; l++) {
                if(dp[l][j-1] == INF) continue;
                int cost_cell = dp[l][j-1] + min_cost[l+1][i];
                if(dp[i][j] > cost_cell)
                    dp[i][j] = cost_cell;
            }
            
        }
    }

    cout << dp[n][k] << "\n"; 

    return 0;
}

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