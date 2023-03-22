/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-11-19
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

const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;

int f[maxn][maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n = 100;
    for (int i = 0; i < n; i++)
        f[i][0] = 1, f[0][i] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            int flag = 0;
            for (int kk = 1; kk <= i; kk++){
                if(i % kk == 0){
                    flag = flag || !f[i - kk][j];
                }
            }
            for (int kk = 1; kk <= j; kk++){
                if(j % kk == 0){
                    flag = flag || !f[i][j - kk];
                }
            }
            f[i][j] = flag;
        }
    }
    
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 20; j++){
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}