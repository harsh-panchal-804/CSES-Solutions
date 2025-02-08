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
stack<int> stk;
vector<int> visited;



void dfs1(int node,vector<vector<int>>& graph){
    visited[node]=1;
    for(auto child: graph[node]){
        if(!visited[child]){
            dfs1(child,graph);
        }
    }
    stk.push(node);
}
void dfs2(int node,vector<vector<int>>& graph){
    visited[node] = 1;
    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs2(child, graph);
        }
    }
}




void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> rgraph(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
    visited.resize(n+1,0);
    for(int i=1;i<=n;i++)if(!visited[i])dfs1(i,graph);
    fill(all(visited), 0);
    vector<int> ans;
    int count=0;
    while(!stk.empty()){
        int node=stk.top();
        stk.pop();
        if(visited[node])continue;
        ans.push_back(node);
        count++;
        dfs2(node,rgraph);
        
    }
    if(ans.size()==1){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
        cout<<ans[1] <<" "<<ans[0]<<'\n';
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
