#include <stdio.h>
#include "stack.c"

void init(Stack* x, char* c){
    int i = 0;
    while(!(full(x))){
        push(x, c[i]);
        i++;
    }
}

void copy(Stack* x, Stack* y, char* c){
    Stack* aux = create(strlen(c));
    int value;
    while(!(vazia(x))){
        push(aux, pop(x));
    }
    while(!(full(x))){
        value = pop(aux);
        push(x, value);
        push(y, value); 
    }
    destroy(aux);
}

int compara(Stack* x, Stack* y){
    int a; int b;
    while(!(vazia(x))){
        a = pop(x); b = pop(y);
        if(a != b) return 0;
    }
    return 1;
}

int palindrome(char *c){
    Stack* a = create(strlen(c)); // stack inicial
    Stack* b = create(strlen(c)); // stack temp p
    Stack* aux = create(strlen(c)); // copia da inicial
    init(a, c); copy(a, aux, c);
    while(!(vazia(a))){
        push(b, pop(a)); // ok!
    }
    print(b); print(aux);
    if(compara(aux, b)) return 1; 
    else return 0;
    destroy(a); destroy(b); destroy(aux);
}

int main(){
    //char* c = "renner";
    //char* c = "gabriel";
    //char* c = "o"; 
    char* c = "ana";
    if(palindrome(c)) printf("True\n");
    else printf("False\n"); 
    return 0;
}
