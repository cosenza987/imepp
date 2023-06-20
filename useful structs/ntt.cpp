long long binexp(long long a, long long n) {
    long long res = 1;
    while(n) {
        if(n & 1) {
            res = (res * a) % mod;
        }
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

namespace ntt {
    long long w[N], k, nrev;
    inline void init(int n, int root, int mod) {
        w[0] = 1;
        k = binexp(root, (mod - 1) / n, mod);
        nrev = binexp(n, mod - 2, mod);
        for(int i = 1; i <= n; i++) {
            w[i] = (w[i - 1] * k) % mod;
        }
    }
    inline void ntt(vector<long long> &a, int n, int mod, bool inv = false) {
        a.resize(n);
        for(int i = 0, j = 0; i < n; i++) {
            if(i > j) swap(a[i], a[j]);
            for(int l = n / 2; (j ^= l) < l; l >>= 1);
        }
        for(int i = 2; i <= n; i <<= 1) {
            for(int j = 0; j < n; j += i) {
                for(int l = 0; l < i / 2; l++) {
                    int x = j + l, y = j + l + (i / 2), z = (n / i) * l;
                    long long tmp = (a[y] * w[(inv ? (n - z) : z)]) % mod;
                    a[y] = (a[x] - tmp + mod) % mod;
                    a[x] = (a[j + l] + tmp) % mod;
                }
            }
        }
        if(inv) {
            for(int i = 0; i < n; i++) {
                a[i] = (a[i] * nrev) % mod;
            }
        }
    }
    vector<long long> multiply(vector<long long>& a, vector<long long>& b, int n, int root = 3, int mod = 998244353) {
        init(n, root, mod);
        ntt(a, n, mod);
        ntt(b, n, mod);
        vector<long long> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = (a[i] * b[i]) % mod;
        }
        ntt(ans, n, mod, true);
        return ans;
    }
    vector<long long> multiply_garner(vector<long long> &a, vector<long long> &b, int n, int mod) {
        vector<long long> primes = {1004535809, 998244353, 985661441};
        vector<long long> x[3], y[3], z[3];
        for(int p = 0; p < 3; p++) {
            x[p].resize(n);
            y[p].resize(n);
            for(int i = 0; i < n; i++) {
                x[p][i] = a[i] % primes[p];
                y[p][i] = b[i] % primes[p];
            }
        }
        for(int p = 0; p < 3; p++) {
            z[p] = multiply(x[p], y[p], n, 3, primes[p]);
        }
        vector<long long> ans(n);
        long long r01 = binexp(primes[0], primes[1] - 2, primes[1]);
        long long r02 = binexp(primes[0], primes[2] - 2, primes[2]);
        long long r12 = binexp(primes[1], primes[2] - 2, primes[2]);
        for(int i = 0; i < n; i++) {
            long long a0 = z[0][i];
            long long a1 = (((z[1][i] - z[0][i] + 2 * primes[1]) % primes[1]) * r01) % primes[1];
            long long a2 = (((z[2][i] - z[0][i] + 2 * primes[2]) % primes[2]) * r02) % primes[2];
            a2 = ((a2 - a1 + 2 * primes[2]) % primes[2]) * r12 % primes[2];
            long long res = a0 % mod;
            res = (res + a1 * (primes[0] % mod)) % mod;
            res = (res + a2 * ((primes[0] % mod) * (primes[1] % mod) % mod)) % mod;
            ans[i] = res;
        }
        return ans;
    }
}
