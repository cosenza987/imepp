vector<vector<long long>> ncr(5007, vector<long long>(5007));
    for(int i = 0; i < 5007; i++) {
        ncr[i][0] = ncr[i][i] = 1;
        for(int j = 1; j < i; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
        }
    }