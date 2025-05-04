/**
 * Author: Simon Lindholm
 * Date: 2015-06-23
 * License: CC0
 * Source: own work
 * Description: Sums of mod'ed arithmetic progressions.
 *
 * \texttt{modsum(to, c, k, m)} = $\sum_{i=0}^{\mathrm{to}-1}{(ki+c) \% m}$.
 * \texttt{divsum} is similar but for floored division.
 * Time: $\log(m)$, with a large constant.
 * Status: Tested for all |k|,|c|,to,m <= 50, and on kattis:aladin
 */
#pragma once

typedef unsigned long long uint;
uint sumsq(uint to) { return to / 2 * ((to-1) | 1); }
/// ^ written in a weird way to deal with overflows correctly

uint divsum(uint to, uint c, uint k, uint m) {
	uint res = k / m * sumsq(to) + c / m * to;
	k %= m; c %= m;
	if (!k) return res;
	uint to2 = (to * k + c) / m;
	return res + (to - 1) * to2 - divsum(to2, m-1 - c, m, k);
}

int modsum(uint to, int c, int k, int m) {
	c = ((c % m) + m) % m;
	k = ((k % m) + m) % m;
	return to * c + k * sumsq(to) - m * divsum(to, c, k, m);
}
