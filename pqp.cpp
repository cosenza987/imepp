#include <bits/stdc++.h>

using namespace std;
    
vector<string> v(8);
int ans = 0, row[8];

bool check(int r, int c) {
    if(v[r][c] == '*') {
        return false;
    }
    for(int i = 0; i < c; i++) {
        if(row[i] == r) {
            return false;
        }
        if(row[i] + i == r + c) {
            return false;
        }
        if(row[i] - i == r - c) {
            return false;
        }
    }
    return true;
}

void bt(int c) {
    if(c == 8) {
        ans++;
        return;
    }
    for(int i = 0; i < 8; i++) {
        if(check(i, c)) {
            row[c] = i;
            bt(c + 1);
            row[c] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 8; i++) {
        cin >> v[i];
    }
    bt(0);
    cout << ans << "\n";
    return 0;
}