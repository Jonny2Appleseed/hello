/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-11-21
 *
 * This file holds the prototypes and the definitions of functions
 */
#include <stdlib.h>
#include <stdio.h>

#include "binomial.h"

long choose(int n, int k) {
    if(k == 0 || k == n) {
        return 1;
    }
    return choose(n - 1, k) + choose(n - 1, k - 1);
}

long chooseMemoization(int n, int k, long **table) {
    if(table[n][k] != -1) {
        return table[n][k];
    }
    if(k == 0 || k == n) {
        table[n][k] = 1;
    } else {
        table[n][k] = chooseMemoization(n - 1, k, table) + chooseMemoization(n - 1, k - 1, table);
    }
    return table[n][k];
}
