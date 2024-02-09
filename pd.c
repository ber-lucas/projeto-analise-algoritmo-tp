#include <stdio.h>
#include <stdlib.h>

int calculatesTheCostOfTheSubdistance(
  int planet1, int planet2, int subdistance[]
);

int smallerThan(int x, int y);

int biggerThan(int x, int y);

/*
  Algoritmo de Programação Dinâmica
    Neste algoritmo utilizamos a heurística utilizada no Algoritmo Guloso para
    selecionar os k-1 planetas restantes, e então a matriz que armazena estes
    resultados é utilizada para calcular a solução ótima para este problema.
*/
int pd(int dist[], int n, int k) {

  int memo[n + 1][k + 1];
  for (int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      memo[i][j] = -1;
    }
  }

  memo[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    memo[i][0] = calculatesTheCostOfTheSubdistance(0, i, dist);
  }

  /* Calcula os k-1 planetas restantes usando a escolha gulosa como heurística */
  int *travDistance = (int *) calloc(n, sizeof(int));
  int last = n - 1;
  int first = 0;
  for (int i = 1; i < k; i++) {
    int best = -1;

    /* Escolhe o planeta mais distante do último planeta escolhido. */
    for (int j = 0; j < n; j++) {
      if (!travDistance[j] &&
        (best == -1 || dist[j] - dist[last] > dist[best] - dist[last]))
        best = j;
    }

    travDistance[best] = 1;
    last = best;

    /* Atualiza o valor de first quando o first planeta é escolhido */
    if (i == 1) {
      first = best;
    }
  }

  return 0;
}

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
