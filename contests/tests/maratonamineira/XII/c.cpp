#include <bits/stdc++.h>

using namespace std;

int translate(string s) {
    char a = s[0], b = s[1];
    switch(a) {
        case '4':
            if(b == 'P')
                return 14;
            return 1;
        case '5':
            return 2;
        case '6':
            return 3;
        case '7':
            if(b == 'C')
                return 13;
            if(b == 'O')
                return 11;
            return 4;
        case 'Q':
            return 5;
        case 'J':
            return 6;
        case 'K':
            return 7;
        case 'A':
            if(b == 'E')
                return 12;
            return 8;
        case '2':
            return 9;
        case '3':
            return 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<vector<int>> cards(4);

    for(int player = 0; player < 4; player++) {
        for(int j = 0; j < 3; j++) {
            string s; cin >> s;
            cards[player].push_back(translate(s));
        }

        sort(cards[player].begin(), cards[player].end());
    }

    for(int round = 0; round < 3; round++) {
        int winner_card = 0;
        int winner_group = 0;
        for(int turn = 0; turn < 4; turn++) {
            if(turn % 2) { // impar é dupla B/D
                if(winner_group == 2 || *cards[turn].rbegin() <= winner_card) { // estao ganhando ou a maior carta nao vence
                    if(winner_card == *cards[turn].begin() && winner_group != 2)
                        winner_group = 0;
                    //cout << "deleting: " << *cards[turn].begin() << "\n";    
                    cards[turn].erase(cards[turn].begin()); // joga carta mais baixa
                }
                else {
                    winner_group = 2;
                    winner_card = *cards[turn].rbegin();
                    // cout << winner_group << ":" << winner_card << " ";
                    //cout << "deleting: " << *(cards[turn].end()-1) << "\n";
                    cards[turn].erase((cards[turn].end()-1)); // joga carta mais alta
                }
            }
            else { // dupla A/C
                if(winner_group == 1 || *cards[turn].rbegin() <= winner_card) { // estao ganhando ou a maior carta nao vence
                    if(winner_card == *cards[turn].begin() && winner_group != 1)
                        winner_group = 0;
                    //cout << "deleting: " << *cards[turn].begin() << "\n";
                    cards[turn].erase(cards[turn].begin()); // joga carta mais baixa
                }
                else {
                    winner_group = 1;
                    winner_card = *cards[turn].rbegin();
                    // cout << winner_group << ":" << winner_card << " ";
                    //cout << "deleting: " << *(cards[turn].end()-1) << "\n";
                    cards[turn].erase((cards[turn].end()-1)); // joga carta mais alta
                }
            }
        }

        cout << winner_group << " ";
    }

    cout << "\n";

    return 0; 
}
