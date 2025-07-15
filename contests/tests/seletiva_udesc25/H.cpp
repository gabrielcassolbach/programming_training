#include <bits/stdc++.h>
using namespace std;

int calculate_ps (vector<pair<int, vector<int>>> v, int i){
    if(v[i].second.empty())
        return v[i].first;
    
    int sum = v[i].first;
    for(auto u: v[i].second){
        sum += calculate_ps(v, u);
    }

    v[i].first = sum;

    return sum;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, vector<int>>> actors_profit; //first -> profit; second -> vector of children   

    for(int i = 0; i < n; i++){
        int profit; cin >> profit;
        actors_profit.push_back(make_pair(profit,vector<int>()));
    }

    for(int i = 1; i < n; i++){
        int parent; cin >> parent;
        actors_profit[parent-1].second.push_back(i); 
    }

    calculate_ps(actors_profit, 0);

    int max_node_profit_sum = 0;
    for(int i = 0; i < actors_profit.size(); i++){
        if(actors_profit[i].first > max_node_profit_sum)
            max_node_profit_sum = actors_profit[i].first;
    }

    if(max_node_profit_sum == 0){
        cout << 0 << "\n";
        return 0;
    }

    cout << max_node_profit_sum << "\n";

    return 0; 
}