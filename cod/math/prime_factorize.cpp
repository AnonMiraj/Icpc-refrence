{
  map<int, int> primes;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      primes[i]++; // i is a prime
      n /= i;
    }
  }

  if (n != 1) {
    primes[n]++;
  }

  for (auto [a, b] : primes)
    cout << a << endl;
}
