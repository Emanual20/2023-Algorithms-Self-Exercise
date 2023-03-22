/*
* HeavyLightDecomposition
* Time Complexity: O(nlog^2n)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
ll MOD = 1e9 + 7;

int n, root, q;
vector<int> edges[maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int left, right;
	ll sum, lazy;
};

struct HeavyLightNode{
    int fath, heavyson, top;
    int sz, depth;
    int w, seq;
} a[maxn];

struct HeavyLightDecomposition{
public:
    int Timestamp, ts2orindex[maxn];
	seg_node tree[4 * maxn];
public:
    void init(){
        Timestamp = 0, memset(ts2orindex, 0, sizeof(ts2orindex));
    }

    void dfs1(int now, int fm, int depth){
        a[now].fath = fm, a[now].depth = depth, a[now].sz = 1;
        for(auto &it : edges[now]){
            if(it != fm){
                dfs1(it, now, depth + 1);
                a[now].sz += a[it].sz;
                if(a[it].sz > a[a[now].heavyson].sz)
                    a[now].heavyson = it;
            }
        }
    }

    void dfs2(int now, int fm, int tp){
        Timestamp += 1, a[now].seq = Timestamp, ts2orindex[Timestamp] = now, a[now].top = tp;
        // if node now haven't any heavy sons, return
        if(!a[now].heavyson) return;
        dfs2(a[now].heavyson, now, tp);
        for(auto &it : edges[now]){
            if(it != fm && it != a[now].heavyson){
                // light node is the first node of any chain
                dfs2(it, now, it);
            }
        }
    }

	void Pushup(int k){
		tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
	}

	void build_seg(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = a[ts2orindex[left]].w;
			return;
		}
		int mid = (left + right) >> 1;
		build_seg(left, mid, lson(k));
		build_seg(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Pushdown(int k){
		if (tree[k].lazy == 0) return;
		tree[lson(k)].lazy += tree[k].lazy, tree[rson(k)].lazy += tree[k].lazy;
        tree[lson(k)].lazy %= MOD, tree[rson(k)].lazy %= MOD;
        tree[lson(k)].sum += tree[k].lazy * (tree[lson(k)].right - tree[lson(k)].left + 1);
        tree[lson(k)].sum %= MOD;
        tree[rson(k)].sum += tree[k].lazy * (tree[rson(k)].right - tree[rson(k)].left + 1);
        tree[rson(k)].sum %= MOD;
        tree[k].lazy = 0;
	}

	void Update_seg(int l, int r, int x, int y, ll C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum += (r - l + 1) * C, tree[k].sum %= MOD;
			tree[k].lazy += C, tree[k].lazy %= MOD;
			return;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	ll Query_seg(int l, int r, int x, int y, int k = 1){
		ll ret = 0;
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

    void UpdateSubtree(int u, ll k){
        Update_seg(1, n, a[u].seq, a[u].seq + a[u].sz - 1, k);
    }

    ll QuerySubtree(int u){
        return Query_seg(1, n, a[u].seq, a[u].seq + a[u].sz - 1);
    }

    void UpdatePath(int u, int v, ll k){
        while(a[u].top != a[v].top){
            if(a[a[u].top].depth < a[a[v].top].depth)
                swap(u, v);
            Update_seg(1, n, a[a[u].top].seq, a[u].seq, k);
            u = a[u].top;
            u = a[u].fath;
        }
        if(a[u].depth < a[v].depth)
            swap(u, v);
        Update_seg(1, n, a[v].seq, a[u].seq, k);
    }

    ll QueryPath(int u, int v){
        ll ret = 0;
        while(a[u].top != a[v].top){
            if(a[a[u].top].depth < a[a[v].top].depth)
                swap(u, v);
            ret += Query_seg(1, n, a[a[u].top].seq, a[u].seq);
            u = a[u].top;
            u = a[u].fath;
        }
        if(a[u].depth < a[v].depth)
            swap(u, v);
        ret += Query_seg(1, n, a[v].seq, a[u].seq);
        return ret;
    }

    ll QueryLCA(int u, int v){
        while(a[u].top != a[v].top){
            if(a[a[u].top].depth < a[a[v].top].depth)
                swap(u, v);
            u = a[a[u].top].fath;
        }
        return a[u].depth < a[v].depth ? u : v;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q >> root >> MOD;
    for (int i = 1; i <= n; i++){
        cin >> a[i].w;
    }

    for (int i = 1; i < n; i++){
        int nfm, nto;
        cin >> nfm >> nto;
        edges[nfm].push_back(nto), edges[nto].push_back(nfm);
    }

    HeavyLightDecomposition hld;
    hld.init();
    hld.dfs1(root, -1, 1);
    hld.dfs2(root, -1, root);
    hld.build_seg(1, n);

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int u, v, k;
            cin >> u >> v >> k;
            hld.UpdatePath(u, v, k % MOD);
        }
        else if(op == 2){
            int u, v;
            cin >> u >> v;
            ll ans = hld.QueryPath(u, v) % MOD;
            cout << ans << "\n";
        }        
        else if(op == 3){
            int u, k;
            cin >> u >> k;
            hld.UpdateSubtree(u, k % MOD);
        }
        else if(op == 4){
            int u;
            cin >> u;
            ll ans = hld.QuerySubtree(u) % MOD;
            cout << ans << "\n";
        }
    }
    return 0;
}