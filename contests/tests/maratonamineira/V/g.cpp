#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

bool comp(int n1, int n2){
    return n1 >= n2;
}

int main() {
    fastio;
    string s; cin >> s; 
    int n = s.size();

    vector<int> divs; 
    for(int d = 1; d*d <= n; d++){
        if(n % d == 0){
            divs.push_back(d);
            if(d != n/d) 
                divs.push_back(n/d);
        }
    }

    sort(divs.begin(), divs.end(), comp);
    for(int k : divs){
        int len = n/k;
        bool ok = true;
        for(int j = 0; j < k/2; j++){
            if(s.compare(j*len, len, s, (k-1-j)*len, len) != 0)
                {ok = false; break;}
        }
        if(ok){
            cout << k << '\n';
            break;
        }
    }

    return 0;
}