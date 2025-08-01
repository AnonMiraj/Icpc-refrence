/**
 * Author: Ramez Medhat
 * Description: Handles RURQ for XOR
 * Time: $O(\log N \cdot \log M)$. 
 */
#pragma once

struct Fenwick2DXOR {
    int n, m;
    vector<vi> bit[2][2];

    Fenwick2DXOR(int _n, int _m) : n(_n), m(_m) {
        for (int px = 0; px < 2; ++px)
            for (int py = 0; py < 2; ++py)
                bit[px][py].assign(n+2, vi(m+2, 0));
    }

    void pointXOR(int x, int y, int v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                bit[x&1][y&1][i][j] ^= v;
    }

    void rangeXOR(int x1, int y1, int x2, int y2, int v) {
        if (x1 > x2 || y1 > y2) return;
        auto upd = [&](int x, int y){ if (x > 0 && y > 0) pointXOR(x, y, v); };
        upd(x1,      y1);
        upd(x2 + 1,  y1);
        upd(x1,      y2 + 1);
        upd(x2 + 1,  y2 + 1);
    }

    int prefixXOR(int x, int y) {
        if (x <= 0 || y <= 0) return 0;
        int res = 0;
        int px = x & 1, py = y & 1;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                res ^= bit[px][py][i][j];
        return res;
    }

    int rangeQuery(int x1, int y1, int x2, int y2) {
        int res = 0;
        res ^= prefixXOR(x2,   y2);
        res ^= prefixXOR(x1-1, y2);
        res ^= prefixXOR(x2,   y1-1);
        res ^= prefixXOR(x1-1, y1-1);
        return res;
    }
};

