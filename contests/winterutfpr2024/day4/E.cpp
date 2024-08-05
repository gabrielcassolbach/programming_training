#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAX 32123

int v[MAX];
int memo[MAX];
int value[MAX];
int n; 

void solve(){
    int a, b;
    int i; // primeira linha.
    for(int j = 1; j <= n; j++){
        cin >> a >> b;
        i = b; // 3. 
        int counter = 1;
        while(b == i && counter <= n){ // i = 2;
            //cout << "-->" << a << " " << b << endl;
            v[a] = 1;
            cin >> a >> b;
            counter++;
        }
        //for(int i = 0; i < 10; i++)
        //    cout << v[i] << " ";
        //cout << endl;
        for(int k = 1; k < 10; k++){
            memo[k] += max(memo[k-1], memo[k]) + v[k];
            if(v[k]) value[memo[k]]++;
            //cout << k << " " << value[memo[k]] << endl;
        }
    }
}

void init(){
    cin >> n;
    for(int j = 0; j < MAX; j++)
        {v[j] = 0; memo[j] = 0; value[j] = 0;}
}

int main(){
    _
    init();
    solve();
    for(int i = 0; i < n; i++) cout << value[i] << endl;
    return 0;
}