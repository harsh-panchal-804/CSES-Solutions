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
    vector<vector<pair<ll,ll>>>graph(n+1);
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    vector<vector<ll>> dis(n+1,vector<ll>(2,LONG_LONG_MAX));
    dis[1][0]=0;
    dis[1][1]=0;
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    pq.push({0,1,1});
    while(!pq.empty()){
        ll dist=pq.top()[0];
        ll node=pq.top()[1];
        ll available=pq.top()[2];
        pq.pop();
        if(dis[node][available] < dist )continue;
        for(auto & child : graph[node]){
            ll child_dist=child.first;
            ll child_node=child.second;
            if(available==0){
                if(dist + child_dist <dis[child_node][0]){
                    dis[child_node][0]=dist + child_dist;
                    pq.push({dis[child_node][0],child_node,0});
                }
            }   
            else{
                if(dist + child_dist <dis[child_node][1]){
                    dis[child_node][1]=dist + child_dist;
                    pq.push({dis[child_node][1],child_node,1});
                }
                if(dist+child_dist/2 <dis[child_node][0]){
                    dis[child_node][0]=dist+child_dist/2 ;
                    pq.push({dis[child_node][0],child_node,0});
                }
            }
        }
    }
    cout<<min(dis[n][0],dis[n][1])<<"\n";
    
    
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
