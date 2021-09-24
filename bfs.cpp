#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<string> v;
vector<vector<vector<int>>> l;
 
void bfs(int index, int x, int y, int dep = 0) {
    l[index][x][y] = dep;
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    vis[x][y] = true;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    while(!q.empty()) {
        auto k = q.front();
        q.pop();
        int d = k.first, i = k.second.first, j = k.second.second;
        if(i + 1 < n and !vis[i + 1][j] and v[i + 1][j] != '#') {
            vis[i + 1][j] = true;
            l[index][i + 1][j] = d + 1;
            q.push({d + 1, {i + 1, j}});
        }
        if(i - 1 >= 0 and !vis[i - 1][j] and v[i - 1][j] != '#') {
            vis[i - 1][j] = true;
            l[index][i - 1][j] = d + 1;
            q.push({d + 1, {i - 1, j}});
        }
        if(j + 1 < m and !vis[i][j + 1] and v[i][j + 1] != '#') {
            vis[i][j + 1] = true;
            l[index][i][j + 1] = d + 1;
            q.push({d + 1, {i, j + 1}});
        }
        if(j - 1 >= 0 and !vis[i][j - 1] and v[i][j - 1] != '#') {
            vis[i][j - 1] = true;
            l[index][i][j - 1] = d + 1;
            q.push(make_pair(d + 1, make_pair(i, j - 1)));
        }
    }
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v = vector<string>(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    l = vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(m, INT_MAX)));
    pair<int, int> a1, a2, b1, b2;
    cin >> a1.first >> a1.second;
    cin >> a2.first >> a2.second;
    cin >> b1.first >> b1.second;
    cin >> b2.first >> b2.second;
    bfs(0, a1.first, a1.second);
    bfs(1, a2.first, a2.second);
    bfs(2, b1.first, b1.second);
    bfs(3, b2.first, b2.second);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(l[0][i][j] == INT_MAX or l[1][i][j] == INT_MAX or l[2][i][j] == INT_MAX or l[3][i][j] == INT_MAX) {
                continue;
            }
            //cout << i << " " << j << "\n";
            ans = min(ans, l[0][i][j] + l[1][i][j] + l[2][i][j] + l[3][i][j]);
        }
    }
    if(ans == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
