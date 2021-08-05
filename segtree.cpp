#include <bits/stdc++.h>
 
#define int long long //preguica
 
using namespace std;
 
const int maxn = 1e5 + 7;
 
int st[4 * maxn], v[maxn];
 
void build(int p, int l, int r) {
    if(l == r) {
        st[p] = v[l];
        return;
    }
    build(2 * p, l, (l + r) / 2);
    build(2 * p + 1, (l + r) / 2 + 1, r);
    st[p] = st[2 * p] + st[2 * p + 1];
}
 
int query(int p, int l, int r, int i, int j) {
    if(r < i or j < l) {
        return 0;
    }
    if(i <= l and r <= j) {
        return st[p];
    }
    int x = query(2 * p, l, (l + r) / 2, i, j);
    int y = query(2 * p + 1, (l + r) / 2 + 1, r, i, j);
    return x + y;
}
 
void update(int p, int l, int r, int x, int v) {
    if(x < l or r < x) {
        return;
    }
    if(l == r and l == x) {
        st[p] += v;
        return;
    }
    update(2 * p, l, (l + r) / 2, x, v);
    update(2 * p + 1, (l + r) / 2 + 1, r, x, v);
    st[p] = st[2 * p] + st[2 * p + 1];
}
 
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--) {
        char qq;
        cin >> qq;
        if(qq == 'q') {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
        } else {
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x - 1, v);
        }
    }
    return 0;
} 
