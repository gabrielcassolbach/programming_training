#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X;
    cin >> n >> X;

    unordered_map<int,int> freq;
    freq.reserve(n);
    for(int i = 0, b; i < n; i++){
        cin >> b;
        freq[b]++;
    }

    // max‐heap by frequency
    priority_queue<pii> pq;
    for(auto &p : freq)
        pq.push({p.second, p.first});

    vector<int> ans;
    ans.reserve(n);

    while(!pq.empty()){
        auto [c1,v1] = pq.top(); pq.pop();
        if(ans.empty() || ans.back() + v1 != X){
            ans.push_back(v1);
            if(--c1) pq.push({c1,v1});
        } else {
            if(pq.empty()){
                cout << "*\n";
                return 0;
            }
            auto [c2,v2] = pq.top(); pq.pop();
            ans.push_back(v2);
            if(--c2) pq.push({c2,v2});
            pq.push({c1,v1});
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << (i+1<n ? ' ' : '\n');
    return 0;
}
