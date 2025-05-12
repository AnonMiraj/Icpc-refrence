/**
 * Author: Mosamir
 * License:
 * Source: mosamir
 * Description: Self-explanatory methods for string hashing.
 */
#pragma once

constexpr int H = 2;
typedef array<long long, H> val;
vector<val> B;
const val M = {
    1000000007, 1444444447,
    // 998244353,
    // 1000000009,
};

val tmp;

val operator*(const val &a, const val &b) {
  for (int i = 0; i < H; i++)
    tmp[i] = a[i] * b[i] % M[i];
  return tmp;
}

val operator-(const val &a, const val &b) {
  for (int i = 0; i < H; i++)
    tmp[i] = (a[i] - b[i] + M[i]) % M[i];
  return tmp;
}

val operator+(const val &a, const val &b) {
  for (int i = 0; i < H; i++)
    tmp[i] = (a[i] + b[i]) % M[i];
  return tmp;
}

val getval(int x) {
  // make sure x is always positvie if not handle it
  for (int i = 0; i < H; i++)
    tmp[i] = x % M[i];
  return tmp;
}

void setB(int n) {
  if (B.size() == 0) {
    mt19937 rng(random_device{}());
    B.assign(2, getval(1));
    for (int i = 0; i < H; i++)
      B.back()[i] = uniform_int_distribution<int>(1, M[i] - 1)(rng);
  }
  while ((int)B.size() <= n)
    B.push_back(B.back() * B[1]);
}

struct Hash {
  vector<val> h;

  Hash(const string &s) : Hash(vector<int>(all(s))) {}

  Hash(const vector<int> &s) {
    vector<val> v;
    for (auto x : s)
      v.push_back(getval(x));
    *this = Hash(v);
  }

  Hash(const vector<val> &s) : h(s.size() + 1) {
    setB(s.size());
    for (int i = 0; i < (int)s.size(); i++)
      h[i + 1] = h[i] * B[1] + s[i];
  }
  val get(int l, int r) { return h[r + 1] - h[l] * B[r - l + 1]; }
};

// val concat(val &a, val &b, int len_b) { return a * B[len_b] + b; }
//
// struct val_hash {
//   size_t operator()(const val &v) const {
//       return hash<int>{}(v[0]) ^ (hash<int>{}(v[1]) << 1);
//   }
// };
