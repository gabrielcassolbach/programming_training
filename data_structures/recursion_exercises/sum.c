#include <stdio.h>
#include "list.c"

/*Use recursão para retornar a soma de uma lista.*/
int sum (List *l) {
  if(l != NULL) return (l -> data + sum (l -> next));
  return 0;
}

int main () {
  List *l = NULL;  
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
