#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n;
int color[maxn], vis[maxn];
bool CheckPartBipartite(int root){
    int tot = 0;
    color[root] = 1;

    queue<int> q;
    q.push(root), vis[root] = 1, tot = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(!vis[to]){
                vis[to] = 1, tot++, color[to] = 3 - color[now], q.push(to);
            }
            else if(color[to] == color[now]){
                return false;
            }
        }
    }
    return true;
}

bool CheckBipartite(){
    int ret = 1;
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            ret = ret && CheckPartBipartite(i);
        }
    }
    return ret;
}