#include "bits/stdc++.h"
using namespace std;
#define MAX 19
// Greedy Algorithm. -> UVa410 - Station Balance.
// ----------------------------------------------
int containers[5][5]; double imbalance;

void set_imbalance(int c, double average){
    int test_case;
    for(int i = 0; i < c; i++){
        printf("SET #%d\n", i+1);
        printf(" %d:", i);
        test_case = 0;
        for(int j = 0; j < 2; j++){
            if(containers[i][j]) {
                test_case += containers[i][j];
                printf(" %d", containers[i][j]);
            }
        }
        printf("\n");
        imbalance += ((double)test_case - average);                   
    }
    printf("IMBALANCE = %.6lf\n", imbalance);
    imbalance = 0;
}

void set_containers(int* weights, int n, int c){
    int a = 0; int b = n - 1; int value;
    for(int i = 0; i < c; i++){
        value = weights[a];
        for(int j = 0; j < 2; j++){
            if(value) containers[i][j] = value;
            value = weights[b];
        }
        a++; b--;
    }
}

void best_division(int s, int c, int* weights, double average){
    int n = s; 
    if(s < (2*c)) n = (s + ((2*c) - s));
    sort(weights, weights + n);
    set_containers(weights, n, c);
    set_imbalance(c, average);
}

void set_parameters(int* weights){
    imbalance = 0;
    memset(weights, 0, sizeof weights); 
    memset(containers, 0, sizeof containers);
}

int main(){
    int s, c, weights[MAX];
    double average;
    while(scanf("%d", &c) != EOF){
        scanf(" %d", &s);
        average = 0;
        for(int i = 0; i < s; i++) {scanf("%d", &weights[i]); average += weights[i];}
        set_parameters(weights);
        best_division(s, c, weights, average/(3.0));
    }
    return 0;
}
