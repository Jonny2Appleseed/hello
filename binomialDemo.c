/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-11-21
 *
 * This file runs all the functions that are computed in binomial.c.
 */

#include <stdlib.h>
#include <stdio.h>

#include "binomial.h"


int main(int argc, char **argv){

  if(argc != 3) {
      exit(1);
    }
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  // NOTE: Old code, didn't know if it should be deleted or comented out to show our work.
  // long ways = choose(n, k);

  // printf("The amount of ways for choosing %d items out of %d items: %ld ways\n", k, n, ways);

  long **table = (long **) malloc(sizeof(long*) * (n + 1));
  for(int i = 0; i <= n; i++) {
    table[i] = (long *) malloc(sizeof(long) * (k + 1));
  }
  int j = 0;
  for(int i = 0; i <= n; i++) {
    for(j = 0; j <= k; j++) {
      table[i][j] = -1;
    }
  }

<<<<<<< HEAD


return 0;
=======
  long ways = chooseMemoization(n, k, table);

  printf("The amount of ways for choosing %d items out of %d items: %ld ways\n", k, n, ways);

  return 0;
>>>>>>> 724ef80133fedfbd28f076b05e3f75a968967fb0
}
