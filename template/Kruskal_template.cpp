/**
 * @file kruskal_template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, f[maxn];
struct edge{
    int fm, to, w;
};
vector<edge> edges;
bool comp(edge e1, edge e2){
    if(e1.w == e2.w) return e1.fm < e2.fm;
    return e1.w < e2.w;
}
void init_dsu(int x){
    for(int i = 1; i <= x; i++){
        f[i] = i;    
    }
}
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int src, int dst){
    int s = find(src), d = find(dst);
    f[s] = d;
}

int kruskal(){
    init_dsu(n);
    int ret = 0, tot = 0;
    sort(edges.begin(), edges.end(), comp);
    for(auto &now : edges){
        if(tot == n - 1 || find(now.fm) == find(now.to)){
            continue;
        }
        ret += now.w, tot++;
        merge(now.fm, now.to);
    }
    return (tot == n - 1 ? ret : inf);
}