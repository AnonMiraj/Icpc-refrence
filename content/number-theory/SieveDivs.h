/**
 * Author: ezz
 * Date: 2025-05-03
 * License: CC0
 * Description: Computes all divisors for every number in the range $[1, n)$.
 * Returns a vector of vectors where result[i] contains all divisors of i.
 * Time: $O(n \log n)$
 */
vector<vi> divs(1e6);
for (int i = 1; i < sz(divs); ++i)
    for (int j = i; j < sz(divs); j += i)
        divs[j].push_back(i);
    }
