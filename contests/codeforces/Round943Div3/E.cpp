#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 

        cout << 1 << " " << n << endl;
        cout << 1 << " " << n-1 << endl;
        
        for(int i = 0; i < n-2; i++){
            cout << n-i << " " << i + 1 << endl;
        }

        cout << endl;    

    }

    return 0;
}