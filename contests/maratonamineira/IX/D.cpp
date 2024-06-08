#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 502
#define INT_MAX __INT_MAX__

typedef long long ll;

ll mapa[MAX][MAX];
ll squares[MAX][MAX];
ll t2[MAX][MAX];
ll t3[MAX][MAX];
ll n, m, k, q;
ll mini = INT_MAX;

int main(){

    for(ll i = 0; i < MAX; i++){
        for(ll j = 0; j < MAX; j++){
            mapa[i][j] = INT_MAX;
        }
    }
    cin >> n >> m >> k >> q;
    for(ll i = 1; i <= q; i++){
        ll a, b, d;
        cin >> a >> b >> d;
        mapa[a][b] = d;
    }

    for(ll i = 1; i <= n-k+1; i++){
        for(ll j= 1; j <= m; j++){
            ll M = 0;
            for(ll x= i; x < i+k; x++){
                M = std::max(M, mapa[x][j]);
            }
            t2[i][j] = M;
        }
    }
    for(ll i = 1; i <= n-k+1; i++){
        for(ll j= 1; j <= m-k+1; j++){
            ll M = 0;
            for(ll y= j; y < j+k; y++){
                M = std::max(M, t2[i][y]);
            }
            t3[i][j] = M;
        }
    }
    for(ll i = 1; i <= n-k+1; i++){
        for(ll j= 1; j <= m-k+1; j++){
            mini = min(mini, t3[i][j]);
        }
    }
    if(mini == INT_MAX)
        cout << -1 << endl;
    else
        cout << mini << endl;
}