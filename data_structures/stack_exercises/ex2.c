#include <stdio.h>
#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    if((c[i] == '(') || (c[i] == '['))
        push(s, c[i]);
    else if((c[i] == ']') && (get_peek(s) == '['))
        pop(s);
    else if((c[i] == ')') && (get_peek(s) == '('))
        pop(s);
    i++;
  }
  if(vazia(s)) return 1;
  else return 0;
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c))
    printf("true  (bem formada)\n");
  else
    printf("false (mal formada)\n");
  return 0;
}


