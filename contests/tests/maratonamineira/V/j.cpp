#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> v1, v2;

int set_cicle(vector<int> &cicles, int j, int val, int size){
    if(v1[j] == val) return size + 1;
    return cicles[j] = set_cicle(cicles, v1[j], val, ++size);
}

int main() {
    fastio; 
    int n; cin >> n;
    v1.resize(n + 1); 
    v2.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> v1[i];
    for(int i = 1; i <= n; i++)
        cin >> v2[i];

    vector<int> cicles; 
    cicles.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(cicles[i] != 0) continue;
        int val = v1[i];
        int j = val;
        cicles[i] = set_cicle(cicles, j, val, 0);
    }
    
    int prev_elem = 0;
    for(int i = 1; i <= n; i++){
        if(v2[i] == 0) 
            {prev_elem++; continue;}
        if(prev_elem + 1 <= cicles[v2[i]]){ 
            int val = v2[i]; // valor inicial do ciclo == 3.
            int prox_val = v1[val]; // 4.
            if(i + 1 > n){
                
            }
            for(int k = 1; k <= cicles[v2[i]] - 1; k++){


                
            }
            prev_elem = 0;
        }else{  
            cout << -1 << '\n';
            return 0;
        }
    }

    /*
    iterar sobre v2:
        se encontrar um 0 -> continue elem++. 
        senao:
            elem + 1 <= cicles(v2[i]) ? -> seta esses valores:
                coloca os valores em v2 utilizando o cicles.
                elem = 0.
            elem + 1 > cicles(v2[i]) -> erro!
    */

    /*
        itero sobre v2. se encontrar zero -> -1 (erro)
        senão
            imprima v2.
    */

    return 0;
}