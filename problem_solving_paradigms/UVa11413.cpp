#include "bits/stdc++.h"
using namespace std;
#define MAX 1123

// Fill the Containers.

/*  1 2 3 4 5   */ 
/*
    a = c[0] && b = c[n - 1].

 (1 2 3) (4) (5). -> best 6. 
    {6}  {4} {5}

 (1 2) (3 4) (5) || (1 2) (3) (4 5). -> best 7.
  {3}   {7}  {5}     {3}  {3}  {9}
  
  (1) (2 3 4) (5) || (1) (2) (3 4 5) || (1) (2 3) (4 5). -> best 9. 
  {1}   {9}   {5}    {1} {2}  {12}      {1}  {5}   {9}
*/


int best_division(int n, int m, int* c){
    

}

int main(){
    int n, m, c[MAX];
    while(scanf("%d", &n) != EOF){
        scanf("%d", &m);
        for(int i = 0; i < m; i++) 
            scanf("%d", &c[i]);
        printf("%d\n", best_division(n, m, c));
    }
    return 0;
}