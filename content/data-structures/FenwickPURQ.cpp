/**
 * Author: Ramez Medhat
 * Description: Point Update, Range Query
 * Time: O(logN)
 */
struct FenwickPURQ {
    int n;
    vi f;
    FenwickPUPQ(int _n) : n(_n), f(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};