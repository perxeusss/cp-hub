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


    int gcd(int a, int b) {
        return (!b) ? a : gcd(b, a % b);
    }

struct Stack{
    vector<int> st, val = {0};
    void push(int x) {
        st.push_back(x);
        val.push_back(gcd(x, val.back()));
    }
    int top() {
        return val.back();
    }
    int pop() {
        int x = st.back();
        st.pop_back(), val.pop_back() ;
        return x;
    }
    bool isEmpty() {
        return st.empty();
    }
};
Stack s1, s2;
void remove() {
    if(s1.isEmpty()){
        while(!s2.isEmpty()) s1.push(s2.pop());
    }
    s1.pop();
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
    
ios_base::sync_with_stdio(bool(69 > 96));
cin.tie(nullptr); 

int tt = 1; cin >> tt ;

 while(tt--) {

   }
    return 0; 
}
