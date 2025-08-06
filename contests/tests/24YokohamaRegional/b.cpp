#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string toBinary(ll n){
    string count = "";
    while(n) {
        count += (n%2) == 1 ? '1' : '0';
        n /= 2;
    }
    reverse(count.begin(), count.end());   
    return count;
}   

ll toDecimal(string s){
    ll value = 0;
    for(int i = (int) s.size() - 1; i >= 0; i--){
        if(s[i] == '1')
            value += (1ll << (((int) s.size() - 1) - i));
    }
    return value;
}

ll countDigits(string s){
    ll counter = 0;
    for(int i = 0; i < (int) s.size(); i++){
        if(s[i] == '1') counter++;
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    
    if(a == b){
        cout << a << "\n";
        return 0;
    }

    for(int i = 0; i <= 60; i++){
        ll val = 1ll << i;      
        if(val >= a && val <= b){
            cout << val << "\n";
            return 0;
        }
        if(val > b) 
            break;
    }
    string digA, digB, digC;
    digA = toBinary(a);
    digB = toBinary(b);

    int i = 0;
    while(digA[i] == digB[i])
        i++;

    while(digA[i] == '0' && digB[i] == '1'){
        ++i;
    }

    digC = digA;
    digC[i-1] = '1';
    for(int j = i; j < (int) digA.size(); j++)
        digC[j] = '0';

    if(countDigits(digA) <= countDigits(digC))
        cout << a << "\n";
    else
        cout << toDecimal(digC) << "\n";
    

    return 0;
}

