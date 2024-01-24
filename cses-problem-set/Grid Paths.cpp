#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1001

typedef long long ll;

int n;
int maze[MAX][MAX];
int dp[MAX][MAX];

void printMaze(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << maze[i][j];
        cout << endl;
    }
}

void printMemory(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << dp[i][j] << "   ";
        cout << endl;
    }
}


void init(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = 0;
}

void read(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == '.')
                maze[i][j] = 1;
            else 
                maze[i][j] = 0;
        }
    }     
}

ll ans(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            

        }              
    }
    return dp[n][n];
}

int main(){
    read();
    init();
    //printMaze();
    cout << ans() << endl;
    printMemory();
    return 0;
}