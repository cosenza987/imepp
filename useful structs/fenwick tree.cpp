template <class T> struct FenwickTree {
    vector<T> fwt;
    int n;
    FenwickTree(int n_) {
        n = n_;
        fwt.assign(n, 0);
    }
    FenwickTree(vector<T>& a) {
        n = (int)a.size();
        fwt.assign(n, 0);
        for (int i = 0; i < (int)a.size(); i++) {
            add(i, a[i]);
        }
    }
    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += fwt[r];
        }
    return ret;
    }
    T query(int l, int r) {
    if (l > r) {
        return 0;
    }
    return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1)) {
            fwt[idx] += delta;
        }
    }
};