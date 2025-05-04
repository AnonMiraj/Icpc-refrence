/**
 * Author: Simon Lindholm
 * Date: 2016-07-24
 * License: CC0
 * Source: Russian page
 * Description: Pre-computation of modular inverses. Assumes LIM $\le$ mod and that mod is a prime.
 * Status: Works
 */
#pragma once

// const int mod = 1000000007, LIM = 200000; ///include-line
int* inv = new int[LIM] - 1; inv[1] = 1;
rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
