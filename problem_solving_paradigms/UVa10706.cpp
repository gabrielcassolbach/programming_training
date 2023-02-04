#include <bits/stdc++.h>
using namespace std;

#define ARRAY_LENGHT 100000

// 10706 - Number Sequence.
// ------------------------

int p_answers[ARRAY_LENGHT]; int cont;

void set_array() {for(int i = 0; i < ARRAY_LENGHT; i++) p_answers[i] = i + 1;}

long int get_distance(int n) 
    {return ((p_answers[0] + p_answers[n])*(n+1))/2;}

long int binary_search(int number){
    long int a = 0; long int b = ARRAY_LENGHT; long int m = (a + b) / 2;
    printf("entrou no binary search\n");
    int count = 0;
    while(a < b){
        count++;
        printf("looping..."); printf("a: %ld & b: %ld & m: %ld\n", a, b, m);
        printf("distance: %ld\n", get_distance(m));
        if(count == 10) return m;
        if(get_distance(m) == number) return m;
        if(get_distance(m) < number)
            {a = m; m = ceil((a+b)/2);}
        if(get_distance(m) > number)
            {b = m; m = floor((a+b)/2);}
    }
    return m;
}

void position (int number){
    printf("entrou position\n");
    int pos = binary_search(number);
    printf("position: %d\n", pos);
}  

int main(){
    int t; long int number = 0;
    scanf("%d", &t);
    set_array();
    while(t--){
        scanf("%ld", &number);
        printf("number: %ld\n", number);
        printf("Chamou position\n");
        position(number);
        printf("saiu position\n");
    }
    return 0;
}


