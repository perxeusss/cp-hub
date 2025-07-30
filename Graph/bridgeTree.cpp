#include<bits/stdc++.h>
using namespace std;

struct BridgeTree {
    int n, m;
    vector<pair<int,int>> edges;
    vector<vector<pair<int,int>>> adj;

    vector<int> tin, low, bel;
    vector<bool> vis, isBridge;
    int timer = 0, compCnt = 0;

    vector<vector<int>> tree;

    BridgeTree(int _n = 0) { init(_n); }
    
    void init(int _n) {
        n = _n, m = 0;
        edges.clear();
        adj.assign(n + 1, {});
    }

    void addEdge(int u, int v) {
        edges.emplace_back(u, v);
        adj[u].emplace_back(v, m);
        adj[v].emplace_back(u, m);
        ++m;
    }

    void dfsBridge(int u, int pe) {
        vis[u] = true;
        tin[u] = low[u] = timer++;
        for (auto &pr : adj[u]) {
            int v = pr.first, id = pr.second;
            if (id == pe) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsBridge(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u])
                    isBridge[id] = true;
            }
        }
    }

    void dfsComponent(int u) {
        vis[u] = true;
        bel[u] = compCnt;
        for (auto &pr : adj[u]) {
            int v = pr.first, id = pr.second;
            if (vis[v] || isBridge[id]) continue;
            dfsComponent(v);
        }
    }

    void build() {
       
        tin.assign(n + 1, 0), low.assign(n + 1, 0);
        vis.assign(n + 1, false), isBridge.assign(m, false);
        timer = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i])  dfsBridge(i, -1);
               
        }

        fill(vis.begin(), vis.end(), false);
        bel.assign(n + 1, 0);
        compCnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ++compCnt;
                dfsComponent(i);
            }
        }
        tree.assign(compCnt + 1, {});
        for (int id = 0; id < m; ++id) {
            if (!isBridge[id]) continue;
            auto [u, v] = edges[id];
            int cu = bel[u], cv = bel[v];
            tree[cu].push_back(cv);
            tree[cv].push_back(cu);
        }
    }

    tuple<int,int,int> diameter() const {
        if (compCnt == 0) return {0, 0, 0};
        auto bfs = [&](int src) {
            vector<int> dist(compCnt + 1, -1);
            queue<int> q;
            dist[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : tree[u]) {
                    if (dist[v] < 0) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            int far = src;
            for (int i = 1; i <= compCnt; ++i) {
                if (dist[i] > dist[far]) far = i;
            }
            return make_pair(far, dist[far]);
        };
        auto [A, _] = bfs(1);
        auto [B, d] = bfs(A);
        return {A, B, d};
    }

    const vector<int>& belongs() const { return bel; }
    const vector<vector<int>>& getTree() const { return tree; }
    const vector<bool>& bridges() const { return isBridge; }
};

int main() {


}