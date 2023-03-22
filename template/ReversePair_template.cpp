#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e5 + 10;
int t, n, a[maxn];

ll mergesort(int left, int right){
    if(left == right) return 0;
    ll ret = 0;
    int mid = left + right >> 1;
    if(left <= mid)
        ret += mergesort(left, mid);
    if(mid + 1 <= right)
        ret += mergesort(mid + 1, right);

    int i = left, j = mid + 1;
    for (i = left; i <= mid; i++){
        // Note here: if a[i] == a[j] is regarded as an inverse pair;
        //            here shall be a[i] >= a[j] or something else
        while(j <= right && a[i] > a[j])
            j += 1;
        ret += (j - mid - 1);
    }

    vector<int> tmp;
    i = left, j = mid + 1;
    while(i <= mid && j <= right){
        while(a[i] < a[j] && i <= mid && j <= right)
            tmp.push_back(a[i]), i += 1;
        while(a[i] >= a[j] && i <= mid && j <= right)
            tmp.push_back(a[j]), j += 1;
    }
    while(i <= mid)
        tmp.push_back(a[i]), i += 1;
    while(j <= right)
        tmp.push_back(a[j]), j += 1;

    for (int i = 0; i < tmp.size(); i++){
        a[left + i] = tmp[i];
    }

    return ret;
}