#include<bits/stdc++.h>
using namespace std ;

#define int long long 


vector<int> phi ;
void PHI(int n) {
    phi.assign(n + 7, 0);
    iota(phi.begin() , phi.end(), 0) ;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 

}