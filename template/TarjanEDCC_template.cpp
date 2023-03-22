#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
const int maxm = 2e4 + 10;

struct edge{
    int to, index;
};
vector<edge> edges[maxn];
int m, n;

stack<int> s;
int dfn[maxn], low[maxn], edcc_cnt = 0, Timestamp;
int isbridge[maxm], edcc_id[maxn], edcc_sz[maxn];
// notice that here fm means the from edge, but not the from node!
// cause there may exist multi-edge in the graph, so we need use from edge
void tarjan_edcc(int u, int fm){
    dfn[u] = low[u] = ++Timestamp;
    s.push(u);

    for(auto &iter : edges[u]){
        int nto = iter.to, nindex = iter.index;
        if(!dfn[nto]){
            tarjan_edcc(nto, nindex);
            low[u] = min(low[u], low[nto]);
            if(dfn[u] < low[nto]){
                isbridge[nindex] = isbridge[nindex ^ 1] = 1;
            }
        }
        else if(nindex != (fm ^ 1)){
            low[u] = min(low[u], dfn[nto]);
        }
    }

    if(dfn[u] == low[u]){
        int y;
        ++edcc_cnt;
        do{
            y = s.top();
            s.pop();
            edcc_id[y] = edcc_cnt, edcc_sz[edcc_cnt]++;
        } while (y != u);
    }
}