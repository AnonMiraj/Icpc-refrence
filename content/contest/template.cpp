#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng = mt19937(random_device()());

int rand_int(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

void solve() {

}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
