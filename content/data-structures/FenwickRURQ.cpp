/**
 * Author: Ramez Medhat
 * Description: Range Update, Range Query
 * Time: O(logN)
 */
template<typename T>
struct FenwickRURQ {
    int n;
    vector<T> B1, B2;
    static constexpr T unit = 0;
    T f(T& a, T& b) { return a + b; }
    FenwickRURQ(int size) : n(size), B1(size + 1, unit), B2(size + 1, unit) {}

private:
    void add(vector<T>& B, int i, T v) {
        for (; i <= n; i += i & -i) B[i] = f(B[i], v);
    }

    T prefix(int x) {
        T sum1 = unit, sum2 = unit;
        for (int i = x; i > 0; i -= i & -i) {
            sum1 = f(sum1, B1[i]);
            sum2 = f(sum2, B2[i]);
        }
        return sum1 * x - sum2;
    }

public:
    void rangeAdd(int l, int r, T v) {
        add(B1, l, v);
        add(B1, r + 1, -v);
        add(B2, l, v * (l - 1));
        add(B2, r + 1, -v * r);
    }

    T rangeSum(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }
};