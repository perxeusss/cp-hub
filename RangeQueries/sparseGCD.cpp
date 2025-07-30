#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int gcd(int a, int b) {
    return (!b) ? a : gcd(b, a % b);
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &it : a) cin >> it;

    int LOG = (int)log2(n) + 1;  
    vector<vector<int>> sparse(n, vector<int>(LOG));

    
    for (int i = 0; i < n; i++) {
        sparse[i][0] = a[i];
    }

    for (int e = 1; e < LOG; e++) {
        for (int i = 0; i + (1 << (e - 1)) < n; i++) {  
            sparse[i][e] = gcd(sparse[i][e - 1], sparse[i + (1 << (e - 1))][e - 1]);
        }
    }

    auto query = [&](int l, int r) {
        int len = r - l + 1;
        int k = log2(len); 
        int result = gcd(sparse[l][k], sparse[r - (1 << k) + 1][k]);
        return result;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;  
        cout << query(l, r) << "\n";
    }

    return 0;
}
