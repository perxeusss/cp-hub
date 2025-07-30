#include<bits/stdc++.h>
using namespace std ;

#define int long long 
#define MOD 1000000007

   bool isPrime(int n) {
    if (n <= 1) return false;        
    if (n <= 3) return true;      
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true; 
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 


}