template <bool EDGE> struct HLD {
    vector<vector<int>> g1;
    vector<vector<pair<int, int>>> g2;
    vector<int> pos, sz, w, par, h, sobe;
    vector<long long> v;
    seg_tree seg;
    int t;
    HLD(int n) {
        if(EDGE) {
            g2.resize(n + 3);
        } else {
            g1.resize(n + 3);
        }
        pos.resize(n + 3); sz.resize(n + 3); par.resize(n + 3);
        if(EDGE) {
            sobe.resize(n + 3);
        } else {
            w.resize(n + 3);
        }
        h.resize(n + 3); v.resize(n + 3);
    }
    void build_hld(int k, int p = -1, int f = 1) {
        v[pos[k] = t++] = (EDGE ? sobe : w)[k]; sz[k] = 1;
        for(int i = 0; i < (int)(EDGE ? g2[k].size() : g1[k].size()); i++) {
            if((EDGE and g2[k][i].first != p) or (!EDGE and g1[k][i] != p)) {
                if(EDGE) {
                    sobe[g2[k][i].first] = g2[k][i].second; par[g2[k][i].first] = k;
                    h[g2[k][i].first] = (g2[k][i] == g2[k][0] ? h[k] : g2[k][i].first);
                    build_hld(g2[k][i].first, k, f); sz[k] += sz[g2[k][i].first];
                    if(sz[g2[k][i].first] > sz[g2[k][0].first] or g2[k][0].first == p) {
                        swap(g2[k][i], g2[k][0]);
                    }
                } else {
                    par[g1[k][i]] = k;
                    h[g1[k][i]] = (g1[k][i] == g1[k][0] ? h[k] : g1[k][i]);
                    build_hld(g1[k][i], k, f);
                    sz[k] += sz[g1[k][i]];
                    if(sz[g1[k][i]] > sz[g1[k][0]] or g1[k][0] == p) {
                        swap(g1[k][i], g1[k][0]);
                    }
                }
            }
        }
        if(p * f == -1) {
            t = 1;
            build_hld(h[k] = k, -1, 0);
        }
    }
    void add(int a, int b) {
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    void add(int a, int b, int x) {
        g2[a].push_back({b, x});
        g2[b].push_back({a, x});
    }
    void build(int root = 1) {
        t = 1;
        build_hld(root);
        seg = seg_tree(v);
    }
    long long query_path(int a, int b) {
        if(EDGE and a == b) return 0;
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) return seg.query(pos[b] + EDGE, pos[a]);
        return seg.query(pos[h[a]], pos[a]) + query_path(par[h[a]], b);
    }
    void update_path(int a, int b, int x) {
        if(EDGE and a == b) return;
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) {
            seg.update(pos[b] + EDGE, pos[a], x);
            return;
        }
        seg.update(pos[h[a]], pos[a], x);
        update_path(par[h[a]], b, x);
    }
    long long query_subtree(int a) {
        if(EDGE and sz[a] == 1) return 0;
        return seg.query(pos[a] + EDGE, pos[a] + sz[a] - 1);
    }
    void update_subtree(int a, int x) {
        if(EDGE and sz[a] == 1) return;
        seg.update(pos[a] + EDGE, pos[a] + sz[a] - 1, x);
    }
};
