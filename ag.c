#include <stdio.h>
#include <stdlib.h>
#include "ag.h"

/*
  Algoritmo Guloso
    A ideia deste algoritmo é escolher um planeta inicial que maximize a 
    distância para o próximo planeta escolhido, e em seguida escolher o planeta 
    que maximize a distância para o último planeta escolhido. Desta forma, para
    cada elemento da sequência, escolher o próximo elemento que maximize a soma 
    entre o elemento atual e o próximo elemento.
*/
int ag(int dist[], int n, int k) {
    int max_subdistance = 0, current_subdistance = 0, first = 0, last = n - 1;
    
    int *trav_distance;
    trav_distance = (int *) malloc(n * sizeof(int));

    /* Seleciona o planeta mais distante do último planeta como o primeiro. */
    int i = 0;
    while (i < n) {
        if (dist[i] > dist[first]) {
            first = i;
        }
        i++;
    }

    trav_distance[first] = 1;

    /* Escolha gulosa: escolhe os k-1 planetas restantes. */
    for (int i = 1; i < k; i++) {
        int best = -1;

        /* Escolhe o planeta mais distante do último planeta escolhido. */
        for (int j = 0; j < n; j++) {
            if (!trav_distance[j] &&
                (best == -1 || dist[j] - dist[last] > dist[best] - dist[last]))
                best = j;
        }

        trav_distance[best] = 1;
        last = best;
    }

    /* Calcula a maior subdistância da solução encontrada. */
    for (int i = 0; i < n; i++) {
        if (trav_distance[i]) {
            current_subdistance += dist[i];

            if (current_subdistance > max_subdistance) {
                max_subdistance = current_subdistance;
            }

            current_subdistance = 0;
        } else {
            current_subdistance += dist[i];
        }
    }

    free(trav_distance);
    return max_subdistance;
}
