#ifndef AG_H_INCLUDED
#define AG_H_INCLUDED

/*
  Entrada
    subdistance <- Subdistâncias entre os planetas;
    n <- Quantidade de planetas;
    k <- Quantidade de planetas a serem reconquistados;
  Saída
    max_subdistance <- Subdistância de maior custo;
*/
int ag(int dist[], int n, int k);

#endif