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

const int maxn = 10 + 2;
const int inf = 0x3f3f3f3f;
int n, m, a[maxn][maxn];

int dfs(int nx, int ny, set<int> st){
    int ret = 0;
    if(st.count(a[nx][ny]) != 0){
        return 0;
    }
    else
        st.insert(a[nx][ny]);

    if(nx == n && ny == m)
        return 1;

    if(nx < n && st.count(a[nx + 1][ny]) == 0){
        ret += dfs(nx + 1, ny, st);
        st.erase(a[nx + 1][ny]);
    }
    if(ny < m && st.count(a[nx][ny + 1]) == 0){
        ret += dfs(nx, ny + 1, st);
        st.erase(a[nx][ny + 1]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    set<int> st;
    auto ans = dfs(1, 1, st);
    cout << ans << endl;
    return 0;
}