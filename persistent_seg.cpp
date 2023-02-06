const int N = 2e5 + 7, LOG = 18;
const int NN = N * LOG + 3 * N;

namespace pseg {
    pair<int, long long> seg[NN];
    int roots[N], L[NN], R[NN], cnt = 1;
    void build(int p = 1, int l = 1, int r = N) {
        if(l == r) {
            seg[p] = {0, 0};
            return;
        }
        int mid = (l + r) >> 1;
        L[p] = cnt++;
        R[p] = cnt++;
        build(L[p], l, mid);
        build(R[p], mid + 1, r);
    }
    void insert(int x, int val, int pcur = -1, int p = -1, int l = 1, int r = N) {
        if(pcur == -1) {
            pcur = roots[x] = cnt++;
        }
        if(p == -1) {
            p = roots[x - 1];
        }
        seg[pcur].first = seg[p].first + 1;
        seg[pcur].second = seg[p].second + val;
        if(l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        if(val > mid) {
            L[pcur] = L[p];
            R[pcur] = cnt++;
            insert(x, val, R[pcur], R[p], mid + 1, r);
        } else {
            R[pcur] = R[p];
            L[pcur] = cnt++;
            insert(x, val, L[pcur], L[p], l, mid);
        }
    }
    pair<int, long long> find(int p1, int p2, int i, int j, int l = 1, int r = N) {
        if(i > r or j < l) {
            return {0, 0};
        }
        if(i <= l and r <= j) {
            return {seg[p1].first - seg[p2].first, seg[p1].second - seg[p2].second};
        }
        int mid = (l + r) >> 1;
        auto a = find(L[p1], L[p2], i, j, l, mid);
        auto b = find(R[p1], R[p2], i, j, mid + 1, r);
        return {a.first + b.first, a.second + b.second};
    }
};
