#ifndef PD_H_INCLUDED
#define PD_H_INCLUDED

/*
  Entrada
    dist <- Subdistâncias entre os planetas;
    n <- Quantidade de planetas;
    k <- Quantidade de planetas a serem reconquistados;
  Saída
    memo[n][k] <- Subdistância de maior custo;
*/
int pd(int dist[], int n, int k);

#endif