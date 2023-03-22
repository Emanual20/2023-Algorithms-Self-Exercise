/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2023-3-19
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

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
ll n, n1, n2;
struct item{
    ll v, len;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> n1 >> n2;
    vector<item> v1(n1, {0, 0}), v2(n2, {0, 0});
    for (int i = 0; i < n1; i++){
        cin >> v1[i].v >> v1[i].len;
    }
    for (int i = 0; i < n2; i++){
        cin >> v2[i].v >> v2[i].len;
    }

    ll ans = 0, idx = 0, resx = 0, idy = 0, resy = 0;
    while(idx < n1 && idy < n2){
        ll nx = v1[idx].len - resx, ny = v2[idy].len - resy;
        if(v1[idx].v == v2[idy].v){
            ans += min(nx, ny);
        }
        resx += min(nx, ny), resy += min(nx, ny);
        if(resx == v1[idx].len)
            idx += 1, resx = 0;
        if(resy == v2[idy].len)
            idy += 1, resy = 0;
    }

    cout << ans << endl;
    return 0;
}