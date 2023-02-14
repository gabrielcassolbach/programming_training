// Fractions Again - UVa10976.
#include <bits/stdc++.h>
using namespace std;

#define MAX 123456
#define EPS 0.000001

typedef struct{
    int a;
    int b;
} Pair;

vector <Pair> v; int cont; 

bool check(int n, int x, int y){
    double ans = 1.0 / (double) n;
    double p_ans = ((1.0) / (double) x) + ((1.0) / (double) y);
    if((ans - p_ans) < EPS) return true;
    return false;
}

bool used(int x, int y){
    for(int i = 0; i < (int) v.size(); i++)
        if((v[i].a == x || v[i].a == y) && (v[i].b == x || v[i].b == y)) 
            return true;
    return false;
}

bool integer(double n){
    double diff = (n - (int)n);
    if(diff > EPS) return false; 
    return ((int) n);  
}

int calc(int n, int x){
    double up_fraction, down_fraction;
    up_fraction = abs(x - n);  down_fraction = (x*n);
    if(up_fraction != 1)
        down_fraction = (down_fraction / up_fraction);
    if(!integer(down_fraction)) return -1;
    return (int) down_fraction;
}

int teste(int n, int x){
    int y = calc(n, x);
    if(y != -1) return y;
    return -1;
}

void solutions(int n){
    int y; Pair value;  
    for(int x = MAX; x > n; x--){
        y = teste(n, x);
        if(y != -1 && !(used(x, y)) && check(n, x, y)){
            cont++;            
            value.a = x; value.b = y; 
            v.push_back(value); 
        }
    }
}

void set_parameters(){
    v.clear(); cont = 0;
}

bool compare (Pair one, Pair two) {return (one.a  > two.a);}

void set_solutions(int n){
    for(int i = 0; i < v.size(); i++)
        if(v[i].a < v[i].b)
            {int aux = v[i].a; v[i].a = v[i].b; v[i].b = aux;}
    sort(v.begin(), v.end(), compare);
}

void print_solutions(int n){
    printf("%d\n", cont);
    set_solutions(n);    
    for(int i = 0; i < v.size(); i++)
        printf("1/%d = 1/%d + 1/%d\n", n, v[i].a, v[i].b);
}

int main(){
    int tc;
    while(scanf("%d", &tc) != EOF) {
        set_parameters();
        solutions(tc); 
        print_solutions(tc);
    }
    return 0;
}
