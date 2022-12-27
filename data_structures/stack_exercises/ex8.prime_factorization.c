#include <stdio.h>
#include "stack.c"

void imprime(Stack* p){
    int cont = 0;
    while(!(vazia(p))){
        cont++;
        if(cont == 1) printf("%d", pop(p));
        else printf(" * %d", pop(p));
    }
    printf("\n");
}

int computa_primo(Stack* p, int n){
    int new_number = n;
    for(int i = 2; i <= n; i++){
        if(n%i == 0){
            push(p, i);
            new_number = n / i;
            return new_number;
        }
    }
    return -1;
}

void prime_factorization(int n){
    Stack* p = create(n);
    while(!(n == 1)){
        n = computa_primo(p, n);
    }
    imprime(p); 
    destroy(p);
}

int main(){
    int n;
    scanf("%d", &n);
    prime_factorization(n);
    return 0;
}