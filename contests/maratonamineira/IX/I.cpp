#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n;
vector<ll> v;

/*
-> backtracking ou busca completa. (TLE)
-> divisão e conquista: não tem nenhuma relação de ordem no problema. X
-----------------------------------------------------------------------
-> programação dinâmica.
-> guloso. (perhaps)

s1 e1 s2 e2 s3 e3 s4 e4 s1
   10    -2    20    7

-- faço a escolha ótima dos três primeiros valores:
10 -2  7
s1 10 s2 4 s3 4 s4 6 s1

-- e1 e3 (e5 e7 e9)
-- e2 e4 e6 e8 e10

-- e1 e e3 ou e2 e e4 

5
s1 1 s2 -8 s3 1 s4 10 s5 -1 s1
   e1   e2   e3    e4    e5
-----------------------------
enum all the possibilities:
-- e1 - e4 -> lógica circular.
or
-- e1 - e3 - e5 -> todos os impares.
or  
-- e2 - e4. --> todos os pares.
----------------------------- 
1  2  3  4  5  6  7  
-- 1 3 5 7 -- decorrente dos impares
-- o terceiro elemento é negativo 
-- 1 > 5 + 7.


-- 2 4 6 -- decorrente dos pares
-- 1 6 4 -- decorrente de tras pra frente começando com impar
-- 2 7 5 -- decorrente de tras pra frente começando com par

*/

void read(){
    cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
}

void answer(){
    ll max_imp = 0; ll max_par = 0; ll max_cir = 0; ll max_cir2 = 0;
    // primeiro caso: todos os ímpares:
    ll tmp_ans = 0;
    for(int i = 1; i <= n; i += 2){
        if(v[i] < 0){
            tmp_ans = max(tmp_ans, max_imp);
            max_imp = 0;
        }else{
            max_imp += v[i];
        }  
    }
    // segundo caso: todos os pares:
    tmp_ans = 0;
    for(int i = 2; i <= n; i += 2){
        if(v[i] < 0){
            tmp_ans = max(tmp_ans, max_par);
            max_par = 0;
        }else{
            max_par += v[i];
        }  
    }
    // terceiro caso: lógica circular 1:
    max_cir = v[1] > 0 ? v[1] : 0; tmp_ans = 0;
    for(int i = n-1; i > 2; i -= 2){
       if(v[i] < 0){
            tmp_ans = max(tmp_ans, max_cir);
            max_cir = 0;
        }else{
            max_cir += v[i];
        } 
    }
    // quarto caso: lógica circular 2:
    max_cir2 = v[2] > 0 ? v[2] : 0; tmp_ans = 0;
    for(int i = n; i > 2; i -= 2){
        if(v[i] < 0){
            tmp_ans = max(tmp_ans, max_cir2);
            max_cir2 = 0;
        }else{
            max_cir2 += v[i];
        } 
    }
    ll ans = max(max_imp, max_par);
    ans = max(ans, max_cir);
    ans = max(ans, max_cir2);
    cout << max_imp << " " << max_par << " " << max_cir << " " << max_cir2 << endl;
    cout << ans << endl;
}

int main(){
    read();
    answer();
    return 0;
}