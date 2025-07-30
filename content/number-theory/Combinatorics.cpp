/**
 * Author: Ramez 
 * Description: Function to solve combinatorics problems.
 * Time: O(n) for init and O(1) for query
 */

namespace combinatorics {
    vector<int> fact, inv, invFact;

    int pwmod(int a, int b) {
        a %= MOD;
        int result = 1;
        while (b > 0) {
            if (b & 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return result;
    }

    int inverse(int x) { return pwmod(x, MOD - 2); }
    int multiply(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
    int divide(int a, int b) { return multiply(a, inverse(b)); }

    void init(int n) {
        fact.resize(n + 1); inv.resize(n + 1); invFact.resize(n + 1);
        fact[0] = fact[1] = inv[0] = inv[1] = invFact[0] = invFact[1] = 1; 
        for (int i = 2; i <= n; ++i){
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - ((MOD / i) * inv[MOD % i]) % MOD;
            invFact[i] = invFact[i - 1] * inv[i] % MOD;
        } 
    }

    int nPr(int n, int r) {
        if (n < 0 || r < 0 || r > n) return 0;
        return fact[n] * invFact[n - r] % MOD;
    }

    int nCr(int n, int r) {
        if (n < 0 || r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int nPrLinear(int n, int r){
        int answer = 1;
        for (int i = n - r + 1; i <= n; i++){
            answer = multiply(answer, i);
        }
        return answer;
    }

    int nCrLinear(int n, int r){
        int answer = 1;
        for (int i = r + 1; i <= n; i++){
            answer = multiply(answer, i);
            answer = divide(answer, i - r);
        }
        return answer;
    }
};
using namespace combinatorics;