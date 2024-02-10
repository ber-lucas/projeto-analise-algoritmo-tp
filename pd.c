#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.h"
#include "pd.h"

/*
  Algoritmo de Programação Dinâmica
    Neste algoritmo utilizamos a heurística utilizada no Algoritmo Guloso para
    selecionar os k-1 planetas restantes, e então a matriz que armazena estes
    resultados é utilizada para calcular a solução ótima para este problema.
*/
int pd(int dist[], int n, int k) {
  
  int memo[n + 1][k + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
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

  /* Calcula a solução ótima */
  for (int j = 1; j <= k; j++) {
    for (int i = j; i <= n; i++) {
      if (j == 1) {
        memo[i][j] = calculatesTheCostOfTheSubdistance(first, i, dist);
      } else {
        memo[i][j] = INT_MAX;
        for (int x = j - 2; x < i; x++) {
          int cost = calculatesTheCostOfTheSubdistance(x, i, dist);
          memo[i][j] = smallerThan(memo[i][j], biggerThan(memo[x][j - 1], cost));
        }
      }
    }
  }

  free(travDistance);

  return memo[n][k];
}