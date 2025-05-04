// Range Update, Point Quer
struct FenwickRUPQ {
    int n;
    vi f;
    FenwickRUPQ(int _n) : n(_n), f(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }

    void rangeAdd(int l, int r, int val) {
        update(l, val);
        if (r + 1 <= n) update(r + 1, -val);
    }

    int pointQuery(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }
};