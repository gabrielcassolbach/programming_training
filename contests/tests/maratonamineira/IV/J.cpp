#include <bits/stdc++.h>
using namespace std;

map<string, int> pos, neg;

bool isChar(char c) {return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');}

string lowerCase(string s){
    string l_s = "";
    for(int i  = 0; i < (int) s.size(); i++)
        if(isChar(s[i]))
            l_s += (char) tolower((int) s[i]);
        else 
            l_s += s[i];
    return l_s;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string name; cin >> name;
    name = lowerCase(name);

    int qt_p; cin >> qt_p;
    while(qt_p--){
        string s; cin >> s; 
        s = lowerCase(s);
        pos[s] = 1;
    }
    
    int qt_n; cin >> qt_n;
    while(qt_n--){
        string s; cin >> s; 
        s = lowerCase(s);
        neg[s] = 1;
    }

    int ans_pos = 0, ans_neg = 0, ans_neuter = 0;

    int q; cin >> q;
    string s; getline(cin, s);
    for(int i = 0; i < q; i++){
        getline(cin, s); 
        int qtd_pos = 0, qtd_neg = 0;
        bool has_name = false;

        for(int i = 0; i < (int) s.size(); i++){
            string aux = ""; 
            while(i < (int) s.size() && s[i] != ' '){
                aux += s[i];
                i++;
            }
            aux = lowerCase(aux);

            if(aux == name) has_name = true;
            if(pos.find(aux) != pos.end()) qtd_pos++;
            if(neg.find(aux) != neg.end()) qtd_neg++;
        }
        
        if(has_name){
            if(qtd_neg == qtd_pos) ans_neuter++;
            if(qtd_neg > qtd_pos) ans_neg++;
            if(qtd_neg < qtd_pos) ans_pos++;
        }
    }

    cout << ans_pos << " " << ans_neuter << " " << ans_neg << "\n";

    return 0;
}
