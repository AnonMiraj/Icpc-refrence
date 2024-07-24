int NMAX = 1e6;
vector<int> spf(MAXN + 1, 1);

void sieve() {
  spf[0] = 0;
  for (int i = 2; i <= NMAX; i++) {
    if (spf[i] == 1) {
      for (int j = i; j <= NMAX; j += i) {
        if (spf[j] == 1)
          spf[j] = i;
      }
    }
  }
}

void getFactorization(int x, map<int, int> &primes) {
  while (x != 1) {
    primes[spf[x]]++;
    x = x / spf[x];
  }
}
