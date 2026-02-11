#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1E9 + 7 ;

int minSwaps(vector<int>& a) {
    int n = a.size();
    vector<pair<int,int>> pairs(n);
    for (int i = 0; i < n; ++i) pairs[i] = {a[i], i};
    sort(pairs.begin(), pairs.end()); 
    vector<bool> vis(n, false);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i] || pairs[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = pairs[j].second;
            cycle_size++;
        }
        if (cycle_size > 0) res += cycle_size - 1;
    }
    return res;
}

void run() {


}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int tt = 1 ;
    cin >> tt ;
    while(tt--) run() ;
}

/*
Solutions are simple. 

Proofs are simple.
 
Implementations are simple
*/
