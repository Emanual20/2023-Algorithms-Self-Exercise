#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll MOD = 998244353;
ll fac[maxn], inv[maxn], n, a;
vector<ll> items;
ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1)
            ret = ret * base % MOD;
        base = base * base % MOD;
        index >>= 1;
    }
    return ret;
}
/*
* Note that maxn = 2e5 originally, which may cause TLE in some cases.
*/
void init(){
    fac[0] = 1, fac[1] = 1;
    for (int i = 2; i < maxn; i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    // a * a^(p-2) === 1(mod p), when p is a prime
    for (int i = 0; i < maxn; i++){
        inv[i] = quickpow(fac[i], MOD - 2);
    }
}
/*
* When 1 <= m <= n <= 1e5, we usually use this func
*/
ll regular_C(ll m, ll n){
    if(m > n) return 0;
    if(m == n) return 1;
    return fac[n] * inv[n - m] % MOD * inv[m] % MOD;
}
/*
* When n is too big(n < 1e9) and m is very small(m < 1e3)
*/
// ll C(ll m, ll n){
//     if(m > n)
//         return 0;
//     ll ret = 1;
//     for (ll i = 0; i < m; i++){
//         ret *= (n - i);
//         ret %= MOD;
//     }
//     return ret * inv[m] % MOD;
// }
/*
* When n, m are both enormous(m <= n <= 1e18), when p is a small prime(p < 1e5):
*   We use Lucas theorem.
*/
ll C(ll m, ll n){
    if(m <= MOD && n <= MOD)
        return regular_C(m, n) % MOD;
    return C(m % MOD, n % MOD) * C(m / MOD, n / MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}