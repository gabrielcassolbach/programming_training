#include "utils.h"
 
void insertion_sort (int *A, int n) {
  if(n <= 1) return;

  int key; int j;
  
  for(int i = 1; i < n; i++){

    if(A[i] < A[i-1]) {key = A[i]; j = i;} 
    else {j = 0;}

    while(j){
      if(key < A[j-1]) {
        A[j] = A[j-1]; 
        j--;
        if(!j) 
          A[j] = key;
      }
      else {A[j] = key; j = 0;}
    }
  }
}

int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
   
  int i;
  int n = atoi(argv[1]);
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); 
  }


  start = clock();
  //print (A, n, "Input");
  insertion_sort (A, n);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

