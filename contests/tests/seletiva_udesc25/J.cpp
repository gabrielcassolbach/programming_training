#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    vector<char> corridor;

    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        corridor.push_back(c);
    }

    for(int i = 0; i < k; i++){
        auto it = find(corridor.begin(),corridor.end(),'.');
        if(it != corridor.end())
            corridor.erase(it);
    }

    int missingDots = n - corridor.size();

    //vector<char> dots; dots.resize(missingDots, '.');

    for(int i = 0; i < missingDots; i++)
        cout << '.';
    
    for(auto c: corridor)
        cout << c;

    cout << "\n";

    return 0; 
}