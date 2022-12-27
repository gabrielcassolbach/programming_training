#include "list.h"

List* replicate (List *l, int k) {
  /*Terminar!*/	
}

int main () {
  int i;	
  int k = 3;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 1; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = replicate (l, k);
  print (l);
  destroy (l);
  return 0;
} 
