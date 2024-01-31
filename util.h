#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED




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


#endif