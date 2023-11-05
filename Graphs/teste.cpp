#include <iostream>
#include "adjacency_matrix.hpp"
using namespace std;

void DFS(GrafoM* G, int* v, int p){     
    printf("vertex: %d\n", p);
    v[p] = 1;
    for(int i = 0; i < G->V; i++)
        if(G->Mat[i][0] && !v[i])
            DFS(G, v, i);
}

int main(){ 
    GrafoM* G = create_graph (4);
    int visited[G->V]; 
    
    for(int i = 0; i < G->V; i++) 
        {visited[i] = 0;} 

    init_graph(G);

    add_conection(G, 0, 1); add_conection(G, 0, 2);
    add_conection(G, 1, 2); add_conection(G, 2, 3);

    DFS(G, visited, 0);

    print_graph(G);

    free_graph (G);
    return 0;
}
