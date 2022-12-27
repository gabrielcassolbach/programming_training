#include "list.c"

List* insert_sort (List* l, int k){
    if (l == NULL) {
        List* node = (List*) malloc (sizeof(List));
        node -> data = k;  
        node -> next = NULL;
        return node;
    }
    if(k < (l -> data)){
        List* node = (List*) malloc (sizeof(List));
        node -> data = k;  
        node -> next = l;
        return node;
    }else{
        l -> next = insert_sort(l -> next, k);        
        return l;
    }
}

int main(){
    List* l = create();
    l = insert_sort(l, 9); 
    l = insert_sort(l, 0); 
    l = insert_sort(l, 4);
    l = insert_sort(l, 2); 
    l = insert_sort(l, 7);
    print(l);
    return 0;
}