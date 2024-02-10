#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

/*
  Entrada
    errorCode <- Código da restrição violada;
*/
void parameterInputErrorMessage(int errorCode);

/*
  Entrada
    n <- Quantidade de planetas;
    subdistance <- Subdistâncias entre os planetas;
*/
void subdistancesInput(int n, int *subdistance);

/*
  Entrada
    planet1 <- Planeta do qual o cálculo de custo vai se iniciar;
    planet2 <- Planeta do qual o cálculo de custos vai terminar;
    subdistance <- Subdistâncias entre os planetas;
  Saída
    cost <- Custo da distância percorrida do planet1 ao planet2;
*/
int calculatesTheCostOfTheSubdistance(
  int planet1, int planet2, int *subdistance
);

/*
  Entrada
    x <- Número qualquer;
    y <- Número qualquer;
  Saída
    (x < y) ? x : y <- Menor número entre as opções
*/
int smallerThan(int x, int y);

/*
  Entrada
    x <- Número qualquer;
    y <- Número qualquer;
  Saída
    (x < y) ? x : y <- Maior número entre as opções
*/
int biggerThan(int x, int y);

#endif