#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1E9 + 7 ;

struct P {
    long double x = 0, y = 0;
};

inline P operator+(const P &a, const P &b){ return P{a.x + b.x, a.y + b.y}; }
inline P operator-(const P &a, const P &b){ return P{a.x - b.x, a.y - b.y}; }
inline P operator*(const P &a, long double s){ return P{a.x * s, a.y * s}; }
inline long double dot(const P &a, const P &b){ return a.x*b.x + a.y*b.y; }
inline long double norm2(const P &a){ return dot(a,a); }

long double shortest_distone(const P &S1, const P &E1, const P &S2, const P &E2){
    const long double EPS = 1e-18L;

    long double T1 = sqrt((long double)norm2(E1 - S1));
    long double T2 = sqrt((long double)norm2(E2 - S2));

    P v1{0,0}, v2{0,0};
    if (T1 > EPS) v1 = (E1 - S1) * (1.0L / T1); 
    if (T2 > EPS) v2 = (E2 - S2) * (1.0L / T2);

    long double tmin = min(T1, T2);
    long double tmax = max(T1, T2);

    vector<long double> cand;
    cand.reserve(6);
    cand.push_back(0.0L);
    cand.push_back(tmin);
    cand.push_back(tmax);

    P d0 = S1 - S2;          
    P rv = P{v1.x - v2.x, v1.y - v2.y};

    long double a = norm2(rv);
    long double b = 2.0L * dot(d0, rv);

    if (a > EPS){
        long double tstar = - b / (2.0L * a);
        if (tstar >= 0.0L - EPS && tstar <= tmin + EPS) cand.push_back(tstar);
    }
    if (tmin < tmax - EPS){
        if (T1 < T2){
            P D = P{E1.x - S2.x, E1.y - S2.y};
            long double denom = norm2(v2);
            if (denom > EPS){
                long double tstar = dot(D, v2) / denom; 
                if (tstar >= tmin - EPS && tstar <= tmax + EPS) cand.push_back(tstar);
            }
        } else {
            P D = P{S1.x - E2.x, S1.y - E2.y};
            long double denom = norm2(v1);
            if (denom > EPS){
                long double tstar = - dot(D, v1) / denom;
                if (tstar >= tmin - EPS && tstar <= tmax + EPS) cand.push_back(tstar);
            }
        }
    }
    long double best2 = numeric_limits<long double>::infinity();
    for (long double t : cand){
        if (t < 0.0L) t = 0.0L;

        P p1, p2;
        if (t <= T1 + EPS) p1 = S1 + v1 * t; else p1 = E1;
        if (t <= T2 + EPS) p2 = S2 + v2 * t; else p2 = E2;
        best2 = min(best2, norm2(p1 - p2));
    }
    return sqrt((double)best2);
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
