#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 512345

int main(){
    int n; cin >> n;
    char p, pant = 'x'; int energia = 0; int pulos = 0;
    for(int i = 0; i < n; i++){
        cin >> p;
        if (p == 'x' && pant == '.'){
            pulos++;
            energia = 0;
        } 
        if (p == 'x') {
            energia++;
        } else {
            if(energia == 0) {cout << -1 << endl; return 0;}
            energia--;
        }
        pant = p;
    }
    cout << pulos << endl;
    return 0;
}
