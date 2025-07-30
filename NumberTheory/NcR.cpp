#include<bits/stdc++.h>
using namespace std ;

#define int long long 
#define MOD 1000000007

const int N = 1e6; 

int fac[N + 1], ifac[N + 1];

int binpow(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }
    ifac[N] = binpow(fac[N], MOD - 2, MOD); 
    for (int i = N - 1; i >= 0; i--) {
        ifac[i] = (1LL * ifac[i + 1] * (i + 1)) % MOD;
    }
}

int nCr(int n , int r) {
    return ((( fac[n] * ifac[n - r]) % MOD) * ifac[r] % MOD) ;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 


}