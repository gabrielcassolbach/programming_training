#include "utils.h"

int partition(int A[], int left, int right)
{
  int p = A[right];
  int i = left - 1;
  for (int j = left; j < right; j++)
  {
    if (A[j] <= p)
    {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i + 1, right);
  return (i + 1);
}

int quick_find(int *A, int left, int right, int k)
{
  //   pensar sobre esquerda <= direita ao invés de esquerda < direita.
  /*
    5 1 3 4 2
    1 2 5 4 3
    1 2 3 5 4
    1 2 3 4 5
  */

  if (left <= right) 
  {
    int p = partition(A, left, right);
    if (k == p)
      return A[p];
    if (k < p)
      quick_find(A, left, p - 1, k);
    else
      quick_find(A, p + 1, right, k);
  }
}

int main()
{
  int n = 8;
  int k = 7;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};

  /*Sorted A = {1,  2,  3,  7,  9, 10, 17, 21}*/
  /*   index = [0] [1] [2] [3] [4] [5] [6] [7]*/

  print(A, n, "Input");
  printf("the element in position %d is: %d\n", k, quick_find(A, 0, n - 1, k));
  return 0;
}
