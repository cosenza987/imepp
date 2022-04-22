const int N = 3e5 + 7;
 
pair<int, int> par[N];
int rnk[N];
bool bip[N];
 
pair<int, int> find(int a) {
    if(a != par[a].first) {
        int p = par[a].second;
        par[a] = find(par[a].first);
        par[a].second ^= p;
    }
    return par[a];
}
 
void unite(int a, int b) {
    pair<int, int> ap = find(a), bp = find(b);
    if(ap.first == bp.first) {
        if(ap.second == bp.second) {
            bip[ap.first] = false;
        }
    } else {
        if(rnk[ap.first] < rnk[bp.first]) {
            swap(ap, bp);
        }
        par[bp.first] = {ap.first, ap.second ^ bp.second ^ 1};
        bip[ap.first] &= bip[bp.first];
        if(rnk[ap.first] == rnk[bp.first]) {
            rnk[ap.first]++;
        }
    }
}
 
bool isb(int a) {
    return bip[find(a).first];
}
