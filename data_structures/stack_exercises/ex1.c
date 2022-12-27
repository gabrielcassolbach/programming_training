#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack* a = create(6);
    int j, v[6], aux;

    for(int i = 0; i < 6;  i++)
        push(a, rand() % 10);

    print(a);

    j = 0;
    while(!vazia(a)){
        aux = pop(a);
        if(aux % 2 != 0){
            v[j] = aux;
            j++;
        }
    }

    Stack* b = create(j);
    for(int i = (j-1); i >=0; i--)
        push(b, v[i]);

    print(b);
    destroy(b); destroy(a);
    return 0;
}
