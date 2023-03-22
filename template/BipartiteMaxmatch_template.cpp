#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n1, n2, m, match[maxn], st[maxn];

bool allocate_couple(int now){
    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(!st[nto]){
            st[nto] = 1;
            if(!match[nto] || allocate_couple(match[nto])){
                match[now] = nto, match[nto] = now;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMaxmatch(){
    memset(match, 0, sizeof(match));
    int ret = 0;
    for (int i = 1; i <= n1; i++){
        if(!match[i]){
            memset(st, 0, sizeof(st));
            ret += allocate_couple(i);
        }
    }
    return ret;
}