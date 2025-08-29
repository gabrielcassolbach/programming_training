#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; getline(cin, s);

    string aux = "";
    for(int i = 0; i < (int) s.size(); i++){
        if(s[i] == ' ')
            aux = "";
        else
            aux += tolower(s[i]);
        if(aux == "athletico" || aux == "furacao"){
            cout << "E da-lhe Athletico!\n";
            return 0;
        }
    }

    cout << "Grrrrr! CAP! CAP! CAP!" << "\n";

    return 0;
}