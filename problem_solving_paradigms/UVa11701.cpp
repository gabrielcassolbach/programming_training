#include <bits/stdc++.h>
using namespace std;

#define EPS  0.00001
#define DIFF 0.002

double base_three (double m){
    double sum = 0;  int digit = 0; double n = m;
    for(int i = 1; i <= 6 && (abs(n) > EPS); i++){
        digit = (floor)((n * (pow(10, i))) + 0.001); 
        sum += (pow(3, -(i)) * digit); 
        n -= (digit / (pow(10, i)));   
    }
    return sum;
}

bool member(double number){
    double a = 0; double b = 1; double m = (a + b) / ((double)2);
    int cont = 0;
    while(cont != 40){
        cont++;
        //printf("m: %lf\n", m); printf("p_value: %lf\n", base_three(m));
        if(fabs(base_three(m) - number) < EPS)
            return true;
        if(base_three(m) > number){
            b = m; 
            m = (a + b) / ((double) 2);
        }else{
            a = m; 
            m = (a + b) / ((double) 2);
        }
    } 
    return false;   
}

int main(){
    double tc;
    while(scanf("%lf", &tc) != EOF){
        if(member(tc)) printf("MEMBER\n");
        else printf("NON-MEMBER\n");
    }
    return 0;
}
