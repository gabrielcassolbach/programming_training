#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

string upper(string name) {
    string aux = "";
    for(int i = 0; i < name.size(); i++){
        aux += toupper(name[i]);
    }
    return aux;
}

int main() {
    fastio;
    string v[7];
    v[0] = "What is the name of your team?";
    v[1] = "Our name is ";
    v[2] = "My apologies, I did not understand. What is your team name?";
    v[3] = "We are team ";
    v[4] = "I am really sorry. Could you please repeat it once again?";
    v[5] = "WE ARE TEAM ";
    v[6] = "Oh, now I see. Here are your badges. Good luck!";
    
    string name;
    getline(cin, name);
    string end_s = ".";

    for(int i = 0; i < 7; i++){
        if(i == 5) {name = upper(name); end_s = "!!!";}
        if(i % 2 == 1){
            cout << v[i] << name << end_s << '\n';
        }else
            cout << v[i] << '\n';
    }
    return 0;
}