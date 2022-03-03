bool TopologicalSort(int n) {
    vector <int> in(n + 1, 0);
    for (int i = 1; i <= n; ++i) for (int j : adj[i]) {
        in[j]++;
    }
    queue <int> q;
    for (int i = 1; i <= n; ++i) if (in[i] == 0) {
        q.push(i);
    }
    int ord = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        topo[v] = ord++;
        for (int u : adj[v]) {
            in[u]--;
            if (in[u] == 0) {
                q.push(u);
            }
        }
    }
    return ord == n;
}