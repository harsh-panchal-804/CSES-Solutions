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
ll scc_id[(ll)3e5+100];
void dfs1(ll node,vector<vector<int>>& graph){
    visited[node]=1;
    for(auto child : graph[node]){
        if(!visited[child]){
            dfs1(child,graph);
        }
    }
    stk.push(node);
}
void dfs2(ll node,vector<vector<int>>& rgraph,vector<ll>& comps,ll scc_count){
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
    int n,m;
    cin>>n>>m;
    int x=n;
    vector<vector<int>> graph((int)3e5);
    vector<vector<int>> rgraph((int)3e5);
    while(x--){
        char f1, f2;
        int a, b;
        cin >> f1 >> a >> f2 >> b;
        int nodeA;
        if(f1 == '-'){
            nodeA = 2 * a + 1;
        }
        else {  
            nodeA = 2 * a;
        }
        int nodeB;
        if(f2 == '-'){
            nodeB = 2 * b + 1;
        }
        else { 
            nodeB = 2 * b;
        }
        int notA = nodeA ^ 1;  
        int notB = nodeB ^ 1;  
        graph[notA].push_back(nodeB); 
        graph[notB].push_back(nodeA);
        rgraph[nodeB].push_back(notA);
        rgraph[nodeA].push_back(notB);
    }
    visited.resize((int)3e5,0);
    for(ll i=2;i<(2*m+1);i++)if(!visited[i])dfs1(i,graph);
    fill(all(visited),0);
    ll scc_count=1;
    while(!stk.empty()){
        ll node=stk.top();
        stk.pop();
        if(visited[node])continue;
        vector<ll> comps;
        dfs2(node,rgraph,comps,scc_count++);
    }
    vector<int> tval((int)3e5);
    for(int i=1;i<=m;i++){
        if(scc_id[2*i]==scc_id[2*i +1]){
            cout<<"IMPOSSIBLE"<<"\n";
            return;
        }
        tval[i] = (scc_id[2*i] > scc_id[2*i +1]);
    }
     for (ll i = 1; i <= m; i++)
    {
        cout << ((tval[i]) ? '+' : '-') << " ";
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
