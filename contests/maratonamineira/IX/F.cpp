#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int g; 
vector<char> v; 

void read(){
    cin >> g;
    char c; 
    while(scanf("\n%c", &c) != EOF)
        {v.push_back(c);}
}

void answer(){
    int max_p, max_n; 
    max_p = 0; max_n = 0;
    int ans = 0;    
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 'D')
            ans += g;
        else 
            ans -= g;
        max_p = max(max_p, ans);
        max_n = min(max_n, ans);
    }
    if(max_p + abs(max_n) >= 360)
        cout << "S" << endl;
    else 
        cout << "N" << endl;
}

int main(){ 
    read();
    answer();
    return 0;
}
