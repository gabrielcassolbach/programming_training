#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1002

typedef long long ll;

typedef struct {
    ll x;
    ll y;
    ll p;
} Point;

int values[MAX][MAX];
int n, m, t, ci, cj;
queue<Point> f;
int cont = 0;

void read(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            values[i][j] = -1;
        }
    }
    cin >> n >> m >> t >> ci >> cj;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char val;
            cin >> val;
            if(val == '#')
                values[i][j] = -1;
            else 
                values[i][j] = -2; 
        }
    }
    values[ci][cj] = 0;
    Point p{ci, cj, 0};
    f.push(p);
}

void bfs(){
    while (!f.empty() ) {
        Point p = f.front();
        f.pop();
        if (values[p.x + 1][p.y] == -2) {
            values[p.x + 1][p.y] = p.p + 1;
            Point p2{p.x + 1, p.y, p.p+1};
            f.push(p2);
        }
        if (values[p.x][p.y + 1] == -2) {
            values[p.x][p.y + 1] = p.p + 1;
            Point p2{p.x, p.y + 1, p.p+1};
            f.push(p2);
        }
        if (values[p.x][p.y - 1] == -2) {
            values[p.x][p.y - 1] = p.p + 1;
            Point p2{p.x, p.y - 1, p.p+1};
            f.push(p2);
        }
        if (values[p.x-1][p.y] == -2) {
            values[p.x - 1][p.y] = p.p + 1;
            Point p2{p.x - 1, p.y, p.p+1};
            f.push(p2);
        }
    }
}

int main(){
    read();
    bfs();
    ll a = 0, b = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){ 
            if (values[i][j] >= 0 && values[i][j] <= t) {
                a++;
            } 
            if (values[i][j] >= 0 || values[i][j] == -2 ) {
                b++;
            }
        }
    }
    cout << a / gcd(a, b) << " " << b / gcd(a, b) << endl; 
    return 0;
}