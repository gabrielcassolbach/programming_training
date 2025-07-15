#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int a; cin >> a;
    vector<set<char>> days; days.resize(6, set<char>());

    vector<char> needs_extraction;

    string week_input[6];
    cin >> week_input[0] >> week_input[1] >> week_input[2] >> week_input[3] >> week_input[4] >> week_input[5];

    for(int i = 0; i < 6; i++){
        for(auto c : week_input[i])
            days[i].insert(c);
    }

    for(int i = 1; i < a; i++){
        cin >> week_input[0] >> week_input[1] >> week_input[2] >> week_input[3] >> week_input[4] >> week_input[5];

        for(int j = 0; j < 6; j++){
            needs_extraction.clear();
            for(auto c : days[j])
                if(week_input[j].find(c) > week_input[j].size() - 1){
                    // cout << "extracting " << c << ": " << week_input[j].find(c) << "\n";
                    // days[j].extract(c);
                    needs_extraction.push_back(c);
                }
            for(auto c : needs_extraction)
                days[j].erase(c);
        }
    }

    for(int i = 0; i < 6; i++){
        for(auto c : days[i])
            cout << c;
        cout << " ";
    }
    cout << "\n";

    return 0; 
}