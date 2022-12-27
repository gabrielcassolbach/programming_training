#include "list.h"

int is_circular (List *l) {
  List* t = l;
  while(t -> next != NULL){
    if(t -> next == l) return 1;
    t = t -> next;
  }
  return 0;
}

List* create_circular (List *head) {
  if(head == NULL) return head;
  List* t = head; 
  while(t -> next != NULL) {t = t -> next;}
  t -> next = head; head -> prev = t;
  return head; 
}

int main () {
  int i; int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) 
    l = insert_front (l, i);
  print (l);
  printf("Is circular: %d\n", is_circular(l));
  l = create_circular(l); 
  printf("Is circular: %d\n", is_circular(l));
  return 0;
} 
