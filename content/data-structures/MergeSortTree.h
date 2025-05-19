/**
 * Author: Ezz
 * Date: 2025-5-12
 * License: CC0
 * Source: idk
 * Description: Merge-Sort Tree for Range Queries.
 * The tree stores sorted segments of the array to allow efficient binary search for range queries.
 *
 * Time:
 *   - Construction: O(N log N)
 *   - Query: O(log^2 N)
 * Status: stress-tested
 */

struct MSTree {
  int n;
  vector<vector<int>> s;

  MSTree(vector<int> &a) {
    n = a.size();
    s.resize(2 * n);
    for (int i = 0; i < n; i++)
      s[i + n] = {a[i]};
    for (int i = n - 1; i > 0; i--) {
      auto &L = s[2 * i], &R = s[2 * i + 1];
      auto &P = s[i];
      P.reserve(L.size() + R.size());
      merge(all(L), all(R), back_inserter(P));
    }
  }
  // count of elements > x in [l..r)
  int query(int l, int r, int x) {
    int cnt = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        cnt += s[l].end() - upper_bound(all(s[l]), x);
        l++;
      }
      if (r & 1) {
        --r;
        cnt += s[r].end() - upper_bound(all(s[r]), x);
      }
    }
    return cnt;
  }
};
