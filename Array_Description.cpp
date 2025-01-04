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
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<vector<ll>> dp(n,vector<ll>(m+1,0));
    if(vec[0]!=0){
        dp[0][vec[0]]=1;
    }
    else{
        for(int j=1;j<=m;j++){
            dp[0][j]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(vec[i]!=0){
            if(vec[i]-1>=1){
                dp[i][vec[i]] =( dp[i][vec[i]] +  dp[i-1][vec[i]-1])%mod;
            }
            dp[i][vec[i]] =( dp[i][vec[i]] + dp[i-1][vec[i]] )%mod;
            if(vec[i]+1<=m){
                dp[i][vec[i]] =( dp[i][vec[i]] + dp[i-1][vec[i]+1])%mod;
            }
        }
        else{
            for(int j=1;j<=m;j++){
                if(j-1>=1){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                }
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                if(j+1<=m){
                    dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans+ dp[n-1][i])%mod;
    }
    cout<<ans<<"\n";
    
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
