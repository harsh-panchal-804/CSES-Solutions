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
int dp[(int)2e5+100];
int dfs(vector<pair<int,int>> &a ,int i){
    if(i>=a.size()){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
  
    auto next = lower_bound(a.begin(), a.end(), make_pair(a[i].second, INT_MIN)) - a.begin();
    int op1=1+ dfs(a,next);
    int op2=dfs(a,i+1);
    return dp[i]=max(op1,op2);
}



void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec[i]={a,b};
    }
    sort(all(vec),[&](pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first)return a.first<b.first;
        else a.second<b.second;
    });
    memset(dp,-1,sizeof(dp));
    int ans=dfs(vec,0);
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
