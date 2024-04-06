#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll a, b, c;

void answer(){
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            for(int k = 0; k <= 3; k++){
                if(j + i + k > 3)
                    continue;
                if(!(a%(i+1)) && !(b%(j+1)) && !(c%(k+1))){
                    if((a/(i+1)) == (b/(j+1))  && (b/(j+1)) == (c/(k+1))){
                        cout << "yes" << endl; return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> a >> b >> c;
        answer();
    }
    return 0;
}