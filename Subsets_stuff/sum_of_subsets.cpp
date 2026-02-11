#include <bits/stdc++.h>
using namespace std;

#define int int

// Returns the index of the least significant set bit (0-based)
int lsb_pos(int x) {
    return x ? __builtin_ctzll(x) : 64;
}

// Compute all subset sums of a subarray [start, start+len-1] of array 'arr'
vector<int> subset_sums(const vector<int> &arr, int start, int len, int mod = -1) {
    int tot = 1 << len;                // total number of subsets
    vector<int> sum(tot);
    sum[0] = 0;                        // sum of empty subset
    for (int mask = 1; mask < tot; mask++) {
        int lsb = mask & -mask;            // least significant bit (value)
        int idx = lsb_pos(lsb);                  // index of that bit (0-based)
        sum[mask] = sum[mask ^ lsb] + arr[start + idx]; // add element
        if (mod != -1) sum[mask] %= mod;        // optional modulo
    }
    return sum;
}

/*
tc = o(2 ^ len) 
and sum[10101] = sum[10001] + sum[00100] 
*/

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
