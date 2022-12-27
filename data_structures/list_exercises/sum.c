#include "list.c"
#include <stdio.h>

int sum (List *l) {
  List* t = l; int sum = 0;
  while(t != NULL){
    sum += t->data;
    t = t->next;
  }
  return sum;
}

int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = Insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = Insert (l, k);
  print (l);
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
