/**
 * Author: Ramez Medhat
 * Description: just like normal sieve but faster
 * Time: lim=100'000'000 $\approx$ 0.8 s. Runs 30\% faster if only odd indices are stored.
 * Status: Tested
 */

vi linearSieve(int n) {
	vector<bool> isPr(n + 1, 1);
	vi primes;
	isPr[0] = isPr[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (isPr[i]) primes.push_back(i);
		for (int p : primes) {
			if (i * p >= n + 1) break;
			isPr[i * p] = 0;
			if (i % p == 0) break;
		}
	}
	return primes;
}