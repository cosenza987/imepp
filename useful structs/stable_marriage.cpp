struct StableMarriage {
    int n, m;
    vector<vector<int>> a, b;
    StableMarriage(int n_, int m_, vector<vector<int>> a_, vector<vector<int>> b_) : n(n_), m(m_), a(a_), b(b_) {}
    vector<pair<int, int>> solve() {
        assert(n <= m);
        vector<int> p(n), mb(m, -1);
        vector<vector<int>> rank(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rank[i][b[i][j]] = j;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(i);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            int v = a[u][p[u]++];
            if(mb[v] == -1) {
                mb[v] = u;
            } else {
                int other_u = mb[v];
                if(rank[v][u] < rank[v][other_u]) {
                    mb[v] = u;
                    q.push(other_u);
                } else {
                    q.push(u);
                }
            }
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < m; i++) {
            if(mb[i] != -1) {
                ans.push_back({mb[i], i});
            }
        }
        return ans;
    }
};