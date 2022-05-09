//Слава Україні, Героям слава 🇺🇦
//https://www.spoj.com/problems/SWERC14J/

#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const int N = 2e3 + 7;

ull h[N][N], p[2][N];
ull px = 3731, py = 2999;
int x, y, n, m;

void build(vector<string> &v, int a, int b) {
    p[0][0] = 1;
    p[1][0] = 1;
    for(int i = 1; i <= a; i++) {
        p[0][i] = p[0][i - 1] * px;
    }
    for(int i = 1; i <= b; i++) {
        p[1][i] = p[1][i - 1] * py;
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            h[i + 1][j + 1] = (v[i][j] == 'x' ? 2 : 1);
        }
    }
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            h[i][j] = h[i][j] + h[i - 1][j] * px + h[i][j - 1] * py  - h[i - 1][j - 1] * px * py;
        }
    }
}

ull fhash(int x1, int y1, int x2, int y2) {
    x1--; y1--;
    int dx = x2 - x1, dy = y2 - y1;
    return h[x2][y2] - h[x2][y1] * p[1][dy] - h[x1][y2] * p[0][dx] + h[x1][y1] * p[1][dy] * p[0][dx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> n >> m;
    vector<string> a(x), v(n);
    for(int i = 0; i < x; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(a, x, y);
    ull ref = fhash(1, 1, x, y);
    memset(h, 0, sizeof(h));
    build(v, n, m);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i + x - 1 <= n and j + y - 1 <= m) {
                if(fhash(i, j, i + x - 1, j + y - 1) == ref) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
