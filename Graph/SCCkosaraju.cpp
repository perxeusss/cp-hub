#include <bits/stdc++.h>
using namespace std;


struct scc {
    int n;
    vector<vector<int>> adj, adjT;
    vector<bool> vis;
    vector<int> order, bel;
    int cnt;
    
    scc() {}
    scc(int _n) { init(_n); }
    
    void init(int _n) {
        n = _n;
        adj.assign(n + 1, {} ),  adjT.assign(n+1, {});
        vis.assign(n + 1, false ),  bel.assign(n+1, -1);
        order.clear() ,cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    
    void preCal(int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) preCal(v);
        }
        order.push_back(u);
    }
    
    void dfs(int u) {
        bel[u] = cnt;
        for (int v : adjT[u]) {
            if (bel[v] == -1) dfs(v);
        }
    }
    
    vector<int> work() {
        fill(vis.begin(), vis.end(), false);
        order.clear();
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) preCal(i);
        }
        fill(bel.begin(), bel.end(), -1);
        cnt = 0;
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int u = order[i];
            if (bel[u] == -1) {
                dfs(u);
                cnt++;
            }
        }
        return bel;
    }
};



void run() {
  
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
