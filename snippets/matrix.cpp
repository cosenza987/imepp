const int mod = 1e9 + 7;

struct matrix {
    vector<vector<long long>> v;
    int n;
    matrix(int n_) {
        n = n_;
        v.assign(n, vector<long long>(n));
    }
    matrix operator * (matrix b) const {
        matrix m(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    m.v[i][j] = (m.v[i][j] + v[i][k] * b.v[k][j] % mod) % mod;
                }
            }
        }
        return m;
    }
    matrix operator ^ (long long x) const {
        matrix m(n);
        matrix base = *this;
        for(int i = 0; i < n; i++) {
            m.v[i][i] = 1;
        }
        while(x) {
            if(x & 1) {
                m = (m * base);
            }
            x >>= 1;
            base = (base * base);
        }
        return m;
    }
};
