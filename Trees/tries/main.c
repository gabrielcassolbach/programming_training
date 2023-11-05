#include "trie.h"

int main () {

  Trie *root = create_node ('\0');

  root = insert (root, "maria");
  
  printf("\n\n\n\n\n");
  //print (root, 0);

  search (root, "maria");

  delete (root, "mar");
  //print (root, 0);

  return 0;
}
