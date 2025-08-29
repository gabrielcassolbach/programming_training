#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
int s;

ll rec(int it, int b){
    if(b == 0 && it == s+1) return 1;
    if(b < 0 || it == s+1) return 0;

    ll ans = 0;
    for(int i = 0; i <= b; i++){
        ans += rec(it+1, b-i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int b; cin >> s >> b;   
    cout << rec(1, b-s) << "\n";
    return 0;
}