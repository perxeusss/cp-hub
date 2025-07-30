#include<bits/stdc++.h>
using namespace std ;

#define int long long 
#define MOD 1000000007


vector<vector<int>> adj ;
vector<int> low, tin , vis ;
vector<pair<int, int>> bridges ;
int t = 0 ;

    void dfs(int node, int par ) {
        vis[node] = true ;
        low[node] = tin[node] = t++ ;

        for(int child : adj[node]) {
            if(child == par) continue ;

            if(vis[child]) {
                low[node] = min(low[node] , tin[child]) ;
            }
            else {
                dfs(child, node) ;
                low[node] = min(low[node], low[child]) ;

                if(tin[node] < low[child]) {
                    bridges.push_back({node, child}) ;
                }
            }
        }
    }


void run() {
    int n , m ; cin >> n >> m ;
    adj.assign(n + 1, {}) ;
    tin.assign(n + 1, 0) ;
    low.assign(n + 1, n + 1) ;
    vis.assign(n + 1, false ) ;
    
    for( int i = 0 ; i < m; ) {
        int u , v ; cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    
    dfs(1, -1) ;
    cerr << bridges.size() << "\n" ;
    for(auto p : bridges) cout << p.first << " " << p.second << "\n" ;
  
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int T = 1; cin >> T ;
    while (T--) run();
    return 0;
}


/* * Actually read the question.
   * Use newlines properl.
   * Handle cin >> t; correctly.
   * Use fixed << setprecision for floats.
   * Edge cases matter.
   * Modulo operations aren't optional .
   * Avoid endl unless necessary ('\n' is faster).
   * Watch for integer overflows .
*/
