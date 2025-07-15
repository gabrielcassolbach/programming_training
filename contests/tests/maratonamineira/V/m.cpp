#include <bits/stdc++.h>
using namespace std;

int main(){
    int score = 0;
    int bonus = 0;

    for(int i = 0; i < 10; i++){
        string s;
        cin >> s;

        if(s[0] == 'X'){
            score += 10;

            if(s.size() > 1){
                
            }

            cout << "score: " << score << "\n";

            bonus = 2;

            continue;
        }

        if(s.find("/") <= s.size() -1){
            score += 10;

            if(bonus == 1){
                score += (int) s[0]-'0';
                bonus--;
            }
            else if(bonus == 2){
                score += 10;
                bonus = 0;
            }

            bonus = 1;

            cout << "score: " << score << "\n";
            continue;
        }

        score += (int) s[0]-'0' + (int) s[1]-'0';

        if(bonus == 1){
            score += (int) s[0]-'0';
        }

        if(bonus == 2){
            score += (int) s[0]-'0' + (int) s[1]-'0';
        }

        cout << "score: " << score << "\n";
        bonus = 0;
     }

    cout << score << "\n";

    return 0; 
}
