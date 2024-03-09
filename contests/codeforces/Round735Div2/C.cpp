#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

/*
0100 xor 0111
-> 3 

5 xor 0 == 5 --
5 xor 1 == 4
5 xor 2 == 7
5 xor 3 == 6
5 xor 4 == 1
5 xor 5 == 0 --
5 xor 6 == 3
5 xor 7 == 2

4 xor 0 = 4 5
4 xor 1 = 5 4
4 xor 2 = 6 7
4 xor 3 = 7 6
4 xor 4 = 0 1
4 xor 5 = 1 0
4 xor 6 = 2 3
4 xor 7 = 3 2

3 xor 0 == 3 --
3 xor 1 == 2
3 xor 2 == 1
3 xor 3 == 0 --
3 xor 4 == 7
3 xor 5 == 6
3 xor 6 == 5
3 xor 7 == 4

2 xor 0 == 2 3   0
2 xor 1 == 3 2   0
2 xor 2 == 0 1   1
2 xor 3 == 1 0   4
2 xor 4 == 6 7   4
2 xor 5 == 7 6   4
2 xor 6 == 4 5   5

2 xor 7 == 5 4   8

ou n > m ou n == m  ou n < m.
    0       n par 1
            n imp n + 1


entrada:
 valor n e m.
 esses valores formam uma seq definida por:
    n xor 0 -> n xor m.

 encontrar o menor valor inteiro não negativo que não pertence a 
 sequência.

n e m. -> souber todos os valores que estão na sequência, tem-se
a resposta.

n e [0, m] -> qual valor não pode ser formado?

- m + 11


*/

ll ans(ll n, ll m){


    
}

int main(){
    ll t, m, n; cin >> t;
    while(t--){ // t ~ 30000 ≃ 3*10^4
        cin >> n >> m;
        if (m < n) {
            cout << 0 << endl;
        } else {
            cout << ans(n, m) << endl;   
        }
    }
    return 0;
}