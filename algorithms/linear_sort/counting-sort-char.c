#include "utils.h"

int letra(int c) {return(c >= 'a' &&  c <= 'z');}

void counting_sort (FILE *f, int range) {
  int total = 0;
  int c;
  int *C = (int *)malloc((range) * sizeof(int)); /*contador*/
 
  for(int i = 0; i < range; i ++) {C[i] = 0;} // Primeiro passo.

  while((c = fgetc(f)) != EOF) // Segundo passo.
  {
    if(letra(c)) {c = c - 'a'; C[c] += 1; }
    total++;
  } 

  for(int i = 0; i < range; i ++) // Terceiro passo.
  {
    printf("Letra Contagem Frequência \n");
    printf(" %c      %d       %f      \n", (i + 'a'), C[i], (C[i] / (float)total));
  }

}

int main (int argc, char *argv[]) {

  if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");
  int range = 26; /*número de letras do alfabeto (a-z)*/
  counting_sort (f, range);
  fclose (f);
  return 0;
}

