/**
 * Author: ezz
 * Description: Computes the smallest prime factor (SPF) for every number up to $N$ using a sieve.
 * Can be used for fast prime factorization in $O(\log n)$ per query after $O(N \log \log N)$ preprocessing.
 * Time: sieve - O(N \log \log N), factorization - O(\log n)
 * Status: Tested
 */

int NMAX = 1e6;
vi spf(NMAX + 1, 1);

spf[0] = 0; spf[1] = 1;
for (int i = 2; i <= NMAX; ++i)
    if (spf[i] == 1)
        for (int j = i; j <= NMAX; j += i)
            if (spf[j] == 1)
                spf[j] = i;

while (x > 1) {
    primes[spf[x]]++;
    x /= spf[x];
}

