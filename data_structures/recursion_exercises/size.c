#include "list.c"

int tam = 0;

int size (List* l){
    if(l ==  NULL) return tam; 
    else {tam++; return size(l->next);}
}

List* fill(List* X, int i, int f, int c){
    for(int k = i; k <= f; k += c)
        X = insert_back(X, k);
    return X;
}

int main(){
    List* A = NULL;
    A = fill(A, 0, 19, 1); print (A);
    printf("\nsize of list is %d\n", size(A));
    destroy(A);
    return 0;
}