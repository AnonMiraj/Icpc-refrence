
    vector<vector<Z>> pascal;
    void build_pascal(int d) {
        pascal = {{1}};
        while (d--) {
            vector<Z> &lastrow = pascal.back();
            int s = lastrow.size();
            vector<Z> newrow(s + 1);
            newrow.front() = 1;
            newrow.back() = 1;
            for (int i = 1; i < s; i++)
                newrow[i] = lastrow[i] + lastrow[i - 1];
            pascal.push_back(newrow);
        }
    }
