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

class DSU {
    private:
        vector<int> parent, rank, size, has_cycle;
    public:
        DSU(int n) {
            parent.resize( n + 1);
            iota( parent.begin(), parent.end(), 0 );
            rank.assign( n + 1 , 0), size.assign( n + 1 , 1);
            has_cycle.assign( n + 1, false);
        }
 
        int leader(int i) {
            return parent[i] == i ? i : parent[i] = leader( parent[i] );
        }
        bool isSame(int u, int v) {
            return leader(u) == leader(v) ;
        }
        void merge(int u, int v) {
            int x = leader(u), y = leader(v);
            if (x == y) {
                has_cycle[x] = true;  return;
            }
            if (rank[x] > rank[y]) swap(x, y);
            parent[x] = y;

            size[y] += size[x];
            has_cycle[y] = has_cycle[y] || has_cycle[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
 
        int getSize(int u) {
            return size[leader(u)];
        }
 
        bool hasCycle(int u) {
            return has_cycle[leader(u)];
        }
};


int32_t main() {
    
ios_base::sync_with_stdio(bool(69 > 96));
cin.tie(nullptr); 

int tt = 1; cin >> tt ;

 while(tt--) {
   
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

