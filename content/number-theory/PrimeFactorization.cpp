/**
 * Author: Ramez Medhat
 * Description: gets the prime factors of a number
 * Time: $O(\sqrt{n})$
 * Status: Tested
 */

vector<pair<int, int>> getPrimeFactors(int n) {
    vector<pair<int, int>> primeFactors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) n /= i, count++;
            primeFactors.push_back({i, count});
        }
    }
    if (n > 1) primeFactors.push_back({n, 1});
    return primeFactors;
}