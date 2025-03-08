#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 123

vector<int> v;

int main(){
    int t; cin >> t;
    int n, f, k; int nf, nk;
    while(t--){
        cin >> n >> f >> k; v.resize(n + 10);
        for(int i = 0; i < n; i++) cin >> v[i];
        nf = v[f-1];
        sort(v.begin(), v.end(), greater());
        nk = v[k-1]; int f1 = 0, f2 = 0; 
        //cout << "nf" << nf << " nk" << nk << endl;
        for(int i = 0; i < k; i++){
            if(v[i] == nf) f1 = 1;
            //cout << v[i] << " ";
        }
        //cout << "aa" << " ";
        for(int i = k; i < n; i++){
            if(v[i] == nf) f2 = 1;
            //cout << v[i];
        }
    
        if(f1 && f2) cout << "Maybe" << endl;
        else if(f1) cout << "Yes" << endl;
        else cout << "No" << endl;
        v.clear();
    }
    return 0;
}