#include <bits/stdc++.h>
using namespace std;

int main(){

    int m, val; cin >> m; 
    while(scanf("%d", &val) != EOF){
        if(val < 0.95*m) 
            printf("Calma que ainda tem o returno.\n"); 
        else if(val > 1.05*m)
            printf("Athelera, fera!\n");
        else
            printf("Boa! Merece cafe e pao de queijo.\n");
    }

    return 0;
}