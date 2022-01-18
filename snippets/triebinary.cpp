struct trie {
    struct node {
        node* nxt[2];
        int cnt;
        node() {
            nxt[0] = nxt[1] = NULL;
            cnt = 0;
        }
    };
    node* head;
    trie() {
        head = new node();
    }
    void add(int a) {
        node* cur = head;
        for(int i = 31; i >= 0; i--) {
            int bit = (a >> i) & 1;
            if(cur->nxt[bit] == NULL) {
                cur->nxt[bit] = new node();
            }
            cur = cur->nxt[bit];
            cur->cnt++;
        }
    }
    int query(int x, int k) {
        node* cur = head;
        int ans = 0;
        bool pode = false;
        for(int i = 31; i >= 0; i--) {
            int b1 = (x >> i) & 1, b2 = (k >> i) & 1;
            if(!b2) {
                if(cur->nxt[b1 ^ 1]) {
                    ans += cur->nxt[b1 ^ 1]->cnt;
                }
            }
            if(cur->nxt[b1 ^ b2]) {
                cur = cur->nxt[b1 ^ b2];
            } else {
                pode = true;
                break;
            }
        }
        if(!pode) {
            ans += cur->cnt;
        }
        return ans;
    }
};