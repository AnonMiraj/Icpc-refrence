int count_inversions_permutation(vector<int>& A) {
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        cnt += abs((i+1) - A[i]);
    }
    return cnt/2;
}

int count_inversions(vector<int>& A) {
    int cnt = 0;
    vector<int> B;
    B.push_back(A[0]);
    for (int i = 1; i < A.size(); i++) {
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        B.insert(it, A[i]);

        auto it_last = upper_bound(B.begin(), B.end(), A[i]);
        int idx_last = it_last - B.begin();
        
        cnt += B.size() - idx_last;
    }
    return cnt;
}
