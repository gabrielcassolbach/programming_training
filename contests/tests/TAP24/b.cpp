#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 
    vector<int> div(n/2+1, 0);
    vector<int> real_div; 

    for(int i = 2; i <= n/2; i++){
        if(div[i] == 1){
            // checa se há multiplos de i divisores de n
            if(i+i <= n/2 && div[i+i] == 1){
                div[i] = 0;
            }
        }
        if(n % i == 0) {
            div[i] = 1;
            for(int j = i+i; j <= n/2; j+= i){
                if(n % j == 0){
                    div[i] = 0;
                    div[j] = 1;
                }
            }
        }
    }
    for(int i = 1; i < div.size(); i++){
        if(div[i]) real_div.pb(i);
    }  

    if(real_div.size() == 0){
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
        return 0; 
    }
    
    cout << real_div.size() << "\n";
    
    for(auto divisor : real_div){
        cout << 1 << " " << divisor << "\n";
    }   

    return 0;
}

