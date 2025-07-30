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

vector<int> dijkstra(int src, int n, const vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int, int> top = pq.top(); pq.pop();
        int cur_dist = top.first;
        int u = top.second;

        if (cur_dist > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

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

