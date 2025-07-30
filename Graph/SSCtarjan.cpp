#include<bits/stdc++.h>
using namespace std;


struct SCC {
    int n, cur, cnt ;     
              
    vector<vector<int>> adj;
    vector<int> stk, dfn, low, bel;
 
    SCC() {}
    explicit SCC(int _n) {
        init(_n);
    }
 
    void init(int _n) {
        n = _n;
        adj.assign(n + 1, {}), dfn.assign(n + 1, -1);
        low.assign(n + 1, 0), bel.assign(n + 1, 0);
        stk.clear();
        cur = cnt = 0 ;
    }
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
 
    void dfs(int x) {
        dfn[x] = low[x] = ++cur;
        stk.push_back(x);
 
        for (int y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = min(low[x], low[y]);
            } else if (bel[y] == 0) {
                low[x] = min(low[x], dfn[y]);
            }
        }
 
        if (dfn[x] == low[x]) {
            ++cnt;
            int y;
            do {
                y = stk.back();
                stk.pop_back();
                bel[y] = cnt;
            } while (y != x);
        }
    }
    vector<int> work() {
        for (int i = 1; i <= n; ++i) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

int main() {


}