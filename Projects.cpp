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
unsigned long long dp[(int)1e6];
ll dfs(ll i,vector<vector<ll>>& vec){
    if(i>=vec.size())return 0;
    if(i==vec.size()-1)return vec[i][2];
    if(dp[i]!=-1)return dp[i];
    /// take ll
    unsigned long long op1_reward=vec[i][2];
    unsigned long long next=vec[i][1];
    long long j=i;
    j= upper_bound(vec.begin(),vec.end(),next,[&](ll val,const vector<ll>vec){
        return val<vec[0];
    }) -vec.begin();
    // while(j<vec.size() && vec[j][0]<=next)j++;
  
    unsigned long long op1=op1_reward + dfs(j,vec);
    /// dont take 
    unsigned long long op2=dfs(i+1,vec);
    return dp[i]=max(op1,op2);
}
void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> vec(n,vector<ll>(3,0));
    for(ll i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        vec[i]={a,b,c};
    }
    sort(all(vec));
   
    memset(dp,-1,sizeof(dp));
  
  
    unsigned long long ans=dfs(0,vec);
   
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
