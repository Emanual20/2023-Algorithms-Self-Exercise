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

const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
set<int> st_ncall;
set<int> st_ncome;
int n, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        st_ncall.insert(i);
    }
    while(q--){
        int op; cin >> op;
        if(op == 1){
            auto it = st_ncall.begin();
            st_ncome.insert(*it), st_ncall.erase(*it);
        }
        else if(op == 2){
            int x; cin >> x;
            st_ncome.erase(x);
        }
        else if(op == 3){
            auto it = st_ncome.begin();
            cout << *it << "\n";
        }
    }
    return 0;
}