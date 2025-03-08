#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 123

int letters[MAX];

void init(){
    for(int i = 0; i < MAX; i++)
        letters[i] = 0;
}

void solve(){
    int counter = 1; int ans = 0;
    for(int i = 0; i < 27; i++){
        if(letters[i] >= counter)
            ans++;
        counter++;
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        init();
        for(int i = 0; i < n; i++){
            char val; cin >> val;
            letters[val - 'A']++;
        }
        solve();
    }
    return 0;
}