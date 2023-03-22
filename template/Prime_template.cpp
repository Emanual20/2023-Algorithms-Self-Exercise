#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int n, prime[maxn];
/*
 * Initalize a Prime Table by Eratothenes.
 * if prime(i) == 1 means i is **not** a prime.
 * Complexity: O(nloglogn)
 */
vector<int> Eratothenes(int up_bound){
    vector<int> ret;
    for (ll i = 2; i <= up_bound; i++){
        if(!prime[i]){
            for (ll j = i * i; j <= up_bound; j += i){
                prime[j] = 1;
            }
            ret.push_back(i);
        }
    }
    return ret;
}

/*
 * Factorize a number by 'The Fundamental Theorem of Arithmetic'.
 * Items are stored in increasing order of prime.
 * Complexity: O(n^(1/2))
 */
struct item{
    ll prime, tot;
};
vector<item> Prime_Factorization(int x){
    vector<item> ret;
    for (int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int tot = 0;
            while(x % i == 0) 
                x /= i, tot++;
            ret.push_back({i, tot});
        }
    }
    if(x > 1) ret.push_back({x, 1});
    return ret;
}

/*
 * Factorize a number's factorial.
 * You shall call Eratothenes to initialize prime table before calling this function.
 * Items are stored in increasing order of prime.
 * Complexity: O((n / ln n)^(1/2))
 */
vector<item> Factorial_Factorization(int x, vector<int> primes){
    vector<item> ret;
    for (int i = 0; i < primes.size(); i++){
        if(x % primes[i] == 0){
            int tot = 0;
            while(x % primes[i] == 0)
                x /= primes[i], tot++;
            ret.push_back({primes[i], tot});
        }
        if(primes[i] > x / primes[i]) break;
    }
    if(x > 1) ret.push_back({x, 1});
    return ret;
}
