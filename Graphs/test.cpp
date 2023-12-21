#include <bits/stdc++.h>
using namespace std;

#define MAX 512345

int n, m, edges[10][10], vis[10], ans[10];

void bfs(){
    memset(vis, 0, sizeof(vis)); memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vector<int> component; queue<int> q;
            q.push(i);
            while(!q.empty()){
                int x = q.front(); q.pop();
                if(!vis[x]){
                    vis[x] = 1; component.push_back(x);
                    for(int i = 0; i < 10; i++)
                        if(edges[x][i] && !vis[i])
                            q.push(i);
                }
            }
            for(int y : component)
                ans[y] = component.size();
            component.clear();
        }
    }
}

void read(){
    int k, aux; vector<int> v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &k);
        for(int j = 0; j < k; j++)
            {scanf("%d", &aux); v.push_back(--aux);}
        for(int j = 0; j + 1 < k; j++)
            {edges[v[j]][v[j + 1]] = 1; edges[v[j + 1]][v[j]] = 1;}
        v.clear();
    }
}

int main(){
    read();
    bfs();
    for(int i = 0; i < n; i++) 
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
