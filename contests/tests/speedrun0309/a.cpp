#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; vector<int> v(n);
    
    int sum = 0;
    for(int i = 0; i < n; i++)
        {cin >> v[i]; sum += v[i];} 

    for(int i = 0; i < n; i++){
        if((sum%(n-i)) == 0){
            cout << i << '\n';
            return 0;
        }
    }    
    return 0;
}