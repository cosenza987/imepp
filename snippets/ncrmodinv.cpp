long long modinv(long long a, long long m) {
    if(m == 0) {
        return 1;
    }
    if(m % 2 == 0) {
        long long k = modinv(a, m / 2);
        return ((k % mod) * (k % mod)) % mod;
    } else {
        return ((a % mod) * modinv(a, m - 1));
    }
}
 
long long ncr(long long n, long long r) {
    long long res = fact[n];
    res = (res * (modinv(fact[n - r], mod - 2) % mod)) % mod;
    res = (res * (modinv(fact[r], mod - 2) % mod)) % mod;
    return res;
}