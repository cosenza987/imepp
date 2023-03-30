const int maxn = 2e5 + 7;

vector<int> v;
long long table[maxn][30];

void bst(int n) {
    for(int i = 0; i < n; i++) {
        table[i][0] = v[i];
    }
    for(int j = 1; j <= 31 - __builtin_clz(n); j++) {
        for(int i = 0; i <= n - (1 << j); i++) {
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int j = 31 - __builtin_clz(r - l + 1);
    return __gcd(table[l][j], table[r - (1 << j) + 1][j]);
}
