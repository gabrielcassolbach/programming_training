#include <stdio.h>
#include "list.c"
 
List* merge(List* A, List* B){
  List* H = NULL; /*Head*/  List* C = NULL; /*Temporary*/ int cont = 0;
  while((A != NULL) && (B != NULL)){
    if((A -> data) < (B -> data)){
      if(H == NULL) {H = A; C = A;}
      else {C->next = A; C = C -> next;}
      A = A -> next;
    }else{
      if(H == NULL) {H = A; C = A;}
      else {C->next = B; C = C -> next;}
      B = B -> next;
    }
  }
  if(A == NULL) {C -> next = B;}
  if(B == NULL) {C -> next = A;}
  return H; 
}

List* fill(List* X, int a, int c){
  for(int k=a; k>=0; k-=c)
    X = Insert(X, k); 
  return X;
}

int main() {
  List* A = NULL; List* B = NULL; List* C = NULL;
  A = fill(A, 10, 2); B = fill(B, 19, 2); 
  print(A); print(B);
  C = merge (A, B);
  print (C); destroy (C);
  return 0;
}