#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int sum, left, right;
	int lazy;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void Pushup(int k){
		tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
	}

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = a[left];
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k)), build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Pushdown(int k){
		if (tree[k].lazy == 0) return;
		tree[lson(k)].lazy += tree[k].lazy, tree[rson(k)].lazy += tree[k].lazy;
		tree[lson(k)].sum += tree[k].lazy * (tree[lson(k)].right - tree[lson(k)].left + 1);
		tree[rson(k)].sum += tree[k].lazy * (tree[rson(k)].right - tree[rson(k)].left + 1);
		tree[k].lazy = 0;
	}

	void Update_seg(int l, int r, int x, int y, int C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum += (r - l + 1) * C;
			tree[k].lazy += C;
			return;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	int Query_seg(int l, int r, int x, int y, int k = 1){
		int ret = 0;
		if (x <= l && r <= y){
			ret = tree[k].sum;
			return ret;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if (mid >= x) ret += Query_seg(l, mid, x, y, lson(k));
		if (mid < y) ret += Query_seg(mid + 1, r, x, y, rson(k));
		return ret;
	}
};