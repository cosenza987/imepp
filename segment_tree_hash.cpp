//Слава Україні, Героям слава 🇺🇦

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

template <int mod = (int)1e9 + 7> struct modint {
    int x;
    modint(int y = 0) : x((y% mod + mod) % mod) { }
    friend modint operator ^ (modint a, long long b) {
        modint r = 1;
        for (; b; b >>= 1, a *= a) {
            if (b & 1) {
                r *= a;
            }
        }
        return r;
    }
    friend modint operator - (modint a) {
        return modint(0) - a;
    }
    friend modint operator ! (modint a) {
        return a ^ (mod - 2);
    }
    modint& operator /= (modint const& b) {
        return *this *= !b;
    }
    friend modint operator + (modint a, modint const& b) {
        return a += b;
    }
    friend modint operator - (modint a, modint const& b) {
        return a -= b;
    }
    friend modint operator * (modint a, modint const& b) {
        return a *= b;
    }
    friend modint operator / (modint a, modint const& b) {
        return a /= b;
    }
    friend bool operator != (const modint& a, const modint b) {
        return a.x != b.x;
    }
    friend bool operator == (const modint& a, const modint b) {
        return a.x == b.x;
    }
    modint& operator *= (modint const& b) {
        x = 1ll * x * b.x % mod;
        return *this;
    }
    friend ostream& operator << (ostream& os, modint const& a) {
        return os << a.x;
    }
    modint& operator += (modint const& b) {
        x += b.x;
        x = (x >= mod) ? x - mod : x;
        return *this;
    }
    modint& operator -= (modint const& b) {
        x = x >= b.x ? x - b.x : x - b.x + mod;
        return *this;
    }
};

using mint = modint<>;

vector<mint> pr;
const int prime = 1777771;

struct seg_hash {
    int n;
    string s;
    vector<mint> st;
    void build(int p, int l, int r) {
        if(l == r) {
            st[p] = static_cast<int>(s[l - 1]);
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);
        st[p] = st[2 * p] * pr[r - mid] + st[2 * p + 1];
    }
    void init(string s_) {
        s = s_;
        n = s_.size() + 1;
        st.resize(4 * n);
        n = s.size();
        build(1, 1, n);
    }
    seg_hash() {}
    mint query(int i, int j) {
        return query(i, j, 1, 1, n);
    }
    mint query(int i, int j, int p, int l, int r) {
        if(r < i or j < l) {
            return 0;
        }
        if(i <= l and r <= j) {
            return st[p];
        }
        int mid = (l + r) >> 1;
        mint x = query(i, j, 2 * p, l, mid);
        mint y = query(i, j, 2 * p + 1, mid + 1, r);
        return x * pr[r - mid] + y;
    }
    void update(int x, int v) {
        update(x, v, 1, 1, n);
    }
    void update(int x, int v, int p, int l, int r) {
        if(x < l or r < x) {
            return;
        }
        if(l == r and l == x) {
            st[p] = v;
            return;
        }
        int mid = (l + r) >> 1;
        update(x, v, 2 * p, l, mid);
        update(x, v, 2 * p + 1, mid + 1, r);
        st[p] = st[2 * p] * pr[r - mid] + st[2 * p + 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pr.resize(200007);
    pr[0] = 1;
    for(int i = 1; i < 200007; i++) {
        pr[i] = pr[i - 1] * prime;
    }
    int n, q;
    cin >> n >> q;
    vector<pair<seg_hash, seg_hash>> v(n + 1);
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        v[i].first.init(s);
        reverse(s.begin(), s.end());
        v[i].second.init(s);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i, j;
            char c;
            cin >> i >> j >> c;
            v[i].first.update(j, static_cast<int>(c));
            v[i].second.update(v[i].second.n - j + 1, static_cast<int>(c));
        } else if(t == 2) {
            int i, j, l1, r1, l2, r2;
            cin >> i >> j >> l1 >> r1 >> l2 >> r2;
            mint a = v[i].first.query(l1, r1) * pr[l1 - 1];
            mint b = v[j].first.query(l2, r2) * pr[l2 - 1];
            int diff = abs(v[i].first.n - v[j].first.n);
            if(v[i].first.n > v[j].first.n) {
                b *= pr[diff];
            } else if(v[i].first.n < v[j].first.n) {
                a *= pr[diff];
            }
            cout << (a == b ? "equal\n" : "different\n");
        } else {
            int i, j, l1, r1, l2, r2;
            cin >> i >> j >> l1 >> r1 >> l2 >> r2;
            int diff = abs(v[i].first.n - v[j].first.n);
            mint a, b, c, d;
            a = v[i].first.query(l1, r1) * pr[l1 - 1];
            b = v[i].second.query(v[i].second.n - r1 + 1, v[i].second.n - l1 + 1) * pr[v[i].second.n - r1];
            c = v[j].first.query(l2, r2) * pr[l2 - 1];
            d = v[j].second.query(v[j].second.n - r2 + 1, v[j].second.n - l2 + 1) * pr[v[j].second.n - r2];
            if(v[i].first.n > v[j].first.n) {
                c *= pr[diff];
                d *= pr[diff];
            } else if(v[i].first.n < v[j].first.n) {
                a *= pr[diff];
                b *= pr[diff];
            }
            a = (a * pr[r1 - l1 + 1] + c) * pr[r2 - l2 + 1];
            d = (d * pr[r2 - l2 + 1] + b) * pr[r1 - l1 + 1];
            cout << (a == d ? "cool\n" : "not so cool\n");
        }
    }
    return 0;
}
