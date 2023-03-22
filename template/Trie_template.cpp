#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 2e5 + 10;
class Trie{
    int son[maxn][26], cnt[maxn], idx = 1;
public:
    void insert(std::string s){
        int lens = s.length();
        int p = 0;
        for (int i = 0; i < lens; i++){
            int now = s[i] - 'a';
            if(!son[p][now]){
                son[p][now] = idx++;
            }
            p = son[p][now];
        }
        cnt[p] += 1;
    }

    int query(std::string s){
        int lens = s.length();
        int p = 0;
        for (int i = 0; i < lens; i++){
            int now = s[i] - 'a';
            if(!son[p][now]) return 0;
            p = son[p][now];
        }
        return cnt[p];
    }
};