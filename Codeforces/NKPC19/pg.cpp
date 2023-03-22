#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
string a, b;
ll vis1[128], vis2[128];

int main() {
    cin >> a >> b;
    ll n1 = a.length(), n2 = b.length();
    ll ans = 1ll * (n1 + 1) * (n2 + 1);
    for(int i = 0; i < n1; i++) {
        vis1[a[i] - 'a']++;
    }
    for(int i = 0; i < n2; i++) {
        vis2[b[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        ans -= 1ll * vis1[i] * vis2[i];
    }
    cout << ans << endl;
    return 0;
}