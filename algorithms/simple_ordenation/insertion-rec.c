#include "utils.h"

/*
Não é necessário eliminar todos os iteradores, basta escolher um loop para transformar em 
recursão - para isso, observe qual deles é menos acoplado ao código
*/

// Não altere o protótipo dessa função.
void insertion_sort_recursive (int *A, int n) {
  
  // 4, 10, 8, 3.
  if (A[n] < A[n-1]){
    swap(A, n, n-1);
    

  }else{


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
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  start = clock();
  print (A, n, "Input");
  insertion_sort_recursive (A, n);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

