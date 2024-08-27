#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

map<string, ll> m;

int main() {
    ll n; cin >> n; 
    ll c; cin >> c; 
    for (ll i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        ll pos = str.find("*");
        for (char l = 'a'; l <= 'z'; l++)
        {
            string new_str = str;
            new_str[pos] = l;
            m[new_str]++;
        }
    }

    ll M = 0;

    //sort(m.begin(), m.end());

    string ans = "";

    for (auto it = m.begin(); it != m.end(); it++)
    {
        //cout << it->first << " " << it->second << endl;
        if(it->second > M) {
            //cout << "aqui" << it->second << endl;
            M = it->second;
            ans =  it->first;
        }else if (it->second == M) {
            ans = min(ans, it->first);
        }
    }

    cout << ans << " " << M << endl;
    
    return 0;
}