const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
 
struct segTree {
    struct Node {
        int sum, lazy;
        Node() : sum(0), lazy(-1) {}
        Node(int _sum) {
            sum = _sum;
            lazy = -1;
        }
        Node operator + (const Node &o) const {
            if(o.sum == INF) return *this;
            if(sum == INF) return o;
            return Node(sum + o.sum);
        }
    };
    Node node[4 * N];
 
    segTree(){
        for(int i = 0; i < 4 * N; i++)
            node[i] = Node(0);
    }
 
    void push(int no, int ini, int fim) {
        if(node[no].lazy != -1) {
            node[no].sum = node[no].lazy;
            if(ini != fim) {
                node[2 * no].lazy = node[no].lazy;
                node[2 * no + 1].lazy = node[no].lazy;
            }
            node[no].lazy = -1;
        }
    }
 
    void update(int no, int ini, int fim, int l, int r, int x) {
        push(no, ini, fim);
        if(l <= ini and fim <= r) {
            node[no].lazy = x;
            push(no, ini, fim);
            return;
        }
        if(fim < l or r < ini) return;
        int meio = (ini + fim) / 2;
        update(2 * no, ini, meio, l, r, x);
        update(2 * no + 1, meio + 1, fim, l, r, x);
        node[no] = node[2 * no] + node[2 * no + 1];
    }
 
    void update(int l, int r, int x) {
        update(1, 1, N - 1, l, r, x);
    }
 
    Node query(int no, int ini, int fim, int l, int r) {
        push(no, ini, fim);
        if(fim < l or r < ini) return Node();
        if(l <= ini and fim <= r) return node[no];
        int meio = (ini + fim) / 2;
        return query(2 * no, ini, meio, l, r) + query(2 * no + 1, meio + 1, fim, l, r);
    }
 
    Node query(int l, int r) {
        return query(1, 1, N - 1, l, r);
    }
};
 
struct HLD {
    int cur;
    int head[N], sz[N], pos[N], pai[N];
    vector<int> adj[N];
    segTree ST;
 
    HLD () {}
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    void dfs(int x, int p = -1) {
        sz[x] = 1;
        for(auto &u : adj[x]) {
            if(u == p) continue;
            pai[u] = x;
            dfs(u, x);
            sz[x] += sz[u];
            if(adj[x][0] == p or sz[adj[x][0]] < sz[u]) swap(u, adj[x][0]);
        }
    }
 
    void dfs_hld(int x, int p = -1) {
        pos[x] = cur;
        cur++;
        for(auto u : adj[x]) {
            if(u == p) continue;
            head[u] = (u == adj[x][0] ? head[x] : u);
            dfs_hld(u, x);
        }
    }
 
    void build_hld() {
        cur = 1;
        head[1] = 1;
        dfs(1);
        dfs_hld(1);
    }
 
    void update_ancestors(int a, int v) {
        ST.update(pos[head[a]], pos[a], v);
        if(head[a] != 1) update_ancestors(pai[head[a]], v);
    }
 
    void update_subtree(int i, int v) {
        ST.update(pos[i], pos[i] + sz[i] - 1, v);
    }
 
    int query_node(int a) {
        return ST.query(pos[a], pos[a]).sum;
    }
};
