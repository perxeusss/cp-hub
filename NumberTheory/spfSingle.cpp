#include<bits/stdc++.h>
using namespace std ;

  int spf(int x) {
    if (x == 1) return 1;
    if (x % 2 == 0) return 2;
    for (int d = 3; d * 1LL * d <= x; d += 2) {
        if (x % d == 0) return d;
    }
    return x;
}

int main() {

}