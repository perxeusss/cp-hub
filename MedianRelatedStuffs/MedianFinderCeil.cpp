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

class MedianFinder {
    int sz;
    multiset<int> left, right;

public:
    MedianFinder() {
        sz = 0;
    }

    void adjust() {
        // Ensure left has ceil(sz / 2) elements
        while (left.size() > (sz + 1) / 2) {
            auto it = prev(end(left));
            right.insert(*it);
            left.erase(it);
        }
        while (left.size() < (sz + 1) / 2) {
            auto it = begin(right);
            left.insert(*it);
            right.erase(it);
        }
    }

    void addNum(int num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        sz++;
        adjust();
    }

    void removeNum(int num) {
        if (left.find(num) != left.end()) {
            left.erase(left.find(num));
        } else {
            right.erase(right.find(num));
        }
        sz--;
        adjust();
    }

    int findMedian() {
        return *left.rbegin(); 
    }
};

int32_t main() {
    
ios_base::sync_with_stdio(bool(69 > 96));
cin.tie(nullptr); 

int tt = 1;
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

