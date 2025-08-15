#include <bits/stdc++.h>
using namespace std;
   
struct show {int i, f, o;};

bool comp(show &s1, show &s2) 
    {return s1.f > s2.f;}

bool event_comp(pair<int, int> &e1, pair<int, int> &e2)
    {return e1.second > e2.second;}

vector<vector<show>> stages;
vector<pair<int, int>> events; 
int n;

int main() {    
    cin >> n;
    stages.resize(n);

    for(int i = 0; i < n; i++){
        int m; cin >> m; 
        while(m--){
            int a, b, c; cin >> a >> b >> c; 
            stages[i].push_back({a, b, c});
        }

        sort(stages[i].begin(), stages[i].end(), comp);
    }   
    
    for(int i = 0; i < n; i++)
        for(auto it = stages[i].begin(); it != stages[i].end(); it++)
            events.push_back(make_pair(i, it->f));
    
    sort(events.begin(), events.end(), event_comp);

    int mask = (1 << n) - 1; 

    while(events.size()) {
        int id = events.back().first;
        int time = events.back().second;

        cout << id << " " << time << "\n";

        events.pop_back();


    }



    return 0;
}



/*
enquanto houver eventos em 'events':
    k ← índice_do_palco do último evento
    remover último evento de 'events'

    para cada máscara i de 1 até maxi-1:
        se palco k não está incluído em i:
            continuar

        shw ← último show do palco k

        r ← valor_inicial_muito_negativo

        // Transições possíveis:
        // 1) Usar estado dp[i] (mesma máscara)
        para cada (tempo, valor) em dp[i]:
            se tempo <= shw.início:
                r ← max(r, valor + shw.ganho)

        // 2) Usar estado dp[i sem o palco k]
        para cada (tempo, valor) em dp[i XOR (1 << k)]:
            se tempo <= shw.início:
                r ← max(r, valor + shw.ganho)

        // Se encontramos uma transição válida, atualiza dp[i]
        se r > valor_inicial_muito_negativo:
            adicionar (shw.fim, r) a dp[i]

    remover show do palco k de 'shows[k]'

*/