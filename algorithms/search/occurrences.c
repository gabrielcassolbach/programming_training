#include "utils.h"

/* */
int binary_search (int *A, int n, int key, int explore_left) {
  /*Terminar*/	
}

/* */
int find_occurrences (int *A, int n, int target) {
  /*Terminar*/	
}

/* */
int main () {
  int i, n = 10;
  int targets[] = {0,2,8,5,6,9};
  int A[] = {2,5,5,5,6,6,8,9,9,9};
  print (A, n, "Input");
  for (i = 0; i < 6; i++) {
    int oc = find_occurrences (A, n, targets[i]);
    if (oc != NOT_FOUND)
      printf("Target %d found %d times.\n", targets[i], oc);
    else
      printf("Target %d not found.\n", targets[i]);
  }  
  return 0;
}
