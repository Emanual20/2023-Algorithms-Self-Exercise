#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
struct edge{
    int to;
};
vector<edge> edges[maxn];

int n, m;
int TimeStamp = 0, dfn[maxn], low[maxn], vis[maxn];
int scc_id[maxn], scc_sz[maxn], scc_cnt = 0;
stack<int> s;

void tarjan_scc(int now){
    dfn[now] = low[now] = ++TimeStamp;
    s.push(now), vis[now] = 1;

    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(!dfn[nto]){
            tarjan_scc(nto);
            low[now] = min(low[now], low[nto]);
        }
        else if(vis[nto]){
            low[now] = min(low[now], dfn[nto]);
        }
    }

    if(dfn[now] == low[now]){
        scc_cnt++;
        int x;
        do{
            x = s.top();
            s.pop(), vis[x] = 0, scc_id[x] = scc_cnt, scc_sz[scc_cnt]++;
        } while (x != now);
    }
}

void Calc_SCC(){
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(scc_id, 0, sizeof(scc_id));
    memset(scc_sz, 0, sizeof(scc_sz));
    while(!s.empty()) s.pop();
    TimeStamp = 0, scc_cnt = 0;
    for (int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan_scc(i);
        }
    }
}

vector<edge> new_edges[maxn];
void build_SCCDAG(){
    for (int i = 1; i <= n; i++){
        for(auto &iter : edges[i]){
            int nfm = i, nto = iter.to;
            if(scc_id[nfm] != scc_id[nto]){
                new_edges[scc_id[nfm]].push_back({scc_id[nto]});
            }
        }
    }
}