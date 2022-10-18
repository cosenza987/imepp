struct LCA {
    //one indexed shit
    int n, l;
    vector<vector<int>> adj, up;
    vector<int> h;
    LCA (int n_) {
        n = n_;
        l = 31 - __builtin_clz(n);
        adj.resize(n + 1);
        up.assign(n + 1, vector<int>(l + 1));
        h.resize(n + 1);
    }
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int v = 1, int p = 0, int hh = 0) {
        up[v][0] = p;
        for(int i = 1; i <= l; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for(auto u : adj[v]) {
            if(u != p) {
                dfs(u, v, hh + 1);
            }
        }
        h[v] = hh;
    }
    int lca(int a, int b) {
        if(h[a] > h[b]) {
            swap(a, b);
        }
        int dff = h[b] - h[a], cnt = 0;
        while(dff) {
            if(dff & 1) {
                b = up[b][cnt];
            }
            cnt++;
            dff >>= 1;
        }
        if(a == b) {
            return a;
        }
        for(int i = l; i >= 0; i--) {
            if(up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }
    int raise(int node, int dist) {
        //if it returns 0, then it fucked up
        int cnt = 0;
        while(dist) {
            if(dist & 1) {
                node = up[node][cnt];
            }
            cnt++;
            dist >>= 1;
        }
        return node;
    }
    int dist(int a, int b) {
        int z = lca(a, b);
        return h[a] + h[b] - 2 * h[z];
    }
};

// now, what if the tree has weight??

struct LCA {
    //one indexed shit
    int n, l;
    vector<vector<int>> up;
    vector<vector<long long>> sum;
    vector<vector<pair<int, int>>> adj;
    vector<int> h;
    LCA (int n_) {
        n = n_;
        l = 31 - __builtin_clz(n);
        adj.resize(n + 1);
        sum.assign(n + 1, vector<long long>(l + 1));
        up.assign(n + 1, vector<int>(l + 1));
        h.resize(n + 1);
    }
    void add(int a, int b, int c) {
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    void dfs(int v = 1, int w = 0, int p = 0, int hh = 0) {
        up[v][0] = p;
        sum[v][0] = w;
        for(int i = 1; i <= l; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
            sum[v][i] = sum[up[v][i - 1]][i - 1] + sum[v][i - 1];
        }
        for(auto u : adj[v]) {
            if(u.first != p) {
                dfs(u.first, u.second, v, hh + 1);
            }
        }
        h[v] = hh;
    }
    /*int lca(int a, int b) {
        if(h[a] > h[b]) {
            swap(a, b);
        }
        int dff = h[b] - h[a], cnt = 0;
        while(dff) {
            if(dff & 1) {
                b = up[b][cnt];
            }
            cnt++;
            dff >>= 1;
        }
        if(a == b) {
            return a;
        }
        for(int i = l; i >= 0; i--) {
            if(up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    } */
    int raise(int node, int dist) {
        //if it returns 0, then it fucked up
        int cnt = 0;
        while(dist) {
            if(dist & 1) {
                node = up[node][cnt];
            }
            cnt++;
            dist >>= 1;
        }
        return node;
    }
    long long dist(int a, int b) {
        if(h[a] > h[b]) {
            swap(a, b);
        }
        int dff = h[b] - h[a], cnt = 0;
        long long ans = 0;
        while(dff) {
            if(dff & 1) {
                ans += sum[b][cnt];
                b = up[b][cnt];
            }
            cnt++;
            dff >>= 1;
        }
        if(a == b) {
            return ans;
        }
        for(int i = l; i >= 0; i--) {
            if(up[a][i] != up[b][i]) {
                ans += sum[a][i] + sum[b][i];
                a = up[a][i];
                b = up[b][i];
            }
        }
        return ans + sum[a][0] + sum[b][0];
    }
};
