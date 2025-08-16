#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int v, n; cin >> v >> n;
    int tot = v*n;
    for(int i = 1; i <= 9; i++)
        cout << (int)ceil(tot*i*1e-1L) << (i == 9 ? "\n" : " ");
    return 0; 
}