#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

int calculatesTheCostOfTheSubdistance(
  int planet1, int planet2, int subdistance[]
) {
  int cost = 0;

  for(int i = planet1; i < planet2; i++) {
    cost += subdistance[i];
  }

  return cost;
}

