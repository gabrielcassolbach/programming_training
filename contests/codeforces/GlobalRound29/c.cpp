#include <bits/stdc++.h>
using namespace std;

bool check(string s, int n){
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            int j = i + 1, count_ones = 0;

            while(j < n && s[j] == '1')
                {j++; count_ones++;}
            
            if(count_ones >= 2)
                return false;

            if(s[j-1] == '1' && j == n)
                return false;
            
        }
    }
    return true;
}

string solve(){
    int n; cin >> n;
    string s, aux; cin >> s; 
    
    aux = s;
    aux[0] = aux[n-1] = '1';

    bool has_solution = check(aux, n);

    if(has_solution == false){
        aux = s;
        aux[n-1] = '1';
        has_solution = check(aux, n);
    }

    if(has_solution == false){
        aux = s;
        aux[0] = '1';
        has_solution = check(aux, n);
    }

    if(has_solution == false){
        aux = s;
        has_solution = check(aux, n);
    }
    
    return (has_solution ? "YES" : "NO");
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; 
    while(t--)
        cout << solve() << "\n";
    return 0;
}