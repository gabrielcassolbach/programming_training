#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; vector<int> v(n);

    int ans = 1, best_ans = 1;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1] + 1){
            ans++;
        }else{
            ans = 1;
        }
        best_ans = max(best_ans, ans); 
    }

    cout << best_ans << "\n";
    return 0;
}