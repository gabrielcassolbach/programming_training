#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define MAX 26

int main(){
    fastio; 
    int t; cin >> t; 
    while(t--){
        string s, t, ans; cin >> s >> t; 
        vector<int> fs, ft; fs.resize(26, 0); ft.resize(26, 0);

        bool has_ans = true;
        int ans_size = t.size();

        for(int i = 0; i < (int) s.size(); i++) fs[s[i] - 'a']++;
        for(int i = 0; i < (int) t.size(); i++) ft[t[i] - 'a']++;

        for(int i = 0; i < MAX; i++){
            ft[i] -= fs[i];
            
            if(ft[i] < 0){
                has_ans = false;
            }
        }

        t = "";

        for(int i = 0; i < MAX; i++) {
            if(ft[i]) 
                for(int j = 0; j < ft[i]; j++)
                    t += i + 'a';    
        }

        sort(t.begin(), t.end());

        ans = "";
        int i, j; i = j = 0;
        while((int) ans.size() < ans_size){
            if((i < (int) s.size() && s[i] <= t[j]) || j >= (int) t.size()){
                ans += s[i];
                i++;
            }else{
                ans += t[j];
                j++;
            }
        }
        if(has_ans)
            cout << ans << "\n";
        else
            cout << "Impossible\n";
    }

    return 0; 
}



