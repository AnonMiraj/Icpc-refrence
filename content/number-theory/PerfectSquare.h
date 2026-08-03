/**
 * Author: Ramez
 * Date: 2026-08-03
 * License: CC0
 * Source: own
 * Description: Tests whether a signed 64-bit integer is a
 * perfect square. Corrects floating-point rounding from
 * \texttt{sqrtl}.
 * Time: $O(1)$
 * Memory: $O(1)$
 * Status: tested
 */
#pragma once

bool is_perfect_square(long long x) {
	if (x < 0) return false;
	long long y = sqrtl((long double)x);
	while ((__int128)y * y < x) ++y;
	while ((__int128)y * y > x) --y;
	return (__int128)y * y == x;
}
