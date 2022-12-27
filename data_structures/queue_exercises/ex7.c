#include <stdio.h>
#include "queue.c"
#define TAM 5

Queue* inversor(Queue* q, Queue* aux, Queue* r, int spot){
    int cont = 0;
    while(!(vazia(q))){
        cont++;
        if(cont == spot) enqueue(r, dequeue(q));
        else enqueue(aux, dequeue(q));
    }
    while(!(vazia(aux))){
        enqueue(q, dequeue(aux));
    }
    return r;
}


Queue* reverse(Queue* q){
    Queue* r = create(TAM); Queue* aux = create(TAM); 
    int n = TAM - 1; int spot = n;
    while(n--){
        r = inversor(q, aux, r, spot);
        spot--;
    }
    return r;
}

void init(Queue* q){
    for(int i = 1; i <= 4; i++)
        enqueue(q, i);
}

int main(){
    Queue* q = create(TAM); init(q); 
    Queue* r = reverse(q);
    print(r);
    return 0;
}
