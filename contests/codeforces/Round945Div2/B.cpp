#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> v;
vector<ll> a, b;
int n; // lenght of array v.

/*
n -> 10⁵
t -> 10⁴
--------
8
0 1 3 2 2 1 0 3

-> (0 | 1) -> (1 | 3) -> (3 | 2)
-> 

0 1 3 2 2 1 0 -> 3
1 3 2 2 1 0 3 -> 3

-> {0 1 3 2 2 1 0}
. (0 | 1) = 0

0 | 1 => 1.
1 | 3 => 3.

*/

ll answer(){
    if(n == 1) return 1; 

    ll a, b; a = b = 0;

    for(int i = 1; i <= n; i++){
        a = b = 0;
        for(int j = 0; j < n-1; j += i){
            a = 

        }


    }


    return n;   
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n; 
        v.resize(n + 1);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cout << answer() << endl;
        v.clear();
    }   
    return 0;
}