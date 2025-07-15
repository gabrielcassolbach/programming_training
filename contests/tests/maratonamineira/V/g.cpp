#include <bits/stdc++.h>
using namespace std;

set<int> primos;
set<int> divisores; 
 
void crivo(int p){
    vector<int> eh_primo;
    eh_primo.resize(p + 1, 1);
    for(int i = 2; i <= p; i++){
        if(eh_primo[i] == 0) continue;
        for(int j = i+i; j <= p; j += i){
            eh_primo[j] = 0;
        }
        primos.insert(i);
    }
}
 
void get_div(int val, auto it){
    if(val == 1) {divisores.insert(1); return;}
    if(primos.find(val) != primos.end()){
        divisores.insert(1);
        divisores.insert(val);
        return;
    }
    for(auto primo : primos){
        if(primo*primo > val) break;
        int res = val%(primo) == 0 ? 1 : 0;
        if(res){
            get_div(val/(primo), it++);
            divisores.insert(val/(primo));
            divisores.insert((primo));
        }
    }
}

int solve(string s, int t_size) {
    string new_s = s;
    //cout << "new_s.size(): " << new_s.size() << '\n';
    while(new_s.size() != 0) {
        //cout << "aqui..." << '\n';
        string s1 = new_s.substr(0, t_size);
        string s2 = new_s.substr(new_s.size() - t_size, t_size);    
        //new_s = new_s.substr(t_size, new_s.size() - 2*t_size);
        new_s.erase(0, t_size);
        new_s.erase(new_s.size() - t_size, t_size);
        if(s1 != s2)
            return 0;
    }
    return 1;
}

int main(){
    string s; cin >> s;
    crivo((s.size()));
    //cout << "s.size(): " << s.size() << '\n';
    int val = s.size();
    divisores.insert(val);
    get_div(val, primos.begin());
    auto it = divisores.rbegin();
    for(; it != divisores.rend(); it++){
        int ans = solve(s, s.size()/(*it));
        if(ans) {cout << *it << '\n'; break;}
    }
    return 0; 
}
