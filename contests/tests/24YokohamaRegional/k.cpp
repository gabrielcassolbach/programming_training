#include <bits/stdc++.h>
using namespace std;

vector<int> v;
map<int, int> dict; 
int n, m;
vector<int> dp;

int rec(int set){
    if(dp[set] != -1)
        return dp[set];

    if(set == ((1 << m) - 1)) 
        return dp[set] = (dict.find(set) != dict.end() ? set : 0);

    int r = dict[set] ? set : 0;
    for(int i = 0; i < m; i++){
        if(set & (1 << i)) continue; 
        r = max(r, rec(set | (1 << i)));
    }

    return dp[set] = r; 
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m; set<int> unique_v; 
    dp.resize(1 << m, -1);

    for(int i = 0; i < n; i++){
        string s; cin >> s; 
        
        int val = 0; 
        for(int j = (int) s.size() - 1; j >= 0; j--)
            if(s[j] == 'Y')
                val += (1 << ((int) s.size() - 1 - j));
        
        if((i + 1) == 232){
            cout << s << "\n";
        } 
        if(dict.find(val) == dict.end()){
            if((i + 1) == 232){
                cout << s << "\n";
                cout << "aqui\n";
            } 
            dict[val] = i+1;
            v.push_back(val);
        }
    }
    
    int mask = (1 << m) - 1;
    int best_count = -1; pair<int, int> ans = make_pair(-1, -1);
    for(int i = 0; i < (int) v.size(); i++){

        if(v[i] == mask) continue;
        int best_comp = rec((~v[i]) & mask);
        if(v[i] == 32763) cout <<  "test: " << best_comp << "\n";

        if(best_comp == 0) continue;

        int first = dict[v[i]];
        int second = dict[best_comp];

        int count = __builtin_popcount(v[i] & best_comp);
        if((first == 232 && second == 144) || (second == 232 && first == 144)) {
            cout << "------->count: " << count << "----\n";
            cout << "--->first: " << first << "\n";
            cout << "->second: " << second << "\n";
        }
        if(count > best_count){;    
            best_count = count;
            ans = make_pair(first, second);
        }else if(count == best_count){
        
            

            if(first < ans.first)
                ans = make_pair(first, second);
            else if(first == ans.first && second < ans.second)
                ans = make_pair(first, second);
        }

    }

    if(ans.first != -1)
        cout << ans.first << " " << ans.second << "\n";
    else
        cout << "No\n";

    return 0;
}
