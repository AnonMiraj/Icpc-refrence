#define fastio()                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);

struct Query {
  int l, r, idx;
  bool
  operator<(const Query &other) const { // first if they are not starting at the
                                        // same block then sort with l
                                        // if they are the same then sort buy r
    int block_size = 450;
    int block_a = l / block_size;
    int block_b = other.l / block_size;
    if (block_a != block_b)
      return block_a < block_b;
    return r < other.r;
  }
};
void solve() {
  fastio();
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  vector<Query> queries(q); // store queres to make offline process
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    queries[i] = {--l, --r, i}; // convert to 0-based
  }

  sort(queries.begin(), queries.end()); // sort to make the largest amount of
                                        // overlaping with logic at struct

  vector<int> freq(1e6 + 5, 0); // store frq numbers
  int distinct = 0;
  int l = 0, r = -1;
  vector<int> ans(q);

  for (auto query :
       queries) { // shrink and extend logic and calc the new distinct elements
    while (r < query.r)
      if (++freq[a[++r]] == 1)
        ++distinct;
    while (r > query.r)
      if (--freq[a[r--]] == 0)
        --distinct;
    while (l < query.l)
      if (--freq[a[l++]] == 0)
        --distinct;
    while (l > query.l)
      if (++freq[a[--l]] == 1)
        ++distinct;
    ans[query.idx] = distinct;
  }

  for (int x : ans)
    cout << x << '\n';
}
