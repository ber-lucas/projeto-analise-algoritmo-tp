#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"
#include "fb.h"
#include "ag.h"
#include "pd.h"

/*
  Restrições
    argc, argc === 2   (1)
    t,    0 < t <= 100 (2)
    n,    0 < n <= 500 (3)
    k,    0 < k <= 250 (4)

  Observações
    (1) A variável 'argc' armazena o número de valores que foram passados para
    o array '*argv[]' acrescentado da chamada de execução, ou seja, além do
    parâmetro passado (tipo do algoritmo), na posição argv[1] terá a chamada de
    execução de algoritmo. Isso explica o por quê da restrição igual a 2 e não 
    a 1.
*/

int main(int argc, char *argv[]) {
  int t, n, k;
  int *subdistance;

  clock_t start, end;

  if(argc != 2) {
    parameterInputErrorMessage(1);
    return 0;
  }

  // Entrada da quantidade de instâncias do problema a serem simuladas
  scanf("%d", &t);

  if(t < 0 || t > 100) {
    parameterInputErrorMessage(2);
    return 0;
  }

  for(int i = 0; i < t; i++) {
    // Entrada da quantidade de planetas consecutivos de uma rota
    scanf("%d", &n);
    // n = 35;

    if(n < 0 || n > 500) {
      parameterInputErrorMessage(3);
      return 0;
    }

    // Entrada da quantidade de planetas a serem reconquistados
    scanf("%d", &k);
    // k = 10;

    if(k < 0 || k > 250) {
      parameterInputErrorMessage(4);
      return 0;
    }

    // start = clock();
    subdistance = (int *)malloc((n + 1) * sizeof(int));
    subdistancesInput(n, subdistance);

    /*
      Menu de Escolhas
        FB <- Força Bruta
        AG <- Algoritmo Guloso
        PD <- Programação Dinâmica
    */
    if(!(strcmp(argv[1], "FB"))) {
      printf("%d\n", fb(subdistance, n, k));
    }
    
    else if(!(strcmp(argv[1], "AG"))) {
      printf("%d\n", ag(subdistance, n, k));
    }

    else if(!(strcmp(argv[1], "PD"))) {
      printf("%d\n", pd(subdistance, n, k));
    }

    else {
      printf("\nErro: escolha de algoritmo inválida!");
      return 0;
    }

    free(subdistance);
  }

  // end = clock();
  // printf("Tempo de execução: %f", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}