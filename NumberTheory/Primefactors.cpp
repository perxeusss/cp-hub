 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 
 using namespace std;
 using namespace __gnu_pbds;
 
 #define int long long int
 #define MOD (1000000007)
 #define INF 1000000000000000000LL 
 #define PI 3.141592653589793238462

vector<int> pfs(int n) {
    
    vector<int> primes ;
    bool found = false ;

    while (n % 2 == 0) {
        found = true ;
        n /= 2;
    }
    if(found) primes.push_back(2) ;

    for (int i = 3; i * i <= n; i += 2) {
        found = false ;
        while (n % i == 0) {
            found = true ;
            n /= i;
        }
        if(found) primes.push_back(i) ;
    }

    if (n > 2) primes.push_back(n) ;

    return primes ;
}

 int32_t main() {
     
 ios_base::sync_with_stdio(bool(69 > 96));
 cin.tie(nullptr); 
 
 int tt = 1; cin >> tt ;
 
  while(tt--) {

    int n ; cin >> n ;

    vector<int> primes = pfs(120) ;
    for(auto it : primes ) cout << it << " " ;
    cout << "\n" ;

    }
     return 0; 
 }
 
 /* * Actually Read the question — guessing doesn't count!
    * Use newlines properly (or enjoy failing test cases).
    * Handle cin >> t; correctly (or let your code crash).
    * Use fixed << setprecision for floats (unless you like physics experiments).
    * Edge cases matter — "it works on samples" is a lie.
    * Modulo operations aren't optional (TLE & WA await).
    * Avoid endl unless necessary ('\n' is faster).
    * Watch for integer overflows (10⁹ + 10⁹ in an int? Sure...).
 */
 
 