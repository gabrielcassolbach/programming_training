#include "bits/stdc++.h"
using namespace std;
#define MAX 61

// Dart-a-Mania.
// -------------

typedef struct{
    int a;
    int b;
    int c;
} Combinations;

int range[MAX], perm = 0, comb = 0; 
vector<int> p_values; 
vector<Combinations> used_values;

void create_range(){
    memset(range, 0, sizeof range);
    for(int i = 1; i <= 20; i++)
        {range[i] = 1; range[i*2] = 1; range[i*3] = 1;}
    range[50] = 1; range[0] = 1;
    for(int i = 0; i < MAX; i++)
        if(range[i]) p_values.push_back(i);
}

void print_answer(int n){
    if(!perm){
        printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    }else{ 
        printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
        printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
    }
    for(int i = 0; i < 70; i++) printf("*");
    printf("\n");
}

void clean_used_values(){
    while(!used_values.empty())
        used_values.pop_back();
}

bool used_combination(int val1, int val2, int val3){
    int check[3]; bool a, b, c;
    check[0] = val1; check[1] = val2; check[2] = val3;
    for(int i = 0; i < used_values.size(); i++){    
        a = b = c = false;
        for(int j = 0; j < 3; j++){
            if((check[j] == used_values[i].a) && !a) a = true;
            else if((check[j] == used_values[i].b) && !b) b = true;
            else if((check[j] == used_values[i].c) && !c) c = true;
        }
        if(a && b && c) return true;
    }
    return false;       
}

void add_combination(int val1, int val2, int val3){
    Combinations new_combination;
    new_combination.a = val1; new_combination.b = val2; new_combination.c = val3;
    used_values.push_back(new_combination);
}

void save (int val1, int val2, int val3){
    if(!used_combination(val1, val2, val3)) 
        {add_combination(val1, val2, val3); comb++;}
}

int main(){
    int n;
    create_range(); 
    scanf("%d", &n);  
    while (n > 0){
        perm = 0; comb = 0; clean_used_values();
        for(int i = 0; i < p_values.size(); i++)
            for(int j = 0; j < p_values.size(); j++)
                for(int k = 0; k < p_values.size(); k++)
                    if(!(n - (p_values[i] + p_values[j] + p_values[k])))
                        {save(p_values[i], p_values[j], p_values[k]); perm++;}
        print_answer(n);
        scanf("%d", &n);  
        if(n <= 0) printf("END OF OUTPUT\n");
    }
    return 0;
}
