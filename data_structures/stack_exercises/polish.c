#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int operation(char c){
    if(c == '*' || c == '+' || c == '-' || c == '/') return 1;
    else return 0;
}

int number(char c){
    if((c >= '0') && (c <= '9')) return 1;
    else return 0;
}

void reversed_polish_notation (char *c) {
  Stack *p = create(strlen(c));
  Stack *np = create(strlen(c));
  Stack *o = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    if(c[i] == '(')
        push(p, c[i]);
    else if(number(c[i]))
        push(np, c[i]);
    else if(operation(c[i]))
        push(o, c[i]);
    else if(c[i] == ')'){
        pop(p);
        push(np, get_peek(o));
        pop(o);
    }
    i++;
  }
  print2 (np);
  printf("\n");
  destroy(np); destroy(p); destroy(o);
}

int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  reversed_polish_notation (c);
  return 0;
}
