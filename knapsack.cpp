#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;
long long w[2002], v[2002];
long long a[2002][2002];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ks(int W, int w[], int v[], int n) {
    int i, wt;
    int K[n + 1][W + 1];
    for(i = 0; i <= n; i++) {
        for(wt = 0; wt <= W; wt++) {
            if(i==0 || wt == 0) {
                K[i][wt] = 0;
            } else if(w[i - 1] <= wt) {
                K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
            } else {
                K[i][wt] = K[i - 1][wt];
            }
        }
    }
    return K[n][W];
}

int main() {
    int n, W, i, res;
    scanf("%d %d ", &W, &n);
    int v[n], w[n];
    for(i = 0; i < n; i++) {
        scanf("%d %d ", &w[i], &v[i]);
    }
    res = ks(W, w, v, n);
    printf("%d\n", res);
    return 0;
}