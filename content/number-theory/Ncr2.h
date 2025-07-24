/**
 * Author: ezz
 * Description:
 */

int nCr(int n, int r) {
  // Useful when r is very small
	if (r > n)
		return 0;
	r = min(r, n - r);
	int ans = 1;
	for (int i = 0; i < r; i++) {
		ans = ans * (n - i) % mod;
		ans = ans * modpow(i + 1, mod - 2) % mod;
	}
	return ans;
}
