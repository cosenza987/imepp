struct SuffixArray {
    vector<int> sa, lcp_v;
    vector<vector<int>> cs;
    string ss;
    int n;
 
    int add(int a, int b) { return a + b >= n ? a + b - n : a + b; }
    int sub(int a, int b) { return a - b < 0 ? a - b + n : a - b; }
 
    SuffixArray(string& s, bool store_steps = false, bool build_lcp = true) {
        s += ' ';
        n = (int)s.size();
        sa = sort_shifts(s, store_steps);
        if (build_lcp) {
            lcp_v = build_lcp_v(s);
            lcp_v.erase(lcp_v.begin());
        }
        sa.erase(sa.begin());
        ss = s;
        s.pop_back();
    }
 
    vector<int> sort_shifts(string& s, bool store_steps) {
        const int ALPHA_SIZE = 256;
        vector<int> p(n), c(n), cnt(ALPHA_SIZE);
        for (char ch : s) cnt[(int)ch]++;
        for (int i = 1; i < ALPHA_SIZE; i++) cnt[i] += cnt[i - 1];
 
        for (int i = 0; i < n; i++) {
            cnt[s[i]]--;
            p[cnt[s[i]]] = i;
        }
 
        for (int i = 1; i < n; i++)
            c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
 
        if (store_steps) cs.push_back(c);
 
        vector<int> cn(n), pn(n);
 
        for (int k = 0; (1 << k) < n; k++) {
            int nclass = c[p[n - 1]] + 1;
            cnt.assign(nclass, 0);
 
            for (int i = 0; i < n; i++) {
                pn[i] = sub(p[i], (1 << k));
                cnt[c[i]]++;
            }
 
            for (int i = 1; i < nclass; i++)
                cnt[i] += cnt[i - 1];
 
            for (int i = n - 1; i >= 0; i--) {
                cnt[c[pn[i]]]--;
                p[cnt[c[pn[i]]]] = pn[i];
            }
 
            cn[p[0]] = 0;
            for (int i = 1; i < n; i++) {
                pair<int, int> a = { c[p[i]], c[add(p[i], (1 << k))] };
                pair<int, int> b = { c[p[i - 1]], c[add(p[i - 1], (1 << k))] };
                cn[p[i]] = cn[p[i - 1]] + (a != b);
            }
 
            swap(c, cn);
            if (store_steps) cs.push_back(c);
 
        }
 
        return p;
    }
 
    vector<int> build_lcp_v(string& s) {
        vector<int> ans(n - 1), rank(n);
        for (int i = 0; i < n; i++) rank[sa[i]] = i;
 
        for (int i = 0, k = 0; i < n - 1; i++) {
            if (rank[i] == n - 1) continue;
            int j = sa[rank[i] + 1];
            while (s[i + k] == s[j + k]) k++;
            ans[rank[i]] = k;
            if (k) k--;
        }
 
        return ans;
    }
 
    int lcp(int i, int j) {
        if (i == j) return n - i - 1;
        int ans = 0;
        for (int k = (int)cs.size() - 1; k >= 0; k--) {
            if (cs[k][i] == cs[k][j]) {
                int val = (1 << k);
                ans += val, i += val, j += val;
            }
        }
        return ans;
    }
 
    long long diff_substr() {
        int sz = n - 1;
        long long ans = sz - sa[0];
        for (int i = 1; i < (int)sa.size(); i++) ans += sz - sa[i] - lcp_v[i - 1];
        return ans;
    }
 
    long long diff_substr_sz_sum() {
        int sz = n - 1;
        auto sum = [](int l, int r) { return (1ll * (l + r) * (r - l + 1)) / 2; };
        long long ans = sum(1, sz - sa[0]);
        for (int i = 1; i < (int)sa.size(); i++) ans += sum(lcp_v[i - 1] + 1, sz - sa[i]);
        return ans;
    }
 
};
