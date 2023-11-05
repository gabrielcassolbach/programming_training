#include "trie.h"
 
/*                  Questão 3
- Faça a implementação das chaves do exercício anterior. -ok.
- Insira as chaves do exercício anterior.
{Casa, Castor, Galho, Gorro, Mesa, Morro, Rato, Roupa}.
- Busque as chaves: mes, tatu, galhos e casa.
- Remova as chaves: mes, tatu, galhos e roupa
*/

Trie *create_node (char data) {
  Trie *node = (Trie *)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  //size is the alphabet size 
  for (i = 0; i < size; i++) {
    node->keys[i] = NULL;	   
  }
  return node;   
}


void free_node (Trie *node) {
  int i;
  for (i = 0; i < size; i++) {
    if (node->keys[i] != NULL) {
      free_node (node->keys[i]);	    
    }
  }	  
  free (node);
}


Trie *insert (Trie *root, char *word) {
  if(search_auxiliary(root, word)) 
    {printf("Error, already inserted"); return root;}
  Trie* t = root;
  for(int i = 0; word[i] != '\0'; i++){
    int index = word[i] - 'a';
    if(t -> keys[index] ==  NULL)
      t -> keys[index] = create_node(word[i]);
    t -> nchild += 1;
    t = t -> keys[index];
  }
  t -> end = TRUE;
  return root;  	
}


int search_auxiliary (Trie *root, char *word) {
  Trie* t = root;
  for(int i = 0; word[i] != '/0'; i++){
    int index =  word[i] - 'a';
    if(t -> keys[index] == NULL) return FALSE; // The word will not be found.
    else t = t -> keys[index]; // Go deeper in the tree. 
  }
  // This part of the code is necessary to verify the words that are "inside" others.
  if(t -> end) return TRUE;
  return FALSE; 
}

void search (Trie *root, char *word) {
  if (search_auxiliary (root, word))
    printf("Word %s found!\n", word);
  else  
    printf("Error: word %s not found!\n", word);
}


void print (Trie *root, int level) {
  if (root != NULL) {
    int i;
    if (root->data == '\0')
      printf ("(null)");	    
    for (i = 0; i < level; i++) {
      printf ("| ");
    }	    
    printf ("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for (i = 0; i < size; i++) {
      print (root->keys[i], level+1);      
    }
  }	  
}

void delete (Trie *root, char *word) {
  if(search_auxiliary(root, word)) 
    {printf("nothing to delete.."); return root;}
  
  Trie* t = root; // used as auxiliary pointer.
  int pos;

  for(int i = 0; word[i] != '\0'; i++)
    {t = t->keys[word[i] - 'a']; pos = i;}

  /*
  Devemos ir até a última posição da palavra.
   - Se existe mais uma palavra que depende da última letra de word, simplesmente precisamos
   retirar a marcação.
   - Senão, vamos remover a letra e voltar para o nível anterior, checando se essa letra possui algum 
  filho. 
    . Se isso for verdade, então iremos remover a letra e encerrar a função.
    . Caso contrário, iremos continuar subindo na árvore.
  */
  
}  
 
