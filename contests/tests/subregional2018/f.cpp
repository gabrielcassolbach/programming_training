#include <bits/stdc++.h>
using namespace std;

struct state {
    int end, val;
};

struct event {
    int id, begin, end, value;
};

bool event_comp(event &e1, event &e2) {
    return e1.end >= e2.end;
}

void debug(vector<vector<state>> memo){
    for(int i = 0; i < (int) memo.size(); i++){
        cout << i << " :";
        for(int j = 0; j < (int) memo[i].size(); j++){
            cout << "(" << memo[i][j].end << " " << memo[i][j].val << ")"; 
        }
        cout << "\n";
    }

}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 

    vector<event> s;
    vector<vector<state>> memo(1 << n); 

    int mask = (1 << n) - 1; 

    for(int i = 0; i < n; i++){
        int m; cin >> m; 
        for(int j = 0; j < m; j++){
            int a, b, c; cin >> a >> b >> c; 
            s.push_back({i, a, b, c});            
        }
    }

    sort(s.begin(), s.end(), event_comp);
    memo[0].push_back({0, 0});

    while(s.size()){
        event sw = s.back();
        s.pop_back();

        for(int i = 1; i <= mask; i++){
            if((i & (1 << sw.id)) == 0)  
                continue; 

            int r = -(1 << 30);

            if(memo[i].size())
                for(auto elem : memo[i])
                    if(elem.end <= sw.begin)
                        r = max(r, elem.val + sw.value);

            if(memo[(i ^ (1 << sw.id))].size())
                for(auto elem : memo[(i ^ (1 << sw.id))])
                    if(elem.end <= sw.begin)
                        r = max(r, elem.val + sw.value);

            if(r != -(1 << 30))
                memo[i].push_back({sw.end, r});

            debug(memo);
        }
    }

    int ans = -1;
    if(memo[mask].size())
        for(auto elem : memo[mask])
            ans = max(ans, elem.val);    

    cout << ans << "\n";

    return 0;
}