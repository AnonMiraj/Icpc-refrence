/**
 * Author: Ramez Medhat
 * Description: Computes sums a[i,j] for all i<N, j<M, and increases single elements a[i,j].
 * Time: $O(\log N \cdot \log M)$. 
 */
#pragma once
struct Fenwick2D {
    int n, m;
    vector<vi> f;

    Fenwick2D(int _n, int _m) : n(_n), m(_m), f(n + 1, vi(m + 1, 0)) {}

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) 
            for (int j = y; j <= m; j += j & -j) 
                f[i][j] += val;
    }

    int prefixSum(int x, int y) const {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) 
            for (int j = y; j > 0; j -= j & -j) 
                res += f[i][j];
        return res;
    }

    int rangeSum(int x1, int y1, int x2, int y2) const {
        return prefixSum(x2, y2) - prefixSum(x1 - 1, y2) - prefixSum(x2, y1 - 1) + prefixSum(x1 - 1, y1 - 1);
    }
};
