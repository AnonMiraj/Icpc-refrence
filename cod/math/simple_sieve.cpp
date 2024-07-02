const int NMAX = 1000000;
bitset<NMAX / 2> bits;

void precalcseive() {
  bits.set();
  for (int i = 3; i / 2 < bits.size(); i = 2 * bits._Find_next(i / 2) + 1) {
    for (auto j = (int64_t)i * i / 2; j < bits.size(); j += i)
      bits[j] = 0;
  }
}

//count all the divisors of a number
int divCount(int n) {
  int total = 1;
  int count = 0;
  int p = 2;
  if (n % p == 0) {
    while (n % p == 0) {
      n = n / p;
      count++;
    }
    total = total * (count + 1);
  }
  for (p = 3; p <= n; p += 2) {
    if (bits[p / 2]) {
      count = 0;
      if (n % p == 0) {
        while (n % p == 0) {
          n = n / p;
          count++;
        }
        total = total * (count + 1);
      }
    }
  }
  return total;
}
