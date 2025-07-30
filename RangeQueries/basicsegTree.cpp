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

vector<int> segTree ;

int merge(int left, int right) {
    return left + right ;
}
void buildTree(vector<int> &a, int st, int end, int ind) {
    if (st == end) {
        segTree[ind] = a[st] ;
        return ;
    }
    int mid = (st + end) >> 1 ;

    buildTree(a, st, mid, ind << 1 ) ;
    buildTree(a, mid + 1, end, ind << 1 | 1) ;

    segTree[ind] = merge(segTree[ind << 1] , segTree[ind << 1 | 1]) ;
}

void updateTree(vector<int> &a, int st, int end, int ind, int pos, int val) {
    if(st == end) {
        a[pos] = val ;
        segTree[ind] = a[pos] ;
        return ;
    }
    int mid = (st + end) / 2 ;

    if(pos <= mid) updateTree(a, st, mid, (ind << 1), pos, val) ;
    else updateTree(a, mid + 1, end, (ind << 1 | 1), pos, val) ;

    segTree[ind] = merge(segTree[ind << 1] , segTree[ind << 1 | 1]) ;
}
int queryTree(vector<int> &a, int st, int end, int ind, int l, int r ) {
    if(l <= st && end <= r) return segTree[ind] ;
    if(end < l || st > r) return 0LL ;
    
    int mid = (st + end) >> 1 ;

    int leftAnswer = queryTree(a, st, mid , ind << 1, l, r) ;
    int rightAnswer = queryTree(a, mid + 1, end, ind << 1 | 1, l, r) ;

    return merge(leftAnswer , rightAnswer) ;
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
    
ios_base::sync_with_stdio(!true);
cin.tie(NULL); cout.tie(NULL); 

int tt = 1; cin >> tt ;

 while(tt--) {
        
   }
    return 0; 
}
