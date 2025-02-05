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
stack<ll> stk;
vector<ll> visited;
ll scc_id[(ll)1e5+100];
void dfs1(ll node,vector<vector<ll>>& graph){
    visited[node]=1;
    for(auto child : graph[node]){
        if(!visited[child]){
            dfs1(child,graph);
        }
    }
    stk.push(node);
}
void dfs2(ll node,vector<vector<ll>>& rgraph,vector<ll>& comps,ll scc_count){
    visited[node]=1;
    scc_id[node]=scc_count;
    comps.push_back(node);
    for(auto child: rgraph[node]){
        if(!visited[child]){
            dfs2(child,rgraph,comps,scc_count);
        }
    }
}



void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> coins(n+1);
    for(ll i=1;i<=n;i++)cin>>coins[i];
    vector<vector<ll>> graph(n+1);
    vector<vector<ll>> rgraph(n+1);
    while(m--){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);    
    }
    visited.resize(n+1,0);
    for(ll i=1;i<=n;i++)if(!visited[i])dfs1(i,graph);
    fill(all(visited),0);
    ll scc_count=1;
    while(!stk.empty()){
        ll node=stk.top();
        stk.pop();
        if(visited[node])continue;
        vector<ll> comps;
        dfs2(node,rgraph,comps,scc_count++);
    }
    vector<vector<ll>> dag(scc_count+1);
     queue<ll> queue;
    vector<ll> indegree(n+1,0);
    for(ll i=1;i<=n;i++){
        for(auto u : graph[i]){
            if(scc_id[i]!=scc_id[u]){
                dag[scc_id[i]].push_back(scc_id[u]);
                indegree[scc_id[u]]++;
            }
        }
    }
    vector<ll> scc_coins(scc_count+1);
    for(ll i=1;i<=n;i++){
        scc_coins[scc_id[i]] +=coins[i];
    }
    for(ll i=1;i<=scc_count;i++){
        if(indegree[i]==0)queue.push(i);
    }
    vector<ll> topo;
    while(!queue.empty()){
        ll node=queue.front();
        queue.pop();
        topo.push_back(node);
        for(auto child : dag[node]){
            indegree[child]--;
            if(indegree[child]==0)queue.push(child);
        }
    }
    vector<ll> dp(scc_count+1);
    for(ll node : topo){
        dp[node]=max(dp[node],scc_coins[node]);
        for(auto child : dag[node]){
            dp[child]=max(dp[child],dp[node] +scc_coins[child]);
        }
    }
    ll ans=*max_element(all(dp));
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
