#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> b;

int findElement(ll value, int end_value){
    for(int i = 0; i < b.size(); i++)
        if((i != (b.size() - end_value)) && b[i] == value)
            return i;
    return -1;
}

int hasAns(int end_value){
    ll sum = 0; ll check_sum = b[b.size() - end_value];

    for(int i = 0; i < b.size(); i++){
        if(i != b.size() - end_value)
            sum += b[i];
    }
    
    int index = findElement(sum - check_sum, end_value);
   
    if(index != -1)
        {b.erase(b.begin() + index); return 1;}
    else
        {return 0;}
}

void answer(){
    bool ans = 1;
    sort(b.begin(), b.end());
    
    ans = hasAns(1);
    if(!ans) 
        ans = hasAns(2);
        
    if(ans){
        for(int i = 0; i < b.size() - 1; i++)
            cout << b[i] << ' ';
        cout << endl;
    }else 
        {cout << -1 << endl;}
}

void read(){
    ll n; cin >> n;
    b.clear();
    for(int i = 0; i < n+2; i++){
        ll value; cin >> value;
        b.push_back(value);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        read();
        answer();
    }
    return 0;
}