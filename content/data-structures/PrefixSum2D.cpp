
/**
 * Author: Ramez Medhat
 * Description: gets the sum of a square
 * Time: O(n * m) for build O(1) for query 
 * Status: Tested
 */

vector<vi> prefixSum2D(vector<vi>& a) {
    vector<vi> b(a.size(), vi(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

int sumOfSquare(int x1, int y1, int x2, int y2, vector<vi>& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}