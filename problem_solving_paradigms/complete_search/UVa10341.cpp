#include "bits/stdc++.h"
using namespace std;
#define EPS 0.000001

int p, q, r, s, t, u;

bool positive(double value){
    if(value  >= 0) return true;
    return false;
}

bool sinals(double fa, double fd){
    if(positive(fa) && positive(fd)) return true; 
    return false;
}

double f(double d) 
    {return (p*exp(-d) + q*sin(d) + r*cos(d) + s*tan(d) + t*pow(d, 2) + u);}

double solve_it(){
    double x, a = 0, b = 1, d;
    while(a < b){
        d = (a+b)/2.0; x = f(d);
        if(fabs(x) < EPS) return d;
        if(sinals(f(a), f(d))) a = (a+b)/2.0;
        else b = (a+b)/2.0;
    }
    return -1;
}

int main(){
    double ans;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
        ans = solve_it();
        if(ans < 0) printf("No solution\n");
        else printf("%.4lf\n", ans);
    }
    return 0;
}