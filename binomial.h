/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-11-21
 *
 * This file holds the prototypes and the definitions of functions in
 * biniomial.c.
 */

/**
 * This function uses recursion using integers n and k to compute pascal's rule
 */
long choose(int n, int k);


/**
 * This function uses memoization to compute pascal's rule
 */

long chooseMemoization(int n, int k, long arr);
