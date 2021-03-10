#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
 
using namespace std;

bool prime(int k) {
    if (k <= 1) {
        return false;
    }
    if(k <= 3) {
        return true;
    }
    if (k%2 == 0 || k%3 == 0) {
        return false;
    }
    for(int i = 5; i*i<=k; i = i + 6) {
        if(k % i == 0 || k % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n,i,j,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        if(prime(x) && x!=y) {
            printf("%d\n",x);
        }
        else if(y >= x) {
            printf("1\n");
        } else {
            for(j=y;j>0;j--) {
                if(x%j == 0) {
                    printf("%d\n", x/j);
                    break;
                }
            }
        }
    }
    return 0;
}
