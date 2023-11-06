// this question wanted the sum from i = 1 to n of the sum from j = 1 to n of (i & j)

//Слава Україні, Героям слава

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long binexp(long long a, long long n) {
    long long res = 1;
    while(n) {
        if(n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        for(int i = 0; i < 62; i++) {
            if(1ll << i > n) break;
            long long amount = n / (1ll << i + 1) * (1ll << i);
            amount += max(0ll, (n % (1ll << (i + 1)) - (1ll << i) + 1));
            amount %= mod;
            amount = (amount * amount % mod);
            amount = (amount * ((1ll << i) % mod)) % mod;
            ans = (ans + amount) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
