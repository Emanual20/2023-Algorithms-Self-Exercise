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

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i], mp[a[i]] = 1;
    for (int i = 0; i < m; i++)
        cin >> b[i], mp[b[i]] = 1;

    int tot = 1;
    for (auto it = mp.begin(); it != mp.end(); it++, tot++){
        mp[it->first] = tot;
    }
    for (int i = 0; i < n; i++)
        cout << mp[a[i]] << " ";
    cout << endl;
    for (int i = 0; i < m; i++)
        cout << mp[b[i]] << " ";
    cout << endl;
    return 0;
}