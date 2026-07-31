#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;

const ll MOD = (1LL << 61) - 1; 
const ll BASE = 131;

ll compute_hash(string s){
    __int128_t hash = 0;
    for(char c : s)
        hash = (hash * BASE + (c - 'a' + 1))%MOD;
    return (ll) hash;
}

int main(){
    fastio;
    vector<ll> hash_s; 
    string s1, s2; cin >> s1 >> s2; 
    for(int i = 0; i < (int) s1.size(); i++){
        
    }
    

    
    return 0;
}

