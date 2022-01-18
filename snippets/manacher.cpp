bool mc(string s) {
    string t = "$#";
    for(int i = 0; i < s.size(); i++) {
        t += s[i];
        t += '#';
    }
    vector<int> p(t.size());
    int mx = 0, id = 0;
    for(int i = 1; i < t.size(); i++) {
        p[i] = (mx > i ? min(p[2 * id - i], mx - i) : 1);
        while(t[i + p[i]] == t[i - p[i]]) {
            p[i]++;
        }
        if(mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
    }
    for(int i = 1; i < t.size(); i++) {
        if(((p[i] - 1) % 2) == (m % 2) and (p[i] - 1) >= m)  {
            return true;
        }
    }
    return false;
}