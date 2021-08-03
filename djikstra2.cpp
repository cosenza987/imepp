//see https://www.spoj.com/problems/HIGHWAYS/
#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, std::greater<pair<long long, long long>>> q;

const long long lmax = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<pair<long long, long long>> adj[n + 7];
        vector<long long> cost(n + 7, lmax);
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        q.push({0, x});
        cost[x] = 0;
        while(!q.empty()) {
            auto p = q.top();
            q.pop();
            long long c = p.first, a = p.second;
            if(cost[a] < c) {
                continue;
            }
            for(auto k : adj[a]) {
                int b = k.first, d = k.second;
                if(cost[b] > d + c) {
                    cost[b] = d + c;
                    q.push({c + d, b});
                }
            }
        }
        if(cost[y] == lmax) {
            cout << "NONE\n";
        } else {
            cout << cost[y] << "\n";
        }
    }
    return 0;
}
