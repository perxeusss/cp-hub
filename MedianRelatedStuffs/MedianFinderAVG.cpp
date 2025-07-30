
#include<bits/stdc++.h>
using namespace std ;


class MedianFinder {
    int sz ;
    multiset<int> left, right ;

public:
    MedianFinder() {  sz = 0 ; }
    
    void adjust() {
        if(left.size() > right.size() + 1) {
            auto last = prev(end(left) ) ;
            right.insert(*last) ;
            left.erase(last) ;
        }
        if(left.size() < right.size()) {
            auto first = right.begin() ;
            left.insert(*first) ;
            right.erase(first) ;
        }
    }
    void addNum(int num) {
        if(left.empty() || *(left.rbegin()) >= num) {
            left.insert(num) ;
        }
        else right.insert(num) ;
        sz++ ;
        adjust() ;
    }
    void removeNum(int num) {
        if(left.find(num) != left.end()) left.erase(left.find(num)) ;
        else right.erase(right.find(num)) ;
        adjust() ;
        sz-- ;
    }
    
    double findMedian() {
        double lst = *(prev(end(left))) ;
        if(sz & 1)  return lst ;

        double fst = *right.begin() ;
        return (lst + fst) / 2 ; 
    }
};

int main() {


}