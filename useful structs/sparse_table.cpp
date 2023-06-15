struct sparse_table {
    vector<vector<int>> table;
    int n;
    sparse_table(vector<int> &v) {
        n = v.size();
        table.resize(30, vector<int>(n));
        for(int i = 0; i < n; i++) {
            table[0][i] = v[i];
        }
        for(int j = 1; j <= 31 - __builtin_clz(n); j++) {
            for(int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int j = 31 - __builtin_clz(r - l + 1);
        return min(table[j][l], table[j][r - (1 << j) + 1]);
    }
};
