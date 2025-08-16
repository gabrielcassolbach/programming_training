#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int n, c, t;
vector<int> v;

int test_limit(ll m){
    int qtd_comp = c; 
    int sub = 0, max_sub = 0; 
    for(int i = 0; i < n; i++){
        if(sub + v[i] <= m || qtd_comp == 1){
            sub += v[i];
        }else{
            max_sub = max(max_sub, sub);
            sub = v[i];
            qtd_comp--;
        }
    }
    return max_sub = max(max_sub, sub);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> c >> t;  
    v.resize(n); 

    for(int i = 0; i < n; i++)
        cin >> v[i];
     
    int a, b; a = 1; b = (1 << 30); 
    int ans = (1 << 30);
    while(a <= b){
        int m = (a+b)/2;
        int max_val = test_limit((ll)m*t);
        if(max_val > m){
            a = m+1;
        }else{
            ans = min(ans, max_val);
            b = m-1; 
        }
    }

    cout << ans << "\n";

    return 0; 
}