#include <iostream>
#include <stack>
using namespace std;

typedef struct noA {
   int id;          
   struct noA *next; 
} NoA;

typedef struct grafoA {
   int E; 
   int V; 
   NoA **Adj; 
} GrafoA;

GrafoA* create_graph (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

void free_graph (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

NoA* new_node(int value, NoA* address){
   NoA* na = (NoA*) malloc (sizeof(NoA));
   na->id = value;
   na->next = address;
   return na;
}

int connect (GrafoA *G, int pa, int pb){
   for (NoA* n = G->Adj[pa]; n != NULL; n = n->next)
      {if(n->id == pb) return 0;}

   G->Adj[pa] = new_node(pb, G->Adj[pa]);
   return 1;
}

void add_conection(GrafoA *G, int pa, int pb){ 
   if(connect(G, pa, pb))    
      (G->E)++;
}

void print_graph(GrafoA* G){
   stack<int> p; 
   for(int i = 0; i < G->V; i++){
      printf("%d -> ", i);
      NoA* l = G->Adj[i];
      while(l != NULL)
         {p.push(l->id); l = l->next;}
      while(!p.empty())
         {printf("%d ", p.top()); p.pop();}
      printf("\n");
   }
}