/**
 * Author: Ramez
 * Date: 2026-08-03
 * License: CC0
 * Source: own
 * Description: Returns the number of positive divisors of $n$.
 * Removes factors up to 19, then checks the remaining factors
 * using a wheel coprime to their product. Requires $n \ge 1$.
 * Time: $O(\sqrt n)$
 * Memory: $O(1)$
 * Status: tested
 */
#pragma once

#include <cassert>

long long numberOfDivisors(long long n) {
	assert(n >= 1);
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	int wheel = 1;
	long long ans = 1;
	for (int p : primes) {
		int exponent = 0;
		while (n % p == 0) {
			n /= p;
			++exponent;
		}
		ans *= exponent + 1;
		wheel *= p;
	}

	long long residualDivisors = 0;
	for (long long i = 1; i < wheel && i <= n / i; ++i) {
		bool coprime = true;
		for (int p : primes) {
			if (i % p == 0) {
				coprime = false;
				break;
			}
		}
		if (!coprime) continue;

		long long d = i;
		for (; d < n / d; d += wheel)
			if (n % d == 0) residualDivisors += 2;
		if (d == n / d && n % d == 0) ++residualDivisors;
	}
	return ans * residualDivisors;
}
