
/**
 * Author: Mohamed El-Sayed
 * Description:   Square‐root decomposition for range sum queries with point updates.
  Preprocesses the array into blocks of size ~sqrt(n), maintaining the sum of each block.
  query(l, r): returns the sum of arr[l..r] in O(sqrt(n)) time.
  update(idx, val): updates arr[idx] to val and adjusts the corresponding block sum in O(1).
  When to use:
  - You have an array of size n (up to $10^5$) with mixed range‐sum queries and point updates.
  - You need better performance than O(n) per operation but segment trees are overkill.
 * Time: O(sqrt(n)) per query, O(1) per update.
 * Status: stress-tested
 */
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int n, q, SQ;
vi arr, blkSum;

// Build block sums from the initial array in O(n)
void preProcess() {
    // For each element, add it to its block's sum
    for (int i = 0; i < n; ++i) {
        int blk = i / SQ;
        blkSum[blk] += arr[i];
    }
}

// Query the sum in the interval [l, r] in O(sqrt(n))
int query(int l, int r) {
    int ans = 0;
    // Process elements until we reach block boundary or exceed r
    while (l <= r) {
        // If l is at the start of a block and the whole block lies within [l, r]
        if (l % SQ == 0 && l + SQ - 1 <= r) {
            ans += blkSum[l / SQ];
            l += SQ;
        } else {
            // Otherwise, take the single element
            ans += arr[l];
            ++l;
        }
    }
    return ans;
}

// Point update: set arr[idx] = val in O(1)
void update(int idx, int val) {
    int blk = idx / SQ;
    // Remove old value from block sum and add new value
    blkSum[blk] -= arr[idx];
    arr[idx] = val;
    blkSum[blk] += val;
}

void solve() {
    // Read array size and number of operations
    cin >> n >> q;
    arr.resize(n);
    cin >> arr;

    // Determine block size and initialize block sums
    SQ = ceil(sqrt(n));
    blkSum.assign((n + SQ - 1) / SQ, 0);

    preProcess();

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // Update operation: 1 pos val
            int pos, val;
            cin >> pos >> val;
            update(pos - 1, val);
        } else {
            // Query operation: 2 l r
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1) << "\n";
        }
    }
}