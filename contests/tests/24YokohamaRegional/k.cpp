#include <bits/stdc++.h>
using namespace std;

#define inf 2123456

vector<int> v, dict, dp; 
int n, m;

int rec(int set){
    if(dp[set] != -1)
        return dp[set];

    if(set == ((1 << m) - 1)) 
        return dp[set] = (dict[set] != inf ? set : 0);

    int r = (dict[set] != inf) ? set : 0;
    
    for(int i = 0; i < m; i++){
        if(set & (1 << i)) continue; 
        int new_r = rec(set | (1 << i));
        
        if(__builtin_popcount(new_r) > __builtin_popcount(r))
            r = new_r;
        else if(__builtin_popcount(new_r) == __builtin_popcount(r))
            r = dict[new_r] < dict[r] ? new_r : r;
        
    }

    return dp[set] = r; 
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    
    dp.resize(1 << m, -1); dict.resize(1 << m, inf);
    
    int mask = (1 << m) - 1;
    pair<int, int> ans = make_pair(-1, -1);

    for(int i = 0; i < n; i++){
        string s; cin >> s; 
        
        int val = 0; 
        for(int j = (int) s.size() - 1; j >= 0; j--)
            if(s[j] == 'Y')
                val += (1 << ((int) s.size() - 1 - j));
        
        if(dict[val] != inf && ans.first == -1 && val == mask)
            ans = make_pair(dict[val], i+1);
           

        if(dict[val] == inf){ 
            dict[val] = i+1;
            v.push_back(val);
        }
    }
    
    if(ans.first != -1){
        cout << ans.first << " " << ans.second << "\n";
        return 0;
    }        
 
    int best_count = -1; 
    for(int i = 0; i < (int) v.size(); i++){
    
        if(v[i] == mask) continue;
        int best_comp = rec((~v[i]) & mask);
        if(best_comp == 0) continue;

        int first = min(dict[v[i]], dict[best_comp]);
        int second = max(dict[v[i]], dict[best_comp]);

        int count = __builtin_popcount(v[i] & best_comp);
        
        if(count > best_count){    
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
