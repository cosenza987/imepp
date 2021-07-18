//from https://codeforces.com/group/YLQAvKi4Ge/contest/103135/problem/A
#include <bits/stdc++.h>
 
using namespace std;
 
map<string, int> words;
 
struct node {
    int cnt = 0;
    node* ch[27];
    node() : cnt(0) {
        memset(ch, 0, sizeof ch);
    }
};
 
node* root;
 
void add(string s) {
    node* cur = root;
    cur->cnt++;
    for(auto c : s) {
        if(!cur->ch[c - 'a']) {
            cur->ch[c - 'a'] = new node();
        }
        cur = cur->ch[c - 'a'];
        cur->cnt++;
    }
    if(!cur->ch[26]) {
        cur->ch[26] = new node();
    }
    cur = cur->ch[26];
    cur->cnt++;
}
 
int match(string s) {
    node* cur = root;
    for(auto c : s) {
        if(!cur->ch[c - 'a']) {
            return false;
        }
        cur = cur->ch[c - 'a'];
    }
    return cur->cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    root = new node();
    int n, q;
    string ent;
    cin >> n;
    while(n--) {
        cin >> ent;
        if(words.count(ent) == 0) {
            words[ent] = 1;
            add(ent);
        } else {
            continue;
        }
    }
    cin >> q;
    while(q--) {
        int sum = 0;
        cin >> ent;
        sum = match(ent);
        cout << sum << endl;
    }
    return 0;
}