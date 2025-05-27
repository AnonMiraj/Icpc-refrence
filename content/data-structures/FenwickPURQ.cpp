/**
 * Author: Ramez Medhat
 * Description: Point Update, Range Query
 * Time: O(logN)
 */
struct FenwickPURQ {    
    int n;
    vi f;

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) f[idx] += val;
    }
    
    int prefix(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += f[idx];
        return res;
    }
    
    FenwickPURQ(int size) : n(size), f(n + 1, 0) {}

    int rangeQuery(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }

    int lower_bound(int v){
        int sum = 0, pos = 0;
        for(int i = ceil(log2(n)); i >= 0; i--){
            int nextPos = pos + (1 << i);
            if(pos + (1 << i) < n && sum + f[nextPos] < v){
                sum += f[nextPos];
                pos = nextPos;
            }		
        }
        return pos + 1;
    }
};