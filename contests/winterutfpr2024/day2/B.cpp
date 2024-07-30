#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    if(n % 4 == 1 || n % 4 == 3){
        cout << "Either" << endl;
    }else if(n % 4 == 2){
        cout << "Odd" << endl;
    }else if(n % 4 == 0){
        cout << "Even" << endl;
    }
    return 0;
}