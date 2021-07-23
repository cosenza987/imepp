#include <bits/stdc++.h>

using namespace std;

int cost[1004];
vector<pair<int, int>> area[1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x1[1004], y1[1004], x2[1004], y2[1004];
    int n, xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf >> n;
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    vector<bool> marca(n + 2, false);
    x1[n] = x2[n] = xi;
    y1[n] = y2[n] = yi;
    x1[n + 1] = x2[n + 1] = xf;
    y1[n + 1] = y2[n + 1] = yf;
    for(int i = 0; i < n + 1; i++) {
        for(int j = i + 1; j < n + 2; j++) {
            int dx = max(0, max(x1[i], x1[j]) - min(x2[i], x2[j]));
            int dy = max(0, max(y1[i], y1[j]) - min(y2[i], y2[j]));
            int c = dx + dy;
            area[i].push_back(make_pair(j, c));
            area[j].push_back(make_pair(i, c));
        }
    }
    q.push(make_pair(0, n));
    while(!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int c = p.first, a = p.second;
        if(!marca[a]) {
            cost[a] = c;
            marca[a] = true;
            for(auto e : area[a]) {
                int b = e.first, d = e.second;
                if(!marca[b]) {
                    q.push(make_pair(c + d, b));
                }
            }
        }
    }
    cout << cost[n + 1] << "\n";
    return 0;
}