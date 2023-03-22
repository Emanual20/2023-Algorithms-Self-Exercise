typedef long long ll;
const ll MOD = 1e9 + 7;
ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}