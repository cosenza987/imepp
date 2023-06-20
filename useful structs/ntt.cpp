const int mod = 998244353, root = 3, N = 1.2e6 + 7;

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
    inline void init(int n) {
        w[0] = 1;
        k = binexp(root, (mod - 1) / n);
        nrev = binexp(n, mod - 2);
        for(int i = 1; i <= n; i++) {
            w[i] = (w[i - 1] * k) % mod;
        }
    }
    inline void ntt(vector<long long> &a, int n, bool inv = false) {
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
    vector<long long> multiply(vector<long long> &a, vector<long long> &b, int n) {
        init(n);
        ntt(a, n);
        ntt(b, n);
        vector<long long> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = (a[i] * b[i]) % mod;
        }
        ntt(ans, n, true);
        return ans;
    }
}
