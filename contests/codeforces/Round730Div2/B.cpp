#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 212345

typedef long long ll;

int n; ll v[MAX];

ll answer(ll sum){
    float media = ((float)sum/(float)n);
    //if(ceil(media) == floor(media)) return 0;
    return (sum % n)*(n - (sum % n));
}

int main(){
    ll sum = 0, ans = 0;
    int t; cin >> t;
    while(t--){ 
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        } 
        cout << answer(sum) << endl;
        sum = 0;
    }
    return 0;
}

