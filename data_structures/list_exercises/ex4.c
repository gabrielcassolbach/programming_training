#include <stdio.h>
#include "list.c"


int size(List* l){
    List* t = l; int tam = 0;
    while(t != NULL){
        tam++;
        t = t->next;
    }
    return tam;
}

List* fill(List* X){
   X = Insert(X, 0); X = Insert(X, 1);
   X = Insert(X, 2); X = Insert(X, 3); 
   X = Insert(X, 4); X = Insert(X, 9); 
   X = Insert(X, 8); X = Insert(X, 7);
   X = Insert(X, 6); X = Insert(X, 5);  
   return X;
}

int main(){
    List* a = NULL;
    a = fill(a); 
    print(a);
    printf("O tamanho da lista é: %d\n", size(a));
    destroy(a);
    return 0;
}