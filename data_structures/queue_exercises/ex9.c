#include <stdio.h>
#include <time.h>
#include "queue.c"
#define TAM 10 // 1 posição é sacrificada.

// Máquina de caça-níqueis -> exercício 9.

int verify_end(Queue* a, Queue* b, Queue* c){
    if((frente(a)) != (frente(b))) return 0;
    if((frente(a)) != (frente(c))) return 0;
    if((frente(b)) != (frente(c))) return 0;
    return 1;
}

void spin_slots(Queue* x){
    Queue* aux = create(TAM);
    srand(time(NULL));
    int n  = rand() % TAM;
    for(int i = 0; i < n; i++)
        enqueue(aux, dequeue(x));
    for(int i = 0; i < n; i++)
        enqueue(x, dequeue(aux));
    destroy(aux);
}

void initqueues(Queue* a, Queue* b, Queue* c){
    srand(time(NULL));
    while(!full(a)){
        enqueue(a, rand() % 10);
        enqueue(b, rand() % 10);
        enqueue(c, rand() % 10);
    }
    printf("\n");
}

int jackpot (Queue* a, Queue* b, Queue* c){
    initqueues(a, b, c);
    spin_slots(a); spin_slots(b); spin_slots(c);
    print(a); print(b); print(c);
    return verify_end(a, b, c);
}

int main(){
    Queue* a = create(TAM);
    Queue* b = create(TAM);
    Queue* c = create(TAM);
    if(jackpot(a, b, c)) printf("Ganhou!\n");
    else printf("Perdeu!\n");
    destroy(a); destroy(b); destroy(c);
    return 0;
}