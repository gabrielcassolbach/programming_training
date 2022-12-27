#include <stdio.h>
#include "Queue.h" // ALGORITMO MERGE-SORT -> ALGORITMO DE ORDENAÇÃO.

void transfere (Queue* x, Queue* y){
    while(!(vazia(x))){
        enqueue(y, frente(x));
        dequeue(x);
    }
}

void criaseq(Queue* x, int e, int s){
    while(!(full(x))){
        enqueue(x, e);
        e+=s;
    }
}

int* vetordena(int tam){
    int* v = (int *) malloc (sizeof(int) * tam);
    for(int i = 0; i < tam; i++) v[i] = 0;
    return v;
}

Queue* merge (Queue* a, Queue* b) {
    int tam = getsize(a) + getsize(b) + 1; Queue* c = create(tam);
    transfere(a, c); transfere(b, c);
    int* v = vetordena(maior(c) + 1);
    while(!(vazia(c))){
        v[frente(c)] = 1;
        dequeue(c);
    }
    for(int i = 0; i < tam; i++){
        if(v[i]) enqueue(c, i);
    }
    free(v);
    return c;
}


int main(){
    Queue* a = create(3);
    Queue* b = create(5);
    criaseq(a, 1, 1);
    criaseq(b, 6, 1);
    print(a); print(b);
    Queue* c = merge(a, b);
    print(c);
    destroy(a); destroy(b); destroy(c);
    return 0;
}
