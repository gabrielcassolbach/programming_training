#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1123456789

typedef long long ll;

map<string, int > m; 

void set_m() {
    m["Mon"] = 0; 
    m["Tue"] = 1; 
    m["Wed"] = 2; 
    m["Thu"] = 3; 
    m["Fri"] = 4; 
    m["Sat"] = 5; 
    m["Sun"] = 6;
}

/*
1 Sparse Table -> qtd = quantidade de dias do dia de depósito até o dia da última renovação.
(val - qtd).

1 Sparse Table -> dia da semana da próxima renovação. 

*/


int main(){
    fastio; 

    return 0;
}