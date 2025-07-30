#include<bits/stdc++.h>
using namespace std ;

#define int long long 

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 

}