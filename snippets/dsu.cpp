struct DSU {
    int getSize(int x) { return -par[getPar(x)]; }
    int getPar(int x) {
        while(par[x] >= 0) {
            x = par[x];
        }
        return x;
    }
 
    bool makeUnion(int a, int b) {
        a = getPar(a), b = getPar(b);
        if(a == b) return false;
        if(par[a] > par[b]) std::swap(a, b);
        op.emplace_back(a, par[a]);
        op.emplace_back(b, par[b]);
        par[a] += par[b];
        par[b] = a;
        return true;
    }
 
    void init(int n) {
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = -1;
        }
        op.clear();
    }
 
    void rollBack() {
        par[op.back().first] = op.back().second;
        op.pop_back();
    }
 
    std::vector<int> par;
    std::vector<std::pair<int, int>> op;
};