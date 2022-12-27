#include "list.c"
#include <limits.h>

// Verifica se o elemento está na lista.
int in (List *l, int k) {
  if(l == NULL) return 0;
  else if(l -> data == k) return 1;
  return in(l->next, k);
}

int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("In = %d\n", in(l,3));
  printf("In = %d\n", in(l,6));
  destroy (l);
  return 0;
}
