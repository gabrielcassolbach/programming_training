#include "list.c"

/*Essa função verifica se k está na lista.*/
int in (List *l, int k) {
  List* t = l;
  while(t != NULL){
    if(t->data == k) return 1;
    else (t = t->next);
  }
  return 0;
}

int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = Insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = Insert (l, k);
  print (l);
  printf("Pertence %d? %d\n", 9, in(l, 9));
  printf("Pertence %d? %d\n", -1, in(l, -1));
  destroy (l);
  return 0;
}
