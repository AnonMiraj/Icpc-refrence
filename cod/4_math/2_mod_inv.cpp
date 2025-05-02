// a and b must be co-prime. returns (1 / a) mod b.
ll mod_inv(ll a, ll b) {
    return 1 < a ? b - mod_inv(b % a, a) * b / a : 1;
}

