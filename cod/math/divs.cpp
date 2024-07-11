void divs() {
    const int n = 1e6;
    vector<vector<int>> divs(n);

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            divs[j].push_back(i);
        }
    }

    // all divisors of 12  
    for (auto fact : divs[12])
        cout << fact << endl;
}

vector<int> divisors;
void getDivisors(int n) {
    for (int i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
}
