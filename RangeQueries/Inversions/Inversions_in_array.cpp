#include <bits/stdc++.h>
using namespace std;


#define int long long
const int MOD = 1E9 + 7 ;

int merge(vector<int> &a, int l, int r, vector<int> &temp) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2, inv = 0; 
    inv += merge(a, l, m, temp);
    inv += merge(a, m + 1, r, temp);

    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv += (int)(m - i + 1);
        }
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int idx = l; idx <= r; ++idx) a[idx] = temp[idx];
    return inv;
}

int inversions(vector<int> a) {
    int n = (int)a.size();
    if (n <= 1) return 0;
    vector<int> temp(n);
    return merge(a, 0, n - 1, temp);
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
