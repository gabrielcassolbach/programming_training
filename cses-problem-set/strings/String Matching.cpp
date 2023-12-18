#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
char a[MAX], b[MAX];
int size_a, size_b, matches;

int caracter(char c){
    return (c >= 'a' && c <= 'z');
}

void read(){
    int i = 0, j = 0; 
    scanf("%c", &a[i]);
    while(caracter(a[i])) {i++; scanf("%c", &a[i]);}
    scanf(" %c", &b[j]);
    while(caracter(b[j])) {j++; scanf("%c", &b[j]);}
    size_a = i; size_b = j; printf("%d %d\n", size_a, size_b);
}

int main(){
    read();
    matches = 0;
    if(size_b > size_a) {printf("%d\n", matches); return 0;}
    int j = 0;
    for(int i = 0; i < size_a; i++){
        //printf("(%c|%c) %d & %d\n", a[i], b[j], j, size_b);
        if(a[i] == b[j]){
            j++;
            //printf("%d & %d\n", j, size_b); getchar();
            if(j == size_b) 
                {matches++; j = 0;}
        }else{
            j = 0;
        }
    }
    printf("%d\n", matches);
    return 0;
}