#include <bits/stdc++.h>

using namespace std;

int dayToInt(const string& s){
    if(s=="Mon") return 0;
    if(s=="Tue") return 1;
    if(s=="Wed") return 2;
    if(s=="Thu") return 3;
    if(s=="Fri") return 4;
    if(s=="Sat") return 5;
    return 6;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // State machine
    static const int nextState[5] = {2, 3, 4, 0, 0};
	// Qntd de dias para nova renovacao por dia da semana
    static const int cycleDays[5] = {30, 30, 30, 32, 31};
    const int MAX_K = 31; // 2^30 > 10^9/30
    static int state_table[MAX_K][5]; // estado depois de 2^k transicoes
    static long long days_table[MAX_K][5]; // dias consumidos por essas transicoes

    for(int s = 0; s < 5; ++s){
        state_table[0][s]   = nextState[s];
        days_table[0][s] = cycleDays[s];
    }

    for(int k = 1; k < MAX_K; ++k){
        for(int s = 0; s < 5; ++s){
            int binary_aux = state_table[k-1][s];
            state_table[k][s] = state_table[k-1][binary_aux];
            days_table[k][s] = days_table[k-1][s] + days_table[k-1][binary_aux];
        }
    }

    string today; 
    int n;
    cin >> today >> n;
    int t = dayToInt(today);

    int answer = INT_MAX;
    while(n--){
        long long D;
        cin >> D;

		// Dia inicial
        int c = (t - int(D % 7) + 7) % 7;

		if (D == 0) {
			answer = min(answer, cycleDays[c]);
			continue;
		}

        long long val_left = D; // dias restantes
        int state = c;

        for(int k = MAX_K-1; k >= 0; --k){
            if(state < 5 && days_table[k][state] <= val_left){
                val_left -= days_table[k][state];
                state  = state_table[k][state];
            }
        }

        int wait;
        if(val_left == 0){
            if(t == 5)       wait = 2;
            else if(t == 6)  wait = 1;
            else             wait = 0;
        } else {
            wait = cycleDays[state] - int(val_left);
        }
        answer = min(answer, wait);
    }

    cout << answer << "\n";
    return 0;
}