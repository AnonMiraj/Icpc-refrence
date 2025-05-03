/**
 * Author: idk
 * Description: 
 */
#include "ModPow.h"
vector<int> fact = {1}, inv = {1};

void build_fact(int n = 1e6) {
  while (fact.size() <= n) {
    fact.push_back(fact.back() * fact.size() % MOD);
    inv.push_back(modpow(fact.back(), MOD - 2));
  }
}

int ncr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  build_fact(n);
  return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int npr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  build_fact(n);
  return fact[n] * inv[n - r] % MOD;
}

