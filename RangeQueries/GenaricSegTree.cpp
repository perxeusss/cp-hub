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


// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<int> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<int> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) >> 1;
		build(start, mid, index << 1);
		build(mid + 1, end, index << 1 | 1);
		tree[index].merge(tree[index << 1], tree[index << 1 | 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) >> 1;
		if (mid >= query_index)
			update(start, mid, index << 1, query_index, u);
		else
			update(mid + 1, end, index << 1 | 1, query_index, u);
		tree[index].merge(tree[index << 1], tree[index << 1 | 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) >> 1;
		Node l, r, ans;
		l = query(start, mid, index << 1, left, right);
		r = query(mid + 1, end, index << 1 | 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, int val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	int val; // may change
	Node1() { // Identity element
		val = 0;	// may change
	}
	Node1(int p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val ^ r.val;  // may change
	}
};

struct Update1 {
	int val; // may change
	Update1(int p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};



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
