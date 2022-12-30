#include <iostream>
using namespace std;

// Faça um programa que leia um vetor X[10].
/*Entrada: 10 valores inteiros (positivos ou negativos.)*/


// Substitua todos os valores nulos e negativos por 1.
// Mostre todas as posições do vetor conforme a formatação

int main(){
    int x[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &x[i]);
        if(x[i] <= 0) x[i] = 1;
    }
    for(int i = 0; i < 10; i++)
        printf("X[%d] = %d\n", i, x[i]);

    return 0;
}