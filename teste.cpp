#include <bits/stdc++.h>
using namespace std;
#define MAX 100000/2

vector<int> primos, light, v;
int n;

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
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n; v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    





    



    return 0;
}