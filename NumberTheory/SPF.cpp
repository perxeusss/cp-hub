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

const int N = 1e4 + 7 ;

vector<int> spf ;
void SPF(int n) {
    spf.assign(n + 1, 0) ;
        iota(spf.begin() , spf.end(), 0) ;
        
        for( int i = 2; i * i < n ; i++) {
            if(spf[i] != i) continue ;
            
            for( int j = i * i ; j < n ; j += i ) {
                if(spf[j] == j) spf[j] = i ;
            }
        }
    }
//   int spf(int x) {
//     if (x == 1) return 1;
//     if (x % 2 == 0) return 2;
//     for (int d = 3; d * 1LL * d <= x; d += 2) {
//         if (x % d == 0) return d;
//     }
//     return x;
// }

int32_t main() {
    
ios_base::sync_with_stdio(bool(69 > 96));
cin.tie(nullptr); 

int tt = 1; cin >> tt ;

 while(tt--) {
        
   }
    return 0; 
}
