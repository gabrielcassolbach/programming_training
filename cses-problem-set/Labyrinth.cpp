#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define BIG 12345678

typedef struct {
    int x;
    int y;
} point;

point a, b;
char lab[MAX][MAX]; int mp[MAX][MAX]; bool vis[MAX][MAX];
int n, m;

void setVis(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            vis[i][j] = false;
}

bool inMap(int x, int y){
    return(x >= 1 && x <= n && y >= 1 && y <= m);
}

void print(stack<char> &path){
    printf("YES\n");
    printf("%d\n",(int)path.size());
    while(!path.empty()){
        printf("%c", path.top());
        path.pop();
    }
    printf("\n");
}

void findAns(){
    setVis();
    stack<char> path;
    point p = b; 
    while(p.x != a.x || p.y != a.y){
        int best_choice = BIG; point next_p = p; int cord;

        vis[p.x][p.y] = true;

        if(inMap(p.x + 1, p.y) && (mp[p.x + 1][p.y] < best_choice) && (mp[p.x + 1][p.y] != -1) && !vis[p.x + 1][p.y])
            {cord = 1; best_choice = mp[p.x + 1][p.y]; next_p.x = p.x + 1; next_p.y = p.y;}

        if(inMap(p.x - 1, p.y) && (mp[p.x - 1][p.y] < best_choice) && (mp[p.x - 1][p.y] != -1) && !vis[p.x - 1][p.y])
            {cord = 2; best_choice = mp[p.x - 1][p.y]; next_p.x = p.x - 1; next_p.y = p.y;}

        if(inMap(p.x, p.y + 1) && (mp[p.x][p.y + 1] < best_choice) && (mp[p.x][p.y + 1] != -1) && !vis[p.x][p.y + 1])
            {cord = 3; best_choice = mp[p.x][p.y + 1]; next_p.x = p.x; next_p.y = p.y + 1;}

        if(inMap(p.x, p.y - 1) && (mp[p.x][p.y - 1] < best_choice) && (mp[p.x][p.y - 1] != -1) && !vis[p.x][p.y - 1])
            {cord = 4; best_choice = mp[p.x][p.y - 1]; next_p.x = p.x; next_p.y = p.y - 1;}
        
        if(cord == 1) path.push('U'); // D
        if(cord == 2) path.push('D'); // U
        if(cord == 3) path.push('L'); // R
        if(cord == 4) path.push('R'); // L
        
        p = next_p;
    }
    print(path);
}


void bfs(){
    queue<point> q; q.push(a);
    while(!q.empty()){
        point c = q.front(); q.pop(); 
        point ac;

        if(inMap(c.x + 1, c.y) && (lab[c.x + 1][c.y] == '.') && (!vis[c.x + 1][c.y]))
            {ac.x = c.x + 1; ac.y = c.y; q.push(ac); mp[ac.x][ac.y] = mp[c.x][c.y] + 1; vis[c.x + 1][c.y] = true;}

        if(inMap(c.x - 1, c.y) && (lab[c.x - 1][c.y] == '.') && (!vis[c.x - 1][c.y]))
            {ac.x = c.x - 1; ac.y = c.y; q.push(ac); mp[ac.x][ac.y] = mp[c.x][c.y] + 1; vis[c.x - 1][c.y] = true;}

        if(inMap(c.x, c.y + 1) && (lab[c.x][c.y + 1] == '.') && (!vis[c.x][c.y + 1]))
            {ac.x = c.x; ac.y = c.y + 1; q.push(ac); mp[ac.x][ac.y] = mp[c.x][c.y] + 1; vis[c.x][c.y + 1] = true;}

        if(inMap(c.x, c.y - 1) && (lab[c.x][c.y - 1] == '.') && (!vis[c.x][c.y - 1]))
            {ac.x = c.x; ac.y = c.y - 1; q.push(ac); mp[ac.x][ac.y] = mp[c.x][c.y] + 1; vis[c.x][c.y - 1] = true;}
    }
}

void init(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            {mp[i][j] = -1; vis[i][j] = false;}
    mp[a.x][a.y] = 0;
}

void read(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("\n%c", &lab[i][j]);
            if(lab[i][j] == 'A') 
                {a.x = i; a.y = j;}
            if(lab[i][j] == 'B')
                {b.x = i; b.y = j;} 
        }
    }
}

bool hasAns(){
    if(inMap(b.x + 1, b.y) && mp[b.x + 1][b.y] != -1)
        return true;
    if(inMap(b.x - 1, b.y) && mp[b.x - 1][b.y] != -1)
        return true;
    if(inMap(b.x, b.y + 1) && mp[b.x][b.y + 1] != -1)
        return true;
    if(inMap(b.x, b.y - 1) && mp[b.x][b.y - 1] != -1)
        return true;
    return false;
}

int main(){
    read();
    init();
    bfs();
    if(hasAns())
        findAns();
    else
        printf("NO\n");
    return 0;
}