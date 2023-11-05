#include "abbLista.h"
#include "time.h"

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
    if(a == NULL){
        a = (Arvore*) malloc (sizeof (Arvore));
        a -> info = v;
        a -> esq = NULL;
        a -> dir = NULL;
    }
    else if(v < a -> info)
        a -> esq = inserir(a -> esq, v);
    else
        a -> dir = inserir(a -> dir, v);
    return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
   if(a == NULL) return NULL;
   else{
        if(a -> info > v)
            a -> esq = remover(a -> esq, v);
        else if (a -> info < v)
            a -> dir = remover(a -> dir, v);
        else 
            if(a -> esq == NULL && a -> dir == NULL)
                {free(a); a = NULL;}
            else if (a -> dir == NULL)
                {Arvore *tmp = a; a = a -> dir; free(tmp);}
            else
                {
                    Arvore* tmp = a -> esq;
                    while(tmp -> dir != NULL)
                        tmp = tmp -> dir;
                    a -> info = tmp -> info;
                    tmp -> info= v;
                    a -> esq = remover(a -> esq, v);
                }
   }
   return a;
}

//========= Q1 - busca
int buscar (Arvore *a, int v) {
    if(a == NULL) return 0;
    if(v < a -> info) return buscar(a -> esq, v);
    if(v > a -> info) return buscar(a -> dir, v);
    return 1; 
}

//========= Q2 - min =====
int min(Arvore *a){
    if(a != NULL){  
        if(a -> esq == NULL) return a -> info;
        return min(a -> esq);
    } 
}

//========= Q2 - max =====
int max(Arvore *a){
    if(a != NULL){
        if(a -> dir == NULL) return a -> info;
        return max(a -> dir);
    } 
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore *a){
    if(a != NULL){
        imprime_decrescente(a -> dir);
        printf("%d\n", a -> info);
        imprime_decrescente(a -> esq);
    }   
}

//========= Q4 - maior ramo =====
int maior_ramo(Arvore *a){
    if(a != NULL){
        int dir = maior_ramo(a -> dir);
        int esq = maior_ramo(a -> esq);
        if(esq > dir) dir = esq;
        return ((a -> info) + dir);
    }else{
        return 0;
    }
}

void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {
    int i;
    Arvore *a = cria_arvore_vazia ();
    // ====== Q5 ====
    // ok!
    return 0;
}
