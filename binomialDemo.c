/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-11-21
 *
 * This file runs all the functions that are computed in binomial.c.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binomial.h"


int main(int argc, char **argv){

if (argc != 3) {
    exit(1);
  }
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

long ways = choose(n, k);

printf("The amount of ways for choosing %d items out of %d items: %ld ways", k, n, ways);



}
