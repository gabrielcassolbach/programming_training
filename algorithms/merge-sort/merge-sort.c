#include "utils.h"

/*
Exercício 7: modifique o algoritmo Merge-Sort para determinar o número de inversões em 
um array com tempo proporcional a 0(nlogn) no pior caso. 
*/

int inversions = 0;

void merge (int A[], int l, int m, int r, int O[])
{
  int i = l; int j = m + 1; int k = l;
  
  while((i <= m) && (j <= r))
  {
    if(A[i] <= A[j]) // Caso eu troque essa linha por: (A[i] < A[j]) o código funcionará do mesmo modo.
      {O[k++] = A[i++];}
    else 
      {O[k++] = A[j++]; inversions++;} // toda vez que entrou aqui ocorreu uma inversão.
  }
  
  while(i <= m) {O[k++] = A[i++];}
  while(j <= r) {O[k++] = A[j++];}
  for(int n = l; n <= r; n++) {A[n] = O[n];}  
}

void merge_sort (int A[], int l, int r, int O[]) 
{
  if(l < r){
    int m = ((l+r)/2);    
    merge_sort(A, l, m, O);
    merge_sort(A, m + 1, r, O);
    merge(A, l, m, r, O);
  }
}

int main (int argc, char *argv[]) 
{
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
  int i;
  int n = atoi(argv[1]);;
  int *A = (int *)malloc(n * sizeof(int));
  int *O = (int *)malloc(n * sizeof(int)); /*array auxiliar*/
  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i;   /*valores em ordem crescente*/
    //A[i] = n-i; /*valores em ordem descrescente*/
    //A[i] = 0;   /*valores iguais*/
  }
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O);
  print (A, n, "Sorted");
  printf("número de inversões %d\n", inversions);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  free (O);
  return 0;
}
