// Range Update, Range Query
struct FenwickRURQ {
    int n;
    vi B1, B2;
    FenwickRURQ(int _n) : n(_n), B1(n + 1, 0), B2(n + 1, 0) {}

private:
    void update(vi &bit, int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(vi &bit, int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int preSum(int idx) {
        return query(B1, idx) * idx - query(B2, idx);
    }

public:
    void rangeAdd(int l, int r, int val) {
        update(B1, l, val);
        update(B1, r + 1, -val);
        update(B2, l, val * (l - 1));
        update(B2, r + 1, -val * r);
    }

    int rangeQuery(int l, int r) {
        return preSum(r) - preSum(l - 1);
    }
};