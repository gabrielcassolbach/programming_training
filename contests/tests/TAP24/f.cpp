#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int score = 0;
    int streak = 0;

    while(n--){
        int a;
        cin >> a;

        if(a == 1){
            streak++;
            score++;
            if(streak >= 3)
                score++;
        }
        else{
            streak = 0;
            score--;
        }
    }

    cout << score << "\n";

}