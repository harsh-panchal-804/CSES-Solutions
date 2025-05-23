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



void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> vec(n+1,vector<ll>(n+1,LONG_LONG_MAX));
    for(ll i=0;i<m;i++){
        ll a ,b,c;
        cin>>a>>b>>c;
        vec[a][b]=min(c,vec[a][b]);
        vec[b][a]=min(c,vec[b][a]);
    }
    for(int i=1;i<=n;i++)vec[i][i]=0;
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if (vec[i][k] < INF && vec[k][j] < INF)
                {
                    vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
                } 
                
            }
        }
    }
  
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout << (vec[a][b] >= INF ? -1 : vec[a][b]) << "\n";
    }
    
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
