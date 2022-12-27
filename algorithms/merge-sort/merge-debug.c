#include "utils.h"

/*Função intercala*/
void merge (int A[], int l, int m, int r, int O[], int rlevel) {
  int i = l; int j = m + 1; int k = l;
  while((i <= m) && (j <= r)){
    if(A[i] <= A[j])
      O[k++] = A[i++];
    else 
      O[k++] = A[j++];
  }
  while(i <= m) {O[k++] = A[i++];}
  while(j <= r) {O[k++] = A[j++];}
  for(int n = l; n <= r; n++) {A[n] = O[n];} 
  partition_print(A, l, r, rlevel - 1);
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int rlevel) {
  if(l < r){
    int m = ((l+r)/2);
    for(int i = 0; i < rlevel; i++)
      printf("  ");
    printf("Merge-Sort (%d %d %d)\n", l, m, r);    
    merge_sort(A, l, m, O, rlevel+1);
    merge_sort(A, m + 1, r, O, rlevel+1);
    merge(A, l, m, r, O, rlevel);
  }	
}

int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

