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