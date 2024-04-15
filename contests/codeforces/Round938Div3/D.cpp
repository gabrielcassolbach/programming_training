#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1123456

int n, m, k;
vector<int> a; vector<int> b;
vector<int> memo_b;

void read(){
    cin >> n >> m >> k; 
    a.resize(n + 100); b.resize(m + 100); memo_b.resize(MAX);
    for(int i = 0; i < m; i++)
        memo_b[i] = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++){
        cin >> b[i];
        memo_b[b[i]] = 1;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int ans = 0, has_sub;
        read();
        for(int i = 0; i < n; i++){
            has_sub = 1;
            for(int j = i; j < (i+k); j++){
                cout << a[j] << ' ';
                if(memo_b[a[j]] == 0) has_sub = 0;
            }
            if(has_sub) ans++;
            cout << ' ' << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
11 5 3
9 9 2 2 10 9 7 6 3 6 3
6 9 7 8 10

-> 2 2 3 3 6 6 (7 (9 (9) 9) 10)



*/




