struct seg_tree {
    //modify accordingly
    int n;
    vector<long long> v, lz, st;
    void build() {
        build(1, 1, n);
    }
    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = v[l];
            return;
        }
        build(2 * p, l, (l + r) >> 1);
        build(2 * p + 1, ((l + r) >> 1) + 1, r);
        st[p] = st[2 * p] + st[2 * p + 1];
    }
    seg_tree(int n_) {
        n = n_;
        lz.resize(4 * n);
        st.resize(4 * n);
        v.resize(n + 1);
        build();
    }
    seg_tree(vector<long long>& v_) {
        v = v_;
        n = v.size();
        n--;
        lz.resize(4 * n);
        st.resize(4 * n);
        build();
    }
    void push(int p, int l, int r) {
        if (lz[p]) {
            st[p] += (r - l + 1) * lz[p];
            if (l != r) {
                lz[2 * p] += lz[p];
                lz[2 * p + 1] += lz[p];
            }
            lz[p] = 0;
        }
    }
    long long query(int i, int j) {
        return query(i, j, 1, 1, n);
    }
    long long query(int i, int j, int p, int l, int r) {
        push(p, l, r);
        if (l > j or r < i) {
            return 0;
        }
        if (l >= i and j >= r) {
            return st[p];
        }
        return query(i, j, 2 * p, l, (l + r) >> 1) + query(i, j, 2 * p + 1, ((l + r) >> 1) + 1, r);
    }
    void update(int i, int j, int v) {
        update(i, j, v, 1, 1, n);
    }
    void update(int i, int j, int v, int p, int l, int r) {
        push(p, l, r);
        if (l > j or r < i) {
            return;
        }
        if (l >= i and j >= r) {
            lz[p] += v;
            push(p, l, r);
            return;
        }
        update(i, j, v, 2 * p, l, (l + r) >> 1);
        update(i, j, v, 2 * p + 1, ((l + r) >> 1) + 1, r);
        st[p] = st[2 * p] + st[2 * p + 1];
    }
};
