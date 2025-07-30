#include<bits/stdc++.h>
using namespace std;

struct Hash {
    static constexpr int MOD = 1e9 + 7, BASE1 = 5689, BASE2 = 8861;
    vector<pair<int, int>> hash, Pow;

    Hash(const string& s) {
        int n = s.length();
        hash.resize(n + 1, {0, 0});
        Pow.resize(n + 1, {1, 1});

        for (int i = 0; i < n; i++) {
            hash[i + 1] = {
                (uint64_t(hash[i].first) * BASE1 + (s[i] - 'a' + 1)) % MOD,
                (uint64_t(hash[i].second) * BASE2 + (s[i] - 'a' + 1)) % MOD
            };

            Pow[i + 1] = {
                (uint64_t(Pow[i].first) * BASE1) % MOD,
                (uint64_t(Pow[i].second) * BASE2) % MOD
            };
        }
    }

    pair<int, int> get(int l, int r) {
        l++, r++;
        int hash1 = (hash[r].first - uint64_t(hash[l - 1].first) * Pow[r - l + 1].first % MOD + MOD) % MOD;
        int hash2 = (hash[r].second - uint64_t(hash[l - 1].second) * Pow[r - l + 1].second % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};


int main() {

}