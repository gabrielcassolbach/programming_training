#include <bits/stdc++.h>
using namespace std;

int main(){
    
    map<string, string> m; 
    vector<string> ans;
    ans.push_back("Nao e a mamae"); /// eh pai
    ans.push_back("nao e o Nao e a mamae"); // nao eh pai
    int r, v; cin >> r >> v; 
    set<string> pai;
    string s1; 
    getline(cin, s1);

    for(int i = 0; i < r; i++){
        string s;
        getline(cin, s);

        pai.insert(s);
        //cout << s << "\n";
    }


    for(int i = 0; i < v; i++){
        string s;
        getline(cin, s);

        //cout << "entrada: " << s << "\n";

        if(pai.find(s) == pai.end())
            cout << ans[1] << "\n";
        else
            cout << ans[0] << "\n";
    }

    return 0; 
}