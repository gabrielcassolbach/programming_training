#include <bits/stdc++.h>
using namespace std;

#define EPS 0.0001

bool number(double n){
    if(n >= 0 && n <= 1) return true;
    return false;
}

bool member(double number){
    int cont = 0;
    double a = 0, b = 1, size, m1, m2;
    while(cont != 20){
        cont++; 
        size = (b - a) / 3.0;
        m1 = a + size; m2 = b - size;
        if((fabs(number - b) <= EPS) || (fabs(number - a) <= EPS)) return true;
        if(number <= m1) b = m1;
        else if(number >= m2) a = m2;
        else return false;
    } 
    return false;
}

int main(){
    double tc;
    while(scanf("%lf", &tc) && number(tc)){
        if(member(tc)) printf("MEMBER\n");
        else printf("NON-MEMBER\n");
    }
    return 0;
}
