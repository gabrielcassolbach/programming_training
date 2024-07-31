#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAX 12

typedef long long ll;

char matrix[MAX][MAX];
pair<int, int> pi;

void print();

void read(){    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            matrix[i][j] = 0;
    //print();
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 'B')
                {pi.first = i; pi.second = j;}
        }
    }
    //print();
}

void bfs(){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, pi});
    pair<int, int> p;
    while(!q.empty()){
        p = q.front().second;
        int d = q.front().first;
        q.pop();

        if(matrix[p.first][p.second] == 'L')
            {cout << d - 1 << endl; return;}

        matrix[p.first][p.second] = '0';

        if(matrix[p.first + 1][p.second] == '.' || matrix[p.first + 1][p.second] == 'L' ){
            q.push({d+1, {p.first + 1, p.second}}); 
        }
        if(matrix[p.first - 1][p.second] == '.' || matrix[p.first - 1][p.second] == 'L'){
            q.push({d+1, {p.first - 1, p.second}});
        }
        if(matrix[p.first][p.second + 1] == '.' || matrix[p.first][p.second + 1] == 'L'){
            q.push({d+1, {p.first, p.second + 1}});
        }
        if(matrix[p.first][p.second - 1] == '.' || matrix[p.first][p.second - 1] == 'L'){
            q.push({d+1, {p.first, p.second - 1}});
        }
    }

}

void print(){
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}

int main(){
    _;
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    read();
    bfs();
    //print();
    return 0;
}