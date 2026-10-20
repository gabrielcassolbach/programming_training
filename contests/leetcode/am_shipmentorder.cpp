#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

class Solution {
public:
    std::vector<int> maximize_shipment_order(const std::vector<int>& shipment_order, int window_size) {
        vector<int> result = shipment_order;
        int n = result.size();
        stack<pair<int, int>> st; 
        
        vector<int> memo; memo.assign(n, -1);

        st.push({0, result[0]});

        for(int i = 1; i < (int) result.size(); i++){
            while(!st.empty() && st.top().second > result[i]){
                pair<int, int> p = st.top(); 
                memo[p.first] = i;
                st.pop();
            }
            st.push({i, result[i]});
        }

        int best_w_i = 0; int best_idx = -1; 
        for(int i = 0; i <= (int) result.size() - window_size; i++){
            int idx = INF;

            for(int j = i; j < i + window_size; j++)
                if(memo[j] != -1 && memo[j] < i + window_size) 
                    idx = min(idx, j);

            if(idx > best_idx){
                best_w_i = i;
                best_idx = idx;
            }
        }
        
        sort(result.begin() + best_w_i, result.begin() + best_w_i + window_size);
        return result;
    }
};

