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

const int MAX_N = 2e5 + 5;  
const int MAX_L = 20;       

vector<int> adj[MAX_N];
int dp[MAX_N][MAX_L], level[MAX_N];

void dfs(int node, int par) {
    dp[node][0] = par;  
    for (int i = 1; i < MAX_L; i++) {
        dp[node][i] = (dp[node][i - 1] != -1) ? dp[dp[node][i - 1]][i - 1] : -1 ;
    }
    for (int child : adj[node]) {
        if (child != par) {
            level[child] = level[node] + 1;
            dfs(child, node);
        }
    }
}

int getKthParent(int node, int k) {
    int pos = 0;
    while (k > 0) {
        if (k & 1) node = dp[node][pos];  
        if (node == -1) break;  
        k >>= 1,  pos++;
    }
    return node;
}

int LCA(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    u = getKthParent(u, level[u] - level[v]);  
    
    if (u == v) return u;

    for (int i = MAX_L - 1; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0]; 
}


// Actually Read the question — guessing doesn't count!
// Use newlines properly (or enjoy failing test cases).
// Handle cin >> t; correctly (or let your code crash).
// Use fixed << setprecision for floats (unless you like physics experiments).
// Edge cases matter — "it works on samples" is a lie.
// Modulo operations aren't optional (TLE & WA await).
// Avoid endl unless necessary ('\n' is faster).
// Watch for integer overflows (10⁹ + 10⁹ in an int? Sure...).

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int tt = 1; cin >> tt ;

    while(tt--) {
        
    }
    return 0; 
}
