#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.h"
#include "fb.h"

int fb(int *distance, int n, int k) {
  int greaterSubdistance = INT_MAX;
  int currentDistance = 0;

  int *subdistance;
  subdistance = (int*)malloc((n+1) * sizeof(int));
  subdistance[0] = 0;

  do {
    if(subdistance[currentDistance] < n) {
      subdistance[currentDistance + 1] = subdistance[currentDistance] + 1;
      currentDistance++;
    } else {
      subdistance[currentDistance - 1]++;
      currentDistance--;
    }

    if(currentDistance == k) {
      int *subdistanceTemp;
      subdistanceTemp = (int*)malloc((currentDistance+1) * sizeof(int));

      int intermediateSubdistancia = 0, iter = 0;

      while(iter < currentDistance + 1) {
        if(iter != currentDistance) {
          subdistanceTemp[iter] = calculatesTheCostOfTheSubdistance(
            subdistance[iter], subdistance[iter+1], distance
          );
        } else {
          subdistanceTemp[iter] = calculatesTheCostOfTheSubdistance(
            subdistance[iter], n+1, distance
          );
        }

        if(subdistanceTemp[iter] > intermediateSubdistancia) {
          intermediateSubdistancia = subdistanceTemp[iter];
        }

        iter++;
      }

      free(subdistanceTemp);
    }
  } while(currentDistance != 0);


  return greaterSubdistance;
}