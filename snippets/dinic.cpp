class Dinic {
    public:
        vector<int> nxt, head, work, to, d, cap;
        int n, e, edCnt;
        bool uu;
        Dinic(int n, vector<pair<pair<int, int>, int>> edges, bool undir = false):n(n) {
            e = (int)edges.size() * (undir ? 2 : 1) + 7;
            head = vector<int>(n + 1, -1);
            nxt = to = cap = vector<int>(e);
            edCnt = 0;
            uu = undir;
            for(auto e : edges) {
                addEdge(e.first.first, e.first.second, e.second);
                if(undir) {
                    addEdge(e.first.second, e.first.first, e.second);
                }
            }
        }
        void addEdge(int u, int v, int cost) {
            to[edCnt] = v;
            nxt[edCnt] = head[u];
            cap[edCnt] = cost;
            head[u] = edCnt++;
        }
        bool bfs(int &src, int &sink) {
            queue<int> q;
            d = vector<int>(n + 1, -1);
            d[src] = 0;
            q.push(src);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for(int k = head[cur], v; ~k and (v = to[k], 1); k = nxt[k]) {
                    if(d[v] != -1 or !cap[k]) {
                        continue;
                    }
                    d[v] = d[cur] + 1;
                    q.push(v);
                }
            }
            return d[sink] != -1;
        }
        int dfs(int u, int cur_flow, int &sink) {
            if(u == sink) {
                return cur_flow;
            }
            for(int &k = work[u], v; ~k and (v = to[k], 1); k = nxt[k]) {
                if(d[u] + 1 != d[v] or !cap[k]) {
                    continue;
                }
                int fl = dfs(v, min(cur_flow, cap[k]), sink);
                if(!fl) {
                    continue;
                }
                cap[k] -= fl;
                if(uu) {
                    cap[k ^ 1] += fl;
                }
                return fl;
            }
            return 0;
        }
        long long maxFlow(int src, int sink) {
            long long max_flow = 0;
            while(bfs(src, sink)) {
                work = head;
                while(int flow = dfs(src, INT_MAX, sink)) {
                    max_flow += flow;
                }
            }
            return max_flow;
        }
};