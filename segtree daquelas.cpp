//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//THESE ARE LAST DITCH EFFORTS!!!
//don't forget how naum did it https://pastebin.com/uN6FbuuC

#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 7;

int sgt[maxn], lz[maxn], lzinv[maxn];

void push(int p, int l, int r) {
    if(l < r) {
        lz[2 * p] = lz[p] + lzinv[p] * lz[2 * p]; //we need to propagate to the right the inversions that happen
        lz[2 * p + 1] = lz[p] + lzinv[p] * lz[2 * p + 1];
        lzinv[2 * p] *= lzinv[p];
        lzinv[2 * p + 1] *= lzinv[p];
    } else {
        sgt[l] = 2 * lz[p] + lzinv[p] * sgt[l]; // if the range you're pushing is already close enough, no propagation is needed and you simply change the value in the array
    }
    lz[p] = 0; //resetting after propagation
    lzinv[p] = 1;
}

int get(int pq, int p = 1, int l = 0, int r = 1e5) { //literally a binary search to find the value, though you must propagate what's been stored in the lazy
    push(p, l, r);
    if(l == r and pq == l) {
        return sgt[pq];
    }
    if(pq <= (l + r) / 2){
        return(get(pq, 2 * p, l, (l + r) / 2));
    }
    return get(pq, 2 * p + 1, (l + r) / 2 + 1, r);
}

void inv(int x, int y, int p = 1, int l = 0, int r = 1e5) { //propagating the inversions (logn)???
    push(p, l, r);
    if(x > r) {
        return;
    }
    if(x <= l) {
        lz[p] = y - lz[p];
        lzinv[p] *= -1;
        push(p, l, r);
        return;
    }
    inv(x, y, 2 * p, l, (l + r) / 2);
    inv(x, y, 2 * p + 1, (l + r) / 2 + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("reflection.in", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        for(int i = 0; i < maxn; i++) {
            sgt[i] = i;
            lz[i] = 0;
            lzinv[i] = 1;
        }
        int q;
        cin >> q;
        while(q--) {
            int x;
            cin >> x;
            int ans = get(x);
            cout << ans << "\n";
            inv(x, ans);
        }
    }
    return 0;
}