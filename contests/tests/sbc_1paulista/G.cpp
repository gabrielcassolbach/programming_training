#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
    fastio;
    string a;
    cin >> a; 
    string sub2 = a.substr(3, 5);
    if(sub2 == "SP") cout << "S\n";
    else if((sub2[0] == 'S' && sub2[1] == '?') || (sub2[0] == '?' && sub2[1] == 'P')) 
        cout << "T\n";
    else
        cout << "N\n";
    return 0;
}