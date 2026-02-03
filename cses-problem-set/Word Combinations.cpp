#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
const int mod = 1e9 + 7;
typedef long long ll;

#define MAX1 1123456
#define MAX2 26

typedef struct {
    int val;    
    int e; 
} node;


node trie[MAX1][MAX2]; // node | char
ll dp[5123];
string s; 

int main() {
    for(int i = 0; i < MAX1; i++)
        for(int j = 0; j < MAX2; j++)
            {trie[i][j].val = trie[i][j].e = 0;}
    for(int i = 0; i < 5123; i++) dp[i] = 0;
    cin >> s; 
    int t; cin >> t; 
    int node_qt = 1;
    while(t--){
        int node = 0; 
        string aux; cin >> aux; 
        for(int i = 0; i < (int) aux.size(); i++){
            int c = aux[i] - 'a';
            
            if(!trie[node][c].val) trie[node][c].val = node_qt++; 
            if(i ==  (int)aux.size() - 1)  trie[node][c].e = 1;

            node = trie[node][c].val;
        }
    }
     
    dp[(int) s.size()] = 1; 
    for(int i = (s.size() - 1); i >= 0; i--){
        int node = 0; int c = s[i] - 'a';
        int j = i;
       
        while(trie[node][c].val != 0 && j < (int) s.size()){
            if(trie[node][c].e)
                {dp[i] += dp[j + 1] % mod;}
             
            node = trie[node][c].val;
            j++; 
            c = s[j] - 'a';
        }

    }
    
    cout << dp[0]%mod << "\n";

    return 0; 
}
