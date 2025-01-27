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
const int MOD=mod;
ll  inverse(ll  a,ll  b, ll  mod){
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


void solve(){
   ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
    {
        ans+=((n/i)*i)%MOD;
        ans%=MOD;
    }
    ll l=(ll)sqrt(n);
    for(ll i=sqrt(n);i>=1;i--)
    {
        ll r=n/i;
        ll sum=0;
        sum+=((((r%MOD)*((r+1)%MOD))%MOD)*inverse(2,mod-2,mod))%MOD;
        sum%=MOD;
        sum-=((((l%MOD)*((l+1)%MOD))%MOD)*inverse(2,mod-2,mod))%MOD;
        sum=(sum+MOD)%MOD;
        sum=(sum*i)%MOD;
        l=r;
        ans=(ans+sum)%MOD;
        //cout<<sum<<" ";
    }
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
