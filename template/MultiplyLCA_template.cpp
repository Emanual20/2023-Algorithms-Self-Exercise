#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int maxp = 20;
int n, q, rt;
int depth[maxn], fa[maxn][maxp];
vector<int> edges[maxn];

void InitDepthAndFa(int root){
    memset(depth, 0x3f, sizeof(depth));
    memset(fa, 0, sizeof(fa));
    fa[root][0] = 0, depth[0] = 0, depth[root] = 1;

    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            if(depth[iter] > depth[now] + 1){
                q.push(iter);
                depth[iter] = depth[now] + 1, fa[iter][0] = now;
                for (int i = 1; i < maxp; i++){
                    fa[iter][i] = fa[fa[iter][i - 1]][i - 1];
                }
            }
        }
    }
}

int Calc_LCA(int x, int y){
    if(depth[x] > depth[y]){
        swap(x, y);
    }
    for (int i = maxp - 1; i >= 0; i--){
        if(depth[fa[y][i]] >= depth[x]){
            y = fa[y][i];
        }
    }
    if(x == y)
        return x;
    for (int i = maxp - 1; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}