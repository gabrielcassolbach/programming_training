#include <iostream>
#include "adjacency_list.hpp"
using namespace std;



int main () { 
   GrafoA* G = create_graph (4);

   add_conection(G, 0, 1); add_conection(G, 0, 2);
   add_conection(G, 1, 2); add_conection(G, 2, 3);
   
   print_graph(G);

   free_graph (G);
   return 0;
}