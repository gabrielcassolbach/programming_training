#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    arr<arr<bool>> requisites(9, arr<bool>(9, false));
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        requisites[b][a] = true;
    }
    string b = "EEEEEEEEE";
    auto verify_win = [&](char p) {
        if((b[0] == p && b[1] == p && b[2] == p) ||
           (b[3] == p && b[4] == p && b[5] == p) ||
           (b[6] == p && b[7] == p && b[8] == p) ||
           (b[0] == p && b[3] == p && b[6] == p) ||
           (b[1] == p && b[4] == p && b[7] == p) ||
           (b[2] == p && b[5] == p && b[8] == p) ||
           (b[0] == p && b[4] == p && b[8] == p) ||
           (b[2] == p && b[4] == p && b[6] == p))
        {
            return true;
        }
        return false;
    };
    auto find_moves = [&](char p) {
        arr<int> moves;
        for(int i = 0; i < 9; ++i) {
            if(b[i] != 'E') continue;
            bool all_requisites = true;
            for(int j = 0; j < 9 && all_requisites; ++j) {
                if(!requisites[i][j]) continue;
                all_requisites &= b[j] != 'E';
            }
            if(all_requisites) moves.push_back(i);
        }
        return moves;
    };
    arr<arr<char>> dp_mem(2, arr<char>(3.1e4, '\0'));
    auto hash_b = [&]() {
        int res = 0;
        for(int i = 0, a = 1; i < 9; ++i, a *= 3) {
            int digit = b[i] == 'E' ? 0 : (b[i] == 'X' ? 1 : 2);
            res += digit*a;
        }
        return res;
    };
    fun<char (char)> dp = [&](char p) {
        char &res = dp_mem[p == 'X'][hash_b()];
        if(res != '\0') return res;
        char other_p = p == 'X' ? 'O' : 'X';
        if(verify_win(other_p)) return res = other_p;
        auto moves = find_moves(p);
        if(moves.empty()) return res = 'E';
        bool any_win = false, any_tie = false;
        for(int move : moves) {
            b[move] = p;
            char next_res = dp(p);
            if(next_res == p) {
                any_win |= true;
            } else if(next_res == 'E') {
                any_tie |= true;
            }
            b[move] = 'E';
        }
        return res = any_win ? p : (any_tie ? 'E' : other_p);
    };
    cout << dp('X') << '\n';
    return 0;
}
