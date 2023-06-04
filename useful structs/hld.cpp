// for vertices

struct HLD {
    vector<vector<int>> adj;
    vector<int> pos, sz, w, par, h, v;
    seg_tree seg;
    int t;
    HLD(int n) {
        adj.resize(n + 1);
        pos.resize(n + 1); sz.resize(n + 1); w.resize(n + 1); par.resize(n + 1);
        h.resize(n + 1); v.resize(n + 1);
    }
    void build_hld(int k, int p = -1, int f = 1) {
        v[pos[k] = t++] = w[k]; sz[k] = 1;
        for(auto &i : adj[k]) {
            if(i != p) {
                par[i] = k;
                h[i] = (i == adj[k][0] ? h[k] : i);
                build_hld(i, k, f);
                sz[k] += sz[i];
                if(sz[i] > sz[adj[k][0]] or adj[k][0] == p) {
                    swap(i, adj[k][0]);
                }
            }
        }
        if(p * f == -1) {
            t = 1;
            build_hld(h[k] = k, -1, 0);
        }
    }
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void build(int root = 1) {
        t = 1;
        build_hld(root);
        seg = seg_tree(v);
    }
    long long query_path(int a, int b) {
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) return seg.query(pos[b], pos[a]);
        return seg.query(pos[h[a]], pos[a]) + query_path(par[h[a]], b);
    }
    void update_path(int a, int b, int x) {
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) {
            seg.update(pos[b], pos[a], x);
            return;
        }
        seg.update(pos[h[a]], pos[a], x);
        update_path(par[h[a]], b, x);
    }
    long long query_subtree(int a) {
        return seg.query(pos[a], pos[a] + sz[a] - 1);
    }
    void update_subtree(int a, int x) {
        seg.update(pos[a], pos[a] + sz[a] - 1, x);
    }
};
