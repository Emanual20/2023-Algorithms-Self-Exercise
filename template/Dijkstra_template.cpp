/*
* naive_dijkstra
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2 + 10;
const int inf = 0x3f3f3f3f;
int n, m, edges[maxn][maxn], dist[maxn], vis[maxn];
void naive_dijkstra(int source){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[source] = 0;
    for (int i = 1; i <= n; i++){
        int now_min = inf, now_index = -1;
        for (int j = 1; j <= n; j++){
            if(now_min > dist[j] && !vis[j]){
                now_min = dist[j];
                now_index = j;
            }
        }
        vis[now_index] = 1, dist[now_index] = now_min;
        for (int j = 1; j <= n; j++){
            if(!vis[j]){
                dist[j] = min(dist[j], dist[now_index] + edges[now_index][j]);
            }
        }
    }
}
*/


/**
 * min-heap dijkstra
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 150000 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int to, w;
};
int n, m, dist[maxn], vis[maxn];
vector<edge> edges[maxn];
void heap_dijkstra(int source){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    // min-heap
    priority_queue<pii, vector<pii>, greater<pii>> q;

    dist[source] = 0;
    q.push({0, source});

    while(!q.empty()){
        pii now = q.top();
        int nidx = now.second;
        q.pop();
        if(vis[nidx])
            continue;
        vis[nidx] = 1;
        for (auto &iter : edges[nidx]){
            int nto = iter.to, nw = iter.w;
            dist[nto] = min(dist[nto], dist[nidx] + nw);
            q.push({dist[nto], nto});
        }
    }
}