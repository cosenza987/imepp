#define defop(type, op) \
    inline friend type operator op (type u, const type& v) { return u op ##= v; } \
    type& operator op##=(const type& o)
template<int mod>
struct modint {
    int x;
    // note that there is no correction, simply for speed
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x(int(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, * ) { return *this = modint(1ll * x * o.x); }
    modint pow(ll exp) const {
        modint ans = 1, base = *this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) { return *this *= o.pow(mod - 2); }
};
using mint = modint<(int)1e9 + 7>;