#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1000000/2

int n;

vector<int> primos_ax, primos;
map<int, int> max_k;
vector<int> active_steps;

void crivo(){
    primos_ax.resize(MAX, 1);
    cout << "MAX: " << MAX << '\n';
    for(int i = 2; i < MAX; i++){
        if(primos_ax[i] == 0) continue;
        for(int j = i; j < MAX; j += i)
            primos_ax[j] = 0;
        primos.push_back(i);
        max_k[i] = 0;
    }
}

int main(){
    fastio;
    crivo();

    cin >> n;

    while(n--){
        int d;
        cin >> d;
        auto pos = find(active_steps.begin(), active_steps.end(), d);
        if(pos!= active_steps.end()){
            active_steps.erase(pos);
            int primo_atual = 0;
            while(primos[primo_atual] <= d){
                if(d % primos[primo_atual] == 0){
                    //cout << "Diminui: " << primos[primo_atual] << "\n";
                    max_k[primos[primo_atual]]--;
                }
                primo_atual++;
            }
        }
        else{
            active_steps.push_back(d);
            int primo_atual = 0;
            while(primos[primo_atual] <= d){
                if(d % primos[primo_atual] == 0){
                    //cout << "Aumenta: " << primos[primo_atual] << "\n";
                    max_k[primos[primo_atual]]++;
                }
                primo_atual++;
            }
        }
    
        int mk = 0;
        for(auto element : max_k){
            if(mk < element.second)
                mk = element.second;
        }
        cout << mk << "\n";

    }

    return 0;
}