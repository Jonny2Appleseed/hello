/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-11-21
 *
 * This file holds the prototypes and the definitions of functions
 */

long choose(int n, int k) {
    if(k == 0 || k == n) {
        return 1;
    }
    return choose(n - 1, k) + choose(n - 1, k - 1);
}
