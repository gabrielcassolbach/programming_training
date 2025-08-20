#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &bits){;
    for(int i = 0; i < (int) bits.size(); i++)
        if(bits[i]) 
            return false;
    return true;
}

// refletir sobre a razão da simulação parar em 2*n.
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    
    vector<int> bits;
    vector<vector<int>> s;  
    bits.resize(m+1, 0);

    int qtd; cin >> qtd;
    for(int i = 0; i < qtd; i++){
        int bit; cin >> bit; 
        bits[bit] ^= 1; 
    }

    s.resize(n);
    for(int i = 0; i < n; i++){
        int qtd; cin >> qtd; 
        for(int j = 0; j < qtd; j++){
            int bit; cin >> bit; 
            s[i].push_back(bit);
        }
    }

    for(int i = 0; i <= 2*n; i++){
        int sw = i%n;
        for(int j = 0; j < (int)s[sw].size(); j++)
            bits[s[sw][j]] ^= 1;
            
        if(check(bits)){
            cout << i+1 << '\n';
            return 0;
        }
    }   

    cout << "-1\n";
    return 0;
}