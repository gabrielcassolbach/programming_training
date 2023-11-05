#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct grafoM {
   int E; 
   int V; 
   int **Mat; 
} GrafoM;

GrafoM* create_graph (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;

}

void free_graph (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) 
        {free(G->Mat[v]);}
   }
   free(G->Mat);
   free(G);
}
   
void init_graph(GrafoM *G){
    for(int i = 0; i < G->V; i++)
        for(int j = 0; j < G->V; j++)
            G->Mat[i][j] = 0;
}

void add_conection(GrafoM *G, int first_point, int second_point){    
    if(first_point > (G->V - 1) || second_point > (G->V - 1))  
        {printf("invalid points\n"); return;}
    
    G->Mat[first_point][second_point] = 1;
    ++(G->E);
}

void print_graph(GrafoM *G){
    for(int i = 0; i < G->V; i++){
        printf("\n");
        for(int j = 0; j < G->V; j++){
            printf(" %d", G->Mat[i][j]);
        }
    }
    printf("\n");
}