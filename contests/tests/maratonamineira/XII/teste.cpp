#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> cards = {1, 2, 3, 4};

    cards.erase(cards.end()-1);
    for(int i = 0; i < (int) cards.size(); i++)
        cout << cards[i] << " ";

    cout << "\n";

    return 0; 
}
