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

void dfs(int node,vector<int>&depth,vector<vector<int>>& graph,int prev=-1){
    for(auto child: graph[node]){
        if(child==prev)continue;
        depth[child]=depth[node]+1;
        dfs(child,depth,graph,node);
    }
}



void solve(){
    int n,q;
    cin>>n>>q;
    int LOG=ceil(log2(n))+1;
    vector<int> parent(n+1);
    vector<vector<int>> up(n+1,vector<int>(LOG));
    vector<int> depth(n+1,0);
    vector<vector<int>> graph(n+1);
    parent[1]=1;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        graph[i].push_back(a);
        graph[a].push_back(i);
        parent[i]=a;
    }
    dfs(1,depth,graph);
    for(int i=1;i<=n;i++){
        up[i][0]=parent[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            up[i][j]= up.at(up[i][j-1]).at(j-1);
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        if(depth[x]<k){
            cout<<-1<<"\n";
            continue;
        }
        else{
            int ans=x;
            for(int i=0;i<LOG;i++){
                if((1<<i) & k){
                    ans=up[ans][i];
                }
            }
            cout<<ans<<"\n";
        }
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
