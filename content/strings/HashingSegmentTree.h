/**
 * Author: Ramez
 * Date: 2026-08-03
 * License: CC0
 * Source: own
 * Description: Maintains a lowercase string with character
 * updates and substring queries. Use a second tree for the
 * reversed string to answer palindrome queries.
 * Usage:
 * int n = s.size(); string reversed = s;
 * reverse(all(reversed));
 * HashingSegmentTree forward(s), backward(reversed);
 * forward.update(i, c); backward.update(n-1-i, c);
 * bool palindrome = isPalindrome(forward, backward, l, r);
 * Time: $O(N)$ construction, $O(\log N)$ update/query
 * Memory: $O(N)$
 * Status: tested
 * Details: Indices are zero-based and ranges are inclusive.
 * query(l,r) returns a comparable value for s[l..r]. Equal
 * values for same-length substrings mean they are probably
 * equal. Collisions are theoretically possible.
 */
#pragma once

struct HashingSegmentTree {
	using HashValue = pair<long long, long long>;
	static constexpr long long mod1 = 1000000007;
	static constexpr long long mod2 = 2000000011;
	static constexpr long long base1 = 31;
	static constexpr long long base2 = 37;

private:
	vector<HashValue> seg;
	vector<long long> pw1, pw2, inv1, inv2;
	int n, treeSize;

	static long long powmod(long long a, long long b,
			long long mod) {
		long long ans = 1;
		for (; b; b >>= 1, a = a * a % mod)
			if (b & 1) ans = ans * a % mod;
		return ans;
	}

	static HashValue merge(HashValue a, HashValue b) {
		return {(a.first + b.first) % mod1,
			(a.second + b.second) % mod2};
	}

	HashValue rawQuery(int l, int r) const {
		HashValue ans = {0, 0};
		for (l += treeSize, r += treeSize + 1; l < r;
				l /= 2, r /= 2) {
			if (l & 1) ans = merge(ans, seg[l++]);
			if (r & 1) ans = merge(ans, seg[--r]);
		}
		return ans;
	}

public:
	explicit HashingSegmentTree(int n) : n(n), treeSize(1) {
		while (treeSize < n) treeSize *= 2;
		seg.assign(2 * treeSize, {0, 0});
		pw1.resize(n + 1); pw2.resize(n + 1);
		inv1.resize(n + 1); inv2.resize(n + 1);
		pw1[0] = pw2[0] = inv1[0] = inv2[0] = 1;
		long long ib1 = powmod(base1, mod1 - 2, mod1);
		long long ib2 = powmod(base2, mod2 - 2, mod2);
		for (int i = 1; i <= n; ++i) {
			pw1[i] = pw1[i - 1] * base1 % mod1;
			pw2[i] = pw2[i - 1] * base2 % mod2;
			inv1[i] = inv1[i - 1] * ib1 % mod1;
			inv2[i] = inv2[i - 1] * ib2 % mod2;
		}
	}

	explicit HashingSegmentTree(const string& s)
			: HashingSegmentTree(s.size()) {
		for (int i = 0; i < n; ++i) {
			long long value = s[i] - 'a' + 1;
			seg[treeSize + i] = {value * pw1[i] % mod1,
				value * pw2[i] % mod2};
		}
		for (int i = treeSize - 1; i; --i)
			seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
	}

	void update(int index, char ch) {
		long long value = ch - 'a' + 1;
		int node = treeSize + index;
		seg[node] = {value * pw1[index] % mod1,
			value * pw2[index] % mod2};
		for (node /= 2; node; node /= 2)
			seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}

	HashValue query(int l, int r) const {
		HashValue ans = rawQuery(l, r);
		ans.first = ans.first * inv1[l] % mod1;
		ans.second = ans.second * inv2[l] % mod2;
		return ans;
	}

	int size() const { return n; }
};

bool isPalindrome(const HashingSegmentTree& forward,
		const HashingSegmentTree& reverse, int l, int r) {
	int n = forward.size();
	return forward.query(l, r) ==
		reverse.query(n - 1 - r, n - 1 - l);
}
