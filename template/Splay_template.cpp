#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct Splay_Node{
    int s[2], fath;
    int size, val, flag;
    void init(int _val, int _fath){
        val = _val, fath = _fath, flag = 0;
    }
};

class Splay{
public:
    Splay_Node tr[maxn];
    int idx, root, n;
    Splay(int _n){
        memset(tr, 0, sizeof(tr));
        idx = 0, root = 0, n = _n;
    }
    
    void pushup(int x){
        tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
        // TODO: do something
    }
    
    void pushdown(int x){
        // similar to pushdown of segment tree
        if(tr[x].flag){
            // TODO: do something
            tr[x].flag = 0;
        }
    }

    void rotate(int x){
        // unify left-rotate and right-rotate into one rotate function
        int y = tr[x].fath, z = tr[y].fath;
        int xisright = (x == tr[y].s[1]);
        int yisright = (y == tr[z].s[1]);
        // first from bottom to top
        tr[z].s[yisright] = x, tr[x].fath = z;
        tr[y].s[xisright] = tr[x].s[xisright ^ 1], tr[tr[x].s[xisright ^ 1]].fath = y;
        tr[x].s[xisright ^ 1] = y, tr[y].fath = x;
        // there is no need to pushup(z), cuz the state higher than z don't change
        pushup(y), pushup(x);
    }

    // rotate until node k is node x's **direct** father
    void splay_basic(int x, int k){
        while(tr[x].fath != k){
            int y = tr[x].fath, z = tr[y].fath;
            if(z != k)
                if((tr[z].s[1] == y) != (tr[y].s[1] == x)) rotate(x);
                else rotate(y);
            rotate(x);
        }
        if(!k) root = x;
    }

    void insert(int v){
        int u = root, nf = 0;
        while(u) nf = u, u = tr[u].s[v > tr[u].val];
        u = ++idx;
        if(nf) tr[nf].s[v > tr[nf].val] = u;
        tr[u].init(v, nf);
        splay_basic(u, 0);
    }

    int get_k(int k){
        int u = root;
        while(1){
            // when we query node u, we should distribute its lazy tag to its sons.
            pushdown(u);
            if(k <= tr[tr[u].s[0]].size)
                u = tr[u].s[0];
            else if(k == tr[tr[u].s[0]].size + 1)
                return u;
            else
                k -= (tr[tr[u].s[0]].size + 1), u = tr[u].s[1];
        }
        return -1;
    }

    void output(int u){
        pushdown(u);
        if(tr[u].s[0]) output(tr[u].s[0]);
        cout << tr[u].val << " ";
        if(tr[u].s[1]) output(tr[u].s[1]);
    }
};