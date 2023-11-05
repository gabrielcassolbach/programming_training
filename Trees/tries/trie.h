
#ifndef _trie_h_
#define _trie_h_

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define size 26

typedef struct trie {
   char data; 
   int end;
   int nchild;
   struct trie *keys[size];
} Trie;

Trie *create_node (char data);

void free_node (Trie *node);

Trie *insert (Trie *root, char *word);

void search (Trie *root, char *word);

int search_auxiliary (Trie *root, char *word);

void print (Trie *root, int level);

void delete (Trie *root, char *word);


#endif

