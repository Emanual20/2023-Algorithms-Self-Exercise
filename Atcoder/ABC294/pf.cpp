/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2023-3-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const long double eps = 1e-12;
int n, m;
ll k;
struct item{
    int s, w;
};
vector<item> va, vb;

bool check(long double ck){
    long double portion = ck / (1 - ck);
    ll tot = 0;
    vector<long double> v;
    for (int i = 0; i < m; i++){
        long double res = vb[i].s - vb[i].w * portion;
        v.push_back(res);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        long double res = va[i].s - va[i].w * portion;
        tot += v.end() - lower_bound(v.begin(), v.end(), -res);
    }
    // cout << ck << " " << tot << endl;
    return tot >= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    va = vector<item>(n, {0, 0}), vb = vector<item>(m, {0, 0});
    for (int i = 0; i < n; i++){
        cin >> va[i].s >> va[i].w;
    }
    for (int i = 0; i < m; i++){
        cin >> vb[i].s >> vb[i].w;
    }

    long double l = 0, r = 1;
    while(abs(l - r) > eps){
        long double mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << l * 100 << endl;
    return 0;
}