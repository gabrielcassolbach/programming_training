#include "pqueue.h"

/*Função que verifica se o elemento a ser analisado está dentro da matriz ou não.*/
int inside (int i, int j, int n) {
  if ((i < 0) || (j < 0) || (i >= n) || (j >= n))
    return 0;
  return 1;
}

/*Função que imprime uma matriz.*/
void print_matrix (char M[][10], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c ", M[i][j]);
    }
    printf("\n");
  }
}

/*Função auxiliar para a contagem de ilhas. */
void conquer (char M[][10], int i, int j, int n, int nlabel) {
  Queue *q = create((n*n)+1);
  enqueue (q, (point){i,j});
  M[i][j] = (char) nlabel+'0';
  while (!vazia(q)) {
    point p = dequeue (q); // retiro da fila.
    if((M[p.x+1][p.y] == '*') && (inside(p.x+1, p.y, n))){
        enqueue (q, (point){p.x+1,p.y});
        M[p.x+1][p.y] = (char) nlabel+'0';
    }
    if((M[p.x+1][p.y+1] == '*') && (inside(p.x+1, p.y+1, n))){
        enqueue (q, (point){p.x+1,p.y+1});
        M[p.x+1][p.y+1] = (char) nlabel+'0';
    }
    if((M[p.x+1][p.y-1] == '*') && (inside(p.x+1, p.y-1, n))){

        enqueue (q, (point){p.x+1,p.y-1});
        M[p.x+1][p.y-1] = (char) nlabel+'0';
    }
    if((M[p.x-1][p.y] == '*') && (inside(p.x-1, p.y, n))){
        enqueue (q, (point){p.x-1,p.y});
        M[p.x-1][p.y] = (char) nlabel+'0';
    }
    if((M[p.x-1][p.y+1] == '*') && (inside(p.x-1, p.y+1, n))){
        enqueue (q, (point){p.x-1,p.y+1});
        M[p.x-1][p.y+1] = (char) nlabel+'0';
    }
    if((M[p.x-1][p.y-1] == '*') && (inside(p.x-1, p.y-1, n))){
        enqueue (q, (point){p.x-1,p.y-1});
        M[p.x-1][p.y-1] = (char) nlabel+'0';
    }
    if((M[p.x][p.y+1] == '*') && (inside(p.x, p.y+1, n))){
        enqueue (q, (point){p.x,p.y+1});
        M[p.x][p.y+1] = (char) nlabel+'0';
    }
    if((M[p.x][p.y-1] == '*') && (inside(p.x, p.y-1, n))){
        enqueue (q, (point){p.x,p.y-1});
        M[p.x][p.y-1] = (char) nlabel+'0';
    }
  }
  destroy (q);
}

/*Função "main" para a contagem de ilhas.*/
int count_islands (char M[][10], int n) {
  int i, j, sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (M[i][j] == '*') {
        sum++; // há pelo menos uma ilha.
        conquer (M, i, j, n, sum); // continue analisando.
      }
    }
  }
  return sum;
}

int main () {

  int n = 10;
  char M[][10] =
    { {'*',' ','*',' ',' ',' ','*','*','*','*'},
      {' ',' ','*',' ','*',' ','*',' ',' ',' '},
      {'*','*','*','*',' ',' ','*',' ',' ',' '},
      {'*',' ',' ','*',' ',' ',' ',' ',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'},
      {' ','*',' ','*',' ',' ','*','*','*','*'},
      {' ',' ',' ',' ',' ','*','*','*',' ',' '},
      {' ',' ',' ','*',' ',' ','*','*','*',' '},
      {'*',' ','*',' ','*',' ',' ','*',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'}
    } ;

  print_matrix (M, n); // imprime a matriz.
  printf("there are %d islands \n", count_islands (M, n));
  print_matrix (M, n);
  return 0;
}
