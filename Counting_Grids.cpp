#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const long long mod = 1e9 + 7;
#define INF (1LL << 60)
#define inf (1 << 30)
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}


ll mod_exp(ll x, ll y, ll mod){
    ll ans = 1;
    x = x%mod;
    while (y > 0) {
        if (y&1)
            ans = ans*x%mod;
        y = y>>1;
        x = x*x%mod;
    }
    return ans;
}


void solve(){
    ll n; cin>>n;
    
    ll n0 = n*n;
    ll n90 = 1;
    ll n180 = 1;
    if (n > 1 && (n&1)) {
        n90 = 1ll*(n+3)*(n-1)/4 - (n-1)/2 + 1;
        n180 = 1ll*(n+3)*(n-1)/2 - (n-1) + 1;
    }
    else if (n&1^1) {
        n90 = 1ll*n*(n+2)/4 - n/2;
        n180 = 1ll*n*(n+2)/2 - n;
    }
    ll ans = 0;
    ans = (ans + mod_exp(2, n0, mod)) % mod; //0 deg
    ans = (ans + mod_exp(2, n90, mod)) % mod; //90 deg
    ans = (ans + mod_exp(2, n180, mod)) % mod; //180 deg
    ans = (ans + mod_exp(2, n90, mod)) % mod; //270 deg
    ans = ans * mod_exp(4, mod-2, mod) % mod;
    cout<<ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}
