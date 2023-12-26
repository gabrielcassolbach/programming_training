#include "bits/stdc++.h"
using namespace std;

#define MAX 10
// Greedy Algorithm. -> UVa410 - Station Balance.
// Solution by: https://github.com/milderhc/competitive-programming
// ----------------------------------------------

int mass[MAX]; int cases = 1;

void print_answer(double sum, int c, double diff){
    printf("SET #%d\n", cases++);
    for(int i = 0; i < c; i++){
        printf(" %d:", i);
        if(mass[i]) printf(" %d", mass[i]);
        if(mass[2*c - 1 - i]) printf(" %d", mass[2*c - 1 - i]);
        printf("\n");
        diff += fabs(sum - fabs(mass[i] + mass[2*c - 1 - i]));
    }
    printf("IMBALANCE = %.5lf\n\n", diff);
}

int main(){
    int c, s;
    double sum;
    while(scanf("%d", &c) != EOF){
        sum = 0;
        scanf(" %d", &s); 
        for(int i = 0; i < s; i++) {scanf("%d", &mass[i]); sum += mass[i];} 
        for(int i = s; i < (2*c); i++) mass[i] = 0;
        sort(mass, mass + (2*c)); 
        sum = sum / ((double)c); 
        print_answer(sum, c, 0);
    }
}
