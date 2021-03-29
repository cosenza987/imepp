#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

#define mod 1000000007
 
using namespace std;

int dp[1010][1010], n, k;

int calc(int x, int y) {
    if(y <= 0) {
        return 0;
    }
    if(x <= 0) {
        return 1;
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    return dp[x][y] = (calc(x - 1, y) + calc(n - x, y - 1)) % mod;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &k);
        int res = calc(n, k);
        printf("%d\n", res);
    }
    return 0;
}
