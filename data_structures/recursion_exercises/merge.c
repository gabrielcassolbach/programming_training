#include "list.c"

// Copiar o código do professor e analisar ele.
List* merge(List* A, List* B){
  if(A == NULL) {return B;}
  if(B == NULL) {return A;}
  if((A -> data) < (B -> data)){
      A -> next = merge(A -> next, B);
      return A;
  }else{
      B -> next = merge(A, B -> next);
      return B;
  }
}

List* fill(List* X, int i, int f, int n){
  for(int k = i; k <= f; k += n) 
    X = insert_back(X, k);
  return X;
}

int main () {
  List *A = NULL; List* B = NULL; List* C = NULL;
  A = fill(A, 0, 20, 2); print(A); printf("\n");
  B = fill(B, 1, 9, 2);  print(B); printf("\n");
  C = merge (A, B);      print(C); printf("\n");
  destroy (C);
  return 0;
}



