//https://codeforces.com/contest/86/problem/D

//Слава Україні, Героям слава 🇺🇦

#include <bits/stdc++.h>

using namespace std;

long long cnt[(int)1e6 + 7], sqt;

struct fuck {
    int l, r, t;
    friend bool operator < (const fuck a, const fuck b) {
        if(a.l / sqt == b.l / sqt) {
            return a.r < b.r;
        } else {
            return a.l / sqt < b.l / sqt;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<long long> v(n), ans(t);
    vector<fuck> q(t);
    sqt = sqrt(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < t; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].t = i;
    }
    sort(q.begin(), q.end());
    int l = 0, r = -1;
    long long cur = 0;
    for(int i = 0; i < t; i++) {
        while(l > q[i].l) {
            l--;
            cur -= cnt[v[l]] * cnt[v[l]] * v[l];
            cnt[v[l]]++;
            cur += cnt[v[l]] * cnt[v[l]] * v[l];
        }
        while(r > q[i].r) {
            cur -= cnt[v[r]] * cnt[v[r]] * v[r];
            cnt[v[r]]--;
            cur += cnt[v[r]] * cnt[v[r]] * v[r];
            r--;
        }
        while(r < q[i].r) {
            r++;
            cur -= cnt[v[r]] * cnt[v[r]] * v[r];
            cnt[v[r]]++;
            cur += cnt[v[r]] * cnt[v[r]] * v[r];
        }
        while(l < q[i].l) {
            cur -= cnt[v[l]] * cnt[v[l]] * v[l];
            cnt[v[l]]--;
            cur += cnt[v[l]] * cnt[v[l]] * v[l];
            l++;
        }
        ans[q[i].t] = cur;
    }
    for(auto e : ans) {
        cout << e << "\n";
    }
    return 0;
}
