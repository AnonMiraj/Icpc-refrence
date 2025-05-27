/**
 * Author: Ramez Medhat
 * Description: Range Update, Range Query
 * Time: O(logN)
 */
struct FenwickRURQ {
    int n;
    vi B1, B2;
    FenwickRURQ(int size) : n(size), B1(n+1, 0), B2(n+1, 0) {}

    void add(vi& f, int idx, int val) {
        for (; idx <= n; idx += idx & -idx) f[idx] += val;
    }

    int prefix(vi& f, int idx){
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += f[idx];
        return res;
    }

    void rangeUpdate(int l, int r, int val) {
        add(B1, l, val);
        add(B1, r + 1, -val);
        add(B2, l, val * (l - 1));
        add(B2, r + 1, -val * r);
    }

    int prefixQuery(int idx){
        int sumB1 = prefix(B1, idx);
        int sumB2 = prefix(B2, idx);
        return sumB1 * idx - sumB2;
    }

    int rangeQuery(int l, int r){
        return prefixQuery(r) - prefixQuery(l - 1);
    }
};