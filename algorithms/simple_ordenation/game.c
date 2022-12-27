#include "utils.h"

/* */
char game (int *A, int n) {
  int i, j;
  char player = 'A';
  int moves = 0;
  /*Terminar*/
  printf("# of rounds: %d\n", moves);
  return (player == 'A' ? 'B' : 'A');
}

/* */
int main () {

  int i;
  int n = 6;
  //int A[] = {1,5,3,4,2};
  //int A[] = {5,1,3,4,2};
  //int A[] = {1,2,3,4,5};
  //int A[] = {5,4,3,2,1};
  //int A[] = {3,5,2,1,4,6};
  int A[] = {6,5,4,3,2,1};
  print (A, n, "Input");
  printf("Vencedor: %c\n", game (A, n));
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

