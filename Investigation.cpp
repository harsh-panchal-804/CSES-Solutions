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
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> graph(n+1);
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<pair<ll,ll>>> pq;
    vector<ll> dist(n+1,LONG_LONG_MAX);
    vector<ll> ways(n+1,0);
    vector<ll> minc(n+1,0);
    vector<ll> maxc(n+1,0);
    dist[1]=0;
    ways[1]=1;
    minc[1]=1;
    maxc[1]=1;
    pq.push({0,1});
    while(!pq.empty()){
        ll par_node=pq.top().second;
        ll par_dist=pq.top().first;
        pq.pop();
        if(par_dist> dist[par_node])continue;
        for(auto child : graph[par_node]){
            ll child_dist=child.first;
            ll child_node=child.second;
            if(par_dist + child_dist <dist[child_node]){
                dist[child_node]=par_dist+ child_dist;
                ways[child_node]=ways[par_node];
                minc[child_node]=minc[par_node]+1;
                maxc[child_node]=maxc[par_node]+1;
                pq.push({dist[child_node],child_node});
            }
            else if(par_dist + child_dist == dist[child_node]){
                ways[child_node]=(ways[child_node]+ways[par_node])%mod;
                minc[child_node]=min(minc[child_node],minc[par_node]+1);
                maxc[child_node]=max(maxc[child_node],maxc[par_node]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<minc[n]-1<<" "<<maxc[n]-1<<"\n";
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
