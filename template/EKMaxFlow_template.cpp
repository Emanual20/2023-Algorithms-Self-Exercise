/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

ll n, m, s, t;

struct edge{
    int to, f;
    int nid, rid;
};
vector<edge> edges[maxn];

int vis[maxn];
struct RetInfo_FindAug{
    int succ;
    vector<pii> pre;
    vector<ll> d;

    RetInfo_FindAug(){
        succ = 0;
        pre = vector<pii>(maxn, make_pair(0, 0));
        d = vector<ll>(maxn, inf);
    }
};

RetInfo_FindAug FindAugPath(){
    RetInfo_FindAug ret;

    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(s), vis[s] = 1;
    while(!q.empty() && !ret.succ){
        int now = q.front(), cnt = 0;
        for(auto &iter : edges[now]){
            ll nto = iter.to, nf = iter.f;
            if(!vis[nto] && nf > 0){
                q.push(nto), vis[nto] = 1;
                ret.d[nto] = min(ret.d[now], nf);
                ret.pre[nto] = make_pair(now, cnt);
                if(nto == t){
                    ret.succ = 1;
                    return ret;
                }
            }
            cnt++;
        }
        q.pop();
    }
    return ret;
}

ll Edmonds_Karp(){
    ll max_flow = 0;
    RetInfo_FindAug info;
    while(info = FindAugPath(), info.succ){
        ll nminc = info.d[t];
        max_flow += nminc;
        for (int tmp = t; tmp != s; tmp = info.pre[tmp].first){
            auto info_pre = info.pre[tmp];
            auto iter = edges[info_pre.first][info_pre.second];
            int nnid = iter.nid, nrid = iter.rid;
            int nfm = edges[iter.to][nrid].to, nto = iter.to;
            edges[nfm][nnid].f -= nminc;
            edges[nto][nrid].f += nminc;
        }
    }
    return max_flow;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int fm, to, c;
        cin >> fm >> to >> c;
        int fm_rid = edges[to].size(), to_rid = edges[fm].size();
        edges[fm].push_back({to, c, to_rid, fm_rid});
        edges[to].push_back({fm, 0, fm_rid, to_rid});
    }

    ll ans = Edmonds_Karp();
    cout << ans << endl;
    return 0;
}