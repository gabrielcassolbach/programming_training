#include <bits/stdc++.h>
using namespace std;
#define MAX 9
#define MAX2 21234

int n; 
int restr[MAX][MAX];
string board;
int mem[2][MAX2];

bool check(int player) {
    char p = '0'+player;
    if((board[0] == p && board[1] == p && board[2] == p) ||
       (board[3] == p && board[4] == p && board[5] == p) ||
       (board[6] == p && board[7] == p && board[8] == p) ||
       (board[0] == p && board[3] == p && board[6] == p) ||
       (board[1] == p && board[4] == p && board[7] == p) ||
       (board[2] == p && board[5] == p && board[8] == p) ||
       (board[0] == p && board[4] == p && board[8] == p) ||
       (board[2] == p && board[4] == p && board[6] == p))
    {
        return true;
    }
    return false;
}

int hash_board(){
    int val = 0; 
    for(int i = 0, b = 1; i < 9; i++, b *= 3){
        val += (board[i]-'0')*b;
    }   
    return val;
}

int solve(int player) {
    int &ans = mem[player-1][hash_board()];
    if(ans != -1) return ans;
    if(check(player^3)) return ans = player^3;
    ans = player^3;
    bool no_moves = 1;
    for(int i = 0; i < 9; i++){
        if(board[i] != '0') continue;
        bool ok = 1;
        for(int j = 0; j < 9; j++){
            if(!restr[i][j]) continue;
            ok &= board[j] != '0';
        }
        if(ok) {
            board[i] = '0'+player;
            int a = solve(player^3);
            board[i] = '0';
            no_moves = 0;
            if(a == 0) ans = 0;
            else if(a == player) {
                ans = player;
                break;
            }
        }
    }
    if(no_moves) ans = 0;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; 
    memset(restr, 0, sizeof restr);
    memset(mem, -1, sizeof mem);
    board = "000000000";
    while(n--) {
        int a, b; cin >> a >> b;
        restr[--b][--a] = 1;
    }
    int ans = solve(1); 
    cout << (ans == 1 ? "X\n" : (ans == 0 ? "E\n" : "O\n"));
    return 0;
}
