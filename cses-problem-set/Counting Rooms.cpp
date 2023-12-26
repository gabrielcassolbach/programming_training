#include <bits/stdc++.h>
using namespace std;

using wv = pair<int, int>;
#define MAX 1123

typedef struct{ 
    int vis;
    char value;
} cells;
 
int n, m;
cells matrix[MAX][MAX]; queue<pair<int, int>> q; 

int bfs(int i, int j){
    matrix[i][j].vis = 1;
    q.push(wv(i, j));
    
    while(!q.empty()){
        pair<int, int> p; p = q.front(); q.pop();        

        if(matrix[p.first + 1][p.second].value == '.' && matrix[p.first + 1][p.second].vis == 0)
            {q.push(wv(p.first + 1, p.second)); matrix[p.first + 1][p.second].vis = 1;}
        
        if(matrix[p.first - 1][p.second].value == '.' && matrix[p.first - 1][p.second].vis == 0)
            {q.push(wv(p.first - 1, p.second)); matrix[p.first - 1][p.second].vis = 1;}
        
        if(matrix[p.first][p.second + 1].value == '.' && matrix[p.first][p.second + 1].vis == 0)
            {q.push(wv(p.first, p.second + 1)); matrix[p.first][p.second + 1].vis = 1;}
        
        if(matrix[p.first][p.second - 1].value == '.' && matrix[p.first][p.second - 1].vis == 0)
            {q.push(wv(p.first, p.second - 1)); matrix[p.first][p.second - 1].vis = 1;}
        
    }
    return 1;
}

void answer(){
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j].value == '.' && !matrix[i][j].vis)
                ans += bfs(i, j);   
    printf("%d\n", ans);
}

void read(){
    scanf("%d %d", &n, &m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &matrix[i][j].value); 
            matrix[i][j].vis = 0;
        }
    }
}

int main(){
    read();
    answer();
    return 0;
}