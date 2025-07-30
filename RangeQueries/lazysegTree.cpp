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

vector<int> seg, lazy ;

int merge(int left, int right) {
    return min(left, right) ;
}

void propagate(int st, int end, int ind) {
    seg[ind] += lazy[ind] ;

    if(st != end) {
        lazy[2 * ind] += lazy[ind] ;
        lazy[2 * ind + 1] += lazy[ind] ;
    }
    lazy[ind] = 0 ;
}

void build(vector<int> &a, int st, int end, int ind) {
    if(st == end) {
        seg[ind] = a[st] ;
        return ;
    }

    int mid = (st + end) / 2; ;

    build(a , st, mid, 2 * ind) ;
    build(a, mid + 1 , end, 2 * ind + 1) ;

    seg[ind] = merge(seg[2 * ind] , seg[2 * ind + 1]) ;
}

void update(int st, int end, int ind , int l, int r, int val) {

    if(lazy[ind]) propagate(st, end, ind) ;

    if(l <= st && end <= r) {
        lazy[ind] += val ;
        propagate(st, end, ind) ;
        return ;
    }
    if(st > r || end < l) return ;

    int mid = (st + end) / 2 ;

    update(st, mid, 2 * ind, l, r, val) ;
    update(mid + 1, end, 2 * ind + 1, l, r , val) ;

    seg[ind] = merge(seg[2 * ind] , seg[2 * ind + 1]) ;    
}

int query(int st, int end, int ind, int l, int r) {
    
    if(lazy[ind]) propagate(st, end, ind) ;

    if(st > r || end < l ) return INF ;
    if(st >= l && end <= r) return seg[ind] ;

    int mid = (st + end) / 2;

    int leftAnswer = query(st, mid, 2 * ind, l, r) ;
    int rightAnswer = query(mid + 1, end, 2 * ind + 1, l, r) ;

    return merge(leftAnswer, rightAnswer) ;
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
