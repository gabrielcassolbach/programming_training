#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int n, k;

struct event {
    bool t;
    int x1;
    int x2;
};

vector<event> v; 

bool ord(event a, event b) {
    return a.x1 == b.x1 ? a.t > b.t : a.x1 < b.x1;
}

int solve() {
    int cont = 0, ans = 0; 
    map<int, int> freq;

    for(int i = 0; i < v.size(); i++){
        if(v[i].t  == 0) {
            if(cont < k) freq[v[i].x2]++, cont++; 
            else{
                auto it = --freq.end();
                int larger_end = it->first;
                freq[larger_end]--;
                if(!freq[larger_end]) freq.erase(larger_end);
                freq[min(larger_end, v[i].x2)]++;
            }
        }else { 
            if(freq.find(v[i].x1) != freq.end()){
                freq[v[i].x1]--; cont--; ans++;
                if(!freq[v[i].x1]) freq.erase(v[i].x1);
            }
        }
    }
    return ans;
}

int main(){
    fastio; 
    cin >> n >> k; 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.pb({0, a, b}); v.pb({1, b, -1});
    }
    sort(v.begin(), v.end(), ord);
    cout << solve() << '\n';
    return 0;
}