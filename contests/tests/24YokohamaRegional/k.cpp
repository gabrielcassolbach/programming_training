#include <bits/stdc++.h>
using namespace std;

map<string, pair<int, int>> masks;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str, n_str; cin >> str; 
        n_str = "";
        for(int j = 0; j < (int) str.size(); j++){
            if(str[j] == 'N')  
                n_str += "0";
            else 
                n_str += "1";
        }
        if(masks.find(n_str) == masks.end()){
            masks[n_str] = make_pair(i + 1, 0);
        }else{
            masks[n_str] = make_pair(masks[n_str].first, i + 1);   
        }  
    }

    for(auto mask : masks){
        cout << "mask: " << mask.first << "\n";
        string comp_mask = "";
        for(int i = 0; i < (int) mask.first.size(); i++){
            if(mask.first[i] == '0')
                comp_mask += '1';
            else 
                comp_mask += 'X';
        }
        cout << comp_mask << "\n";    
    }


    return 0;
}

/*

NNYYN

00110 -> mascara de NNYYN

dados m judges,

fazemos todas as mascaras possiveis, i.e., no max 2^m.

Exemplo:

NNY - 001 (indice 1)
YYN - 110 (indice 2)
YNY - 101 (indice 3)
NYY - 011 (indice 4)

Todas as mascaras possiveis (2^m):

000, 
001 = {1}, 
010, 
011 = {4}, 
100, 
101 = {3}, 
110 = {2}, 
111

001 = {1} -> complementar seria 11X, ver mascaras 110 e e 111

*/