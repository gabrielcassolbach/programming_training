#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m; 
string x, s;

void read(){
    cin >> n >> m;  
    cin >> x >> s;
}

int answer(){
    int counter = 6;
    int op = 0;
    while(counter--){
        if(x.find(s) != string::npos)
            return op;
        op++;
        x += x;
    }
    return -1;
}

int main(){
    int t; cin >> t;
    while(t--){
        read();
        cout << answer() << endl;
    }
    return 0;
}
