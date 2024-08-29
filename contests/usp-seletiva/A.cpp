#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 10000010

typedef long long ll; 

struct Guests {
    ll m;
    ll c;
    ll ind;
};

ll n, menor = MAX;
vector<Guests> times;

vector<ll> ans;

queue<Guests> q;

void read(){
    cin >> n; times.resize(MAX);
    for(int i = n; i < MAX; i++) {
        times[i].c = -1;
        times[i].m = 0;
    }
    for(int i = 0; i < n; i++){
        Guests a; ll tim; cin >> tim;
        cin >> a.m >> a.c;
        a.ind = i + 1;
        times[tim] = a;
        menor = min(menor, tim);
    }
}

void print_queue() {
    queue<Guests> tmp_q = q;

    while(!tmp_q.empty()){
        cout << tmp_q.front().ind << " " << tmp_q.front().m << " " << tmp_q.front().c << endl;
        tmp_q.pop();
    }
    cout << endl;
}

void solve() {
    Guests g = {
        0, 1, 1
    };
    for (int i = menor; i < 10; i++) { 
        cout << i << " " << g.m << endl;
        
        if (g.m != 0)
            g.m--;
        if (times[i].c == 0){
            cout << "zero" << endl;
            q.push(times[i]);
        } 
        if (times[i].c == 1) {
            cout << "um" << endl;
            for (ll j = 0; j < q.size(); j++)
            {
                ans.push_back(q.front().ind);
                q.pop();
            }
            q.push(times[i]);
        }
        if (g.m == 0) {
            q.pop();
            g = q.front();
        }
        print_queue();
    }
}

void print_ans() {
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main(){ _
    read();
    solve();
    print_ans();
    return 0;
}