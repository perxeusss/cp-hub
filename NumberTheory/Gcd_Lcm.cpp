#include<bits/stdc++.h>
using namespace std ;

#define int long long 
#define MOD 1000000007

   int gcd(int a, int b) {
    return (!b) ? a : gcd(b, a % b);
  }
  int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b; 
  }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 


}