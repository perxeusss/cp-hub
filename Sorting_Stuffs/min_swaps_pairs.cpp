#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1E9 + 7 ;


int minSwapsPairs(vector<pair<int,int>>& arr) {
    int n = arr.size();
    vector<pair<pair<int,int>, int>> vp(n) ;
    for (int i = 0; i < n; ++i) vp.emplace_back(arr[i], i);
    stable_sort(vp.begin(), vp.end(), [](const auto &a, const auto &b){
        return a.first < b.first; 
    });
    vector<char> vis(n, 0);
    int swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i] || vp[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
            j = vp[j].second; 
            ++cycle_size;
        }
        if (cycle_size > 0) swaps += cycle_size - 1;
    }
    return swaps;
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
