#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 212345

int main(){
    int n; cin >> n;
    vector<int> v; v.resize(n);
    int pos[MAX];
    int counter = 1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pos[v[i]] = counter;
        counter++;
    }
    int ans = 1;
    for(int i = 1; i <= n; i++)
        if(pos[i-1] > pos[i])
            ans++;
    cout << ans << endl;
    return 0;
}
