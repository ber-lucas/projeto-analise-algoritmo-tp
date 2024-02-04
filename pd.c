#include <stdio.h>
#include <stdlib.h>

int calculatesTheCostOfTheSubdistance(
  int planet1, int planet2, int subdistance[]
);

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
