struct Trie {
    int tr[N][26];
    int idx;
    void insert(string s) {
        int p = 0;
        for (int i = 0; s[i]; i++) {
            int u = s[i] - 'a';
            if (!tr[p][u]) tr[p][u] = ++idx;
            p = tr[p][u];
        }
    }
    bool query(string s) {
        int p = 0;
        for (int i = 0; s[i]; i++) {
            int u = s[i] - 'a';
            if (!tr[p][u]) return false;
            p = tr[p][u];
        }
        return true;
    }
};
