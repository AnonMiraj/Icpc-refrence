/**
 * Author: ezz
 * Description: Precomputes factorials and inverse factorials modulo mod, call build\_fact once before using nCr.
 */

#include "ModPow.h"

vector<int> fact = {1}, inv = {1};

void build_fact(int n = 2e6) {

  fact.resize(n + 1);
  inv.resize(n + 1);

  rep(i, 1, n + 1) 
    fact.push_back(1LL * fact.back() * i % mod);

  inv[n] = modpow(fact[n], mod - 2);
  for (int i = n - 1; i >= 0; --i)
    inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
}
int ncr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  return fact[n] * inv[r] % mod * inv[n - r] % mod;
  // For npr: return fact[n] * inv[n - r] % mod;
}
