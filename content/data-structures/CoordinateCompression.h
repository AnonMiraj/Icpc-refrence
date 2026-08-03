/**
 * Author: Ramez
 * Date: 2026-08-03
 * License: CC0
 * Source: own
 * Description: Stores the sorted distinct values of an array.
 * \texttt{index(x)} returns how many stored values are smaller
 * than $x$. \texttt{initVal(i)} reverses a valid index.
 * Time: $O(N \log N)$ construction, $O(\log N)$ index
 * Memory: $O(N)$
 * Status: tested
 */
#pragma once

struct CoordinateCompression {
private:
	vector<long long> values;

public:
	CoordinateCompression(const vector<long long>& v)
			: values(v) {
		sort(all(values));
		values.erase(unique(all(values)), values.end());
	}

	int index(long long value) const {
		return lower_bound(all(values), value) - values.begin();
	}

	long long initVal(int index) const {
		return values[index];
	}
};
