/**
 * Author: Noam527
 * Date: 2025-04-24
 * License: CC0
 * Source: ezz
 * Description:
 * Status: tested
 */
#pragma once

const int mod = 1000000007; // faster if const

int modpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
