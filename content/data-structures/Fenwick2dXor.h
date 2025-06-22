/**
 * Author: Ramez Medhat
 * Description: Handles RURQ for XOR
 * Time: $O(\log N \cdot \log M)$. 
 */
#pragma once
struct Fenwick2DAdd {
    int n, m;
    vector<vi> T1, T2, T3, T4;

    Fenwick2DAdd(int _n, int _m)
        : n(_n), m(_m),
          T1(n+1, vi(m+1)),
          T2(n+1, vi(m+1)),
          T3(n+1, vi(m+1)),
          T4(n+1, vi(m+1))
    {}

    void add(vector<vi>& t, int x, int y, int v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                t[i][j] += v;
    }

    void rangeAdd(int x, int y, int v) {
        add(T1, x, y, v);
        add(T2, x, y, v * (y - 1));
        add(T3, x, y, v * (x - 1));
        add(T4, x, y, v * (x - 1) * (y - 1));
    }

    void rangeUpdate(int x1, int y1, int x2, int y2, int val) {
        rangeAdd(x1, y1, val);
        rangeAdd(x1, y2 + 1, -val);
        rangeAdd(x2 + 1, y1, -val);
        rangeAdd(x2 + 1, y2 + 1, val);
    }

    int prefixSum(int x, int y) const {
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j) {
                s1 += T1[i][j];
                s2 += T2[i][j];
                s3 += T3[i][j];
                s4 += T4[i][j];
            }
        return s1 * x * y - s2 * x - s3 * y + s4;
    }

    int rangeQuery(int x1, int y1, int x2, int y2) const {
        return prefixSum(x2, y2)
             - prefixSum(x1 - 1, y2)
             - prefixSum(x2, y1 - 1)
             + prefixSum(x1 - 1, y1 - 1);
    }
};