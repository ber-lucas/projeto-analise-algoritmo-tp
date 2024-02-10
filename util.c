#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

void parameterInputErrorMessage(int errorCode) {
  printf("\nViolação da restrição de número %d.", errorCode);
}

// Função para receber as subdistâncias e armazenar em um vetor dinâmico
void subdistancesInput(int n, int *subdistance) {
  // srand(time(NULL));

  for(int i = 0; i <= n; i++) {
    // subdistance[i] = rand() % 500 + 1;
    scanf("%d", &subdistance[i]);
  }
}

// Função para calcular o custo de ir de um planeta a outro
int calculatesTheCostOfTheSubdistance(
  int planet1, int planet2, int subdistance[]
) {
  int cost = 0;

  for(int i = planet1; i < planet2; i++) {
    cost += subdistance[i];
  }

  return cost;
}

// Função para comparar dois números e retornar o menor
int smallerThan(int x, int y) {
  return (x < y) ? x : y;
}

// Função para comparar dois números e retornar o maior
int biggerThan(int x, int y) {
  return (x > y) ? x : y;
}
