/**
 * Author: Ramez Medhat
 * Description: Range Update, Point Query
 * Time: O(logN)
 */
struct FenwickRUPQ {
    int n;
    vi f;
    FenwickRUPQ(int _n) : n(_n), f(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }

    void rangeAdd(int l, int r, int val) {
        add(l, val);
        if (r + 1 <= n) add(r + 1, -val);
    }

    // quary
    int pointQuery(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }
};