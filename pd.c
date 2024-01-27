#include <stdio.h>
#include <stdlib.h>

#define TEST_SIZE_I
#define TEST_SIZE_J

int pd() {

  int memo[TEST_SIZE_I][TEST_SIZE_J];
  for (int i = 0; i <= TEST_SIZE_I; i++) {
    for(int j = 0; j <= TEST_SIZE_J; j++) {
      memo[i][j] = 0;
    }
  }
}
