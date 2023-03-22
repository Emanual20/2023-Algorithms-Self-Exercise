/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2023-3-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;
vector<int> edges[maxn];

int n, m, vis[maxn];

int dfs(int now, int fm){
    int ret = 0;
    vis[now] = 1;
    for(auto &it : edges[now]){
        if(it != fm){
            if(vis[it]){
                ret = 1;
                return ret;
            }
            ret = dfs(it, now);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        edges[2 * i - 1].push_back(2 * i), edges[2 * i].push_back(2 * i - 1);
    }
    for (int i = 1; i <= m; i++){
        int nx, ny;
        char chx, chy;
        cin >> nx >> chx >> ny >> chy;
        int idx = nx * 2 - (chx == 'B'), idy = ny * 2 - (chy == 'B');
        edges[idx].push_back(idy), edges[idy].push_back(idx);
    }

    int ans_cycle = 0, ans_ncycle = 0;
    for (int i = 1; i <= 2 * n; i++){
        if(!vis[i]){
            st.clear();
            int flag = dfs(i, -1);
            ans_cycle += flag, ans_ncycle += !flag;
        }
    }
    cout << ans_cycle << " " << ans_ncycle << endl;
    return 0;
}