#include<bits/stdc++.h>
using namespace std ;

#define int long long 
#define MOD 1000000007

// TC = n(log(log(n)))

vector<int> primes ; 
vector<bool> is_prime ;

void sieve(int n) {
   is_prime.assign(n + 1, true); 
    is_prime[0] = is_prime[1] = false;       

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i); 
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 


}