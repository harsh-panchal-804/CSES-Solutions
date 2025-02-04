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
const int MAXN = 200005;  
const int LOG = 32;       
ll up[MAXN][LOG];

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> parent(n + 1, 0);
    for (ll i = 1; i <= n; i++){
        cin >> parent[i];
    }
   
    
    
    for (ll i = 1; i <= n; i++){
        up[i][0] = parent[i];
    }
    
   
    for (ll j = 1; j < LOG; j++){
        for (ll i = 1; i <= n; i++){
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }
    
  
    while(q--){
        ll x, k;
        cin >> x >> k;
        ll ans = x;
        for (ll i = 0; i < LOG; i++){
            if ((1LL << i) & k){
                ans = up[ans][i];
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    // cin >> test;
    while(test--){
         solve();
    }
    
    return 0;
}
