#include "ruido.h"
#include "utils.h"
 
Image* create (int nrows, int ncols) {
  int i;
  Image *img = (Image *)malloc(sizeof(Image)); 
  img->nrows = nrows;
  img->ncols = ncols;
  img->m = (int **)malloc(ncols * sizeof(int *));
  for (i = 0; i < ncols; i++) {
    img->m[i] = (int *)malloc(nrows * sizeof(int)); 
  }
  return img;
}

void destroy (Image *img) {
  int i;
  for (i = 0; i < img->ncols; i++) {
    free(img->m[i]);
  }
  free(img->m);
  free(img);
}

Image* read_image (FILE *file_in, int *nrows, int *ncols) {
  int nlevels;
  char *type = (char *)malloc(sizeof(char));
  fscanf(file_in, "%s", type);   
  fscanf(file_in, "%d %d %d", ncols, nrows, &nlevels);   
  Image *in = create (*nrows, *ncols);
  int i, j;
  for (j = 0; j < in->nrows; j++) {
    for (i = 0; i < in->ncols; i++) {
      fscanf(file_in, "%d", &(in->m[i][j]));
    }
  } 
  free(type);
  return in;
}

void write_image (FILE *file_out, Image *out, int nrows, int ncols) {
  int i, j;	
  fprintf(file_out, "P2\n%d %d\n255\n", out->ncols, out->nrows);
  for (j = 0; j < out->nrows; j++) {
    for (i = 0; i < out->ncols; i++) {
      fprintf(file_out, "%d ", out->m[i][j]);
      if ( (j != 0) && ((j % 12) == 0) ) {
        fprintf(file_out, "\n");
      }
    }
  }
}  

void bubble_sort (int *A, int n){
  for(int i = 0; i < (n-1); i++){ 
    for(int j = 0; j < (n-i-1); j++){ 
      if(A[j] > A[j+1]) {swap(A, j, (j+1));}
    }
  }
}

Image* process (Image *in, int wsize) {
  int i, j, k, l, p;
  Image *out = create (in->nrows, in->ncols);
  int *A = (int *) malloc((wsize * wsize) * sizeof(int));   
  for(i = (wsize - 2); i < (in -> ncols - (wsize - 2)); i++){
    for(j = (wsize - 2); j < (in -> nrows - (wsize - 2)); j++){
      p = 0;
      for(k = i - (wsize - 2); k <= i + (wsize - 2); k++){
        for(l = j - (wsize - 2); l <= j + (wsize - 2); l++){
          A[p] = in -> m[k][l]; p++;  
        }
      }
      bubble_sort (A, wsize*wsize);
      out -> m[i][j] = A[(wsize*wsize)/2];
    }
  }
  free(A); 
  return out;
}

int main ( ) {
  int nrows, ncols;
  FILE *file_in  = fopen("lena.pgm", "r");
  FILE *file_out = fopen("saida.pgm", "w");
  /*tamanho da janela de remoção de ruído: */
  int wsize = 3; /*teste com ímpares 5, 7, 9, ...*/
  Image *in = read_image (file_in, &nrows, &ncols);
  Image *out = process (in, wsize);
  write_image (file_out, out, nrows, ncols);
  destroy (in); 
  destroy (out);
  fclose(file_in);
  fclose(file_out);
  return 0;
}