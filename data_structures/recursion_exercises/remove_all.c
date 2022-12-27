#include "list.c"

// Seja l = {1, 0, 1, 2, 1} e k == 1, teste o código abaixo.
List* remove_all(List* l, int k){
    if (l == NULL) {return l;}
    if (l -> data == k){
        List* tmp = l;
        l = l -> next;
        free(tmp); 
        l = remove_all(l, k);
    }else{
        l -> next = remove_all(l -> next, k);
        return l;
    }
}

List* init (List* l){
    // Insira os elementos necessários.
    return l;
}

int main(){
    List* l = create();
    l = init(l); 
    print(l);
    l = remove_all(l, 1);
    print(l);
    return 0;
}