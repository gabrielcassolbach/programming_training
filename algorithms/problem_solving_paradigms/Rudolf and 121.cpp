#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int n; vector<ll> a;

void answer(){
    for(int i = 0; i < n-2; i++){
        if(a[i] < 0) break;
        a[i+1] -= 2*a[i];
        a[i+2] -= a[i];
        a[i] -= a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i])
            {cout << "NO" << endl; return;}
    }
    cout << "YES" << endl; return ;
}

int main(){
    int t; cin >> t; 
    while(t--){
        cin >> n; 
        a.resize(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        answer();
        a.clear();
    }
    return 0;
}

