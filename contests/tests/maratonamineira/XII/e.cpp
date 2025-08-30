#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 

    vector<pair<int,int>> doce(n+1);
    vector<vector<int>> regiao(n+1);

    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;

        // doce
        doce[i] = make_pair(a, b);

        // regiao
        regiao[a].push_back(i);
        regiao[b].push_back(i);
    }

    int counter = 0;

    for(int i = 1; i <= n; i++) { //itera por cada doce (par de regioes)
        if(doce[i].first == doce[i].second) continue;
        
        int troca; 
        for(auto val : regiao[doce[i].first]){
            if(val != i) 
                troca = val; 
        }
           
        int num = (doce[troca].first == doce[i].first) ? 0 : 1;     
        
        int aux = doce[i].second; 
        doce[i].second = doce[i].first;

        if(num == 0)
            doce[troca].first = aux; 
        else    
            doce[troca].second = aux; 

        regiao[doce[i].first] = {i, i};

        if(regiao[aux][0] == i)
            regiao[aux][0] = troca;
        else
            regiao[aux][1] = troca;
            
        counter++;
    }
    
    cout << counter << "\n";

    return 0; 
}