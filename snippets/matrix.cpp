struct matrix {
    long long mat[2][2];
    matrix() {
        memset(mat, 0, sizeof(mat));
    }
    matrix(long long a, long long b, long long c, long long d) {
        mat[0][0] = a % mod;
        mat[0][1] = b % mod;
        mat[1][0] = c % mod;
        mat[1][1] = d % mod;
    }
    matrix(const matrix& fuck) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                mat[i][j] = fuck.mat[i][j];
            }
        }
    }
    matrix operator*(matrix fuck) const {
        matrix m;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    m.mat[i][j] = (m.mat[i][j] + mat[i][k] * fuck.mat[k][j] % mod) % mod;
                }
            }
        }
        return m;
    }
    matrix pow(long long p) const {
        matrix res(1, 0, 0, 1);
        matrix b = *this;
        while(p > 0) {
            if(p & 1ll) {
                res = res * b;
            }
            p >>= 1ll;
            b = b * b;
        }
        return res;
    }
};