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
const ll  MAX=2e6+100;
vector<ll> factorial(MAX,1);
void precompute(){
    factorial[1]=1;
    for(ll i=2;i<MAX;i++){
        factorial[i]=(1ll* factorial[i-1] *i )%mod;
    }
}
ll  binPow(ll  a,ll  b, ll  mod){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(1ll* ans * a)%mod;
        }
        b>>=1;
        a=(1ll* a * a)%mod;
    }
    return ans;
}
ll  ncr(ll  n,ll  r){
    if(r>n)return 0;
    ll  ans=factorial[n];
    ans= (1ll  * ans * binPow(factorial[n-r],mod-2,mod))%mod;
    ans= ( 1ll * ans * binPow(factorial[r],mod-2,mod))%mod;
    return ans;
}
void solve(){
    precompute();
    ll n;
    cin>>n;
    if(n&1){
        cout<<0<<'\n';
        return ;
    }
    n>>=1;
    int num =ncr(2*n,n);
    int inv=binPow(n+1,mod-2,mod);
    cout<< (1ll*num * inv )%mod;

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
