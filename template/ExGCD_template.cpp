typedef long long ll;
ll ex_gcd(ll a, ll b) {
	return b == 0 ? a : ex_gcd(b, a % b);
}