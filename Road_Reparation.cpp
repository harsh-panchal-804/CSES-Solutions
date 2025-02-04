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
    vector<pair<ll,pair<ll,ll>>> vec;
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        vec.push_back({c,{a,b}});
    }

    vector<ll> parent(n+1);
    vector<ll> size(n+1,0);
    auto make=[&](ll a){
        parent[a]=a;
        size[a]=1;
    };
    function<ll(ll)> find=[&](ll node){
        if(parent[node]==node)return node;
        return parent[node]=find(parent[node]);
    };

    function<void(ll,ll)>Union=[&](ll a,ll b){
        a=find(a);
        b=find(b);
        if(a==b){
            return;
        }
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    };

    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq(all(vec));
    ll edges=0;
    ll ans=0;
    for(ll i=1;i<=n;i++)make(i);
    while(!pq.empty() && edges <n-1){
        ll cost=pq.top().first;
        ll a =pq.top().second.first;
        ll b=pq.top().second.second;
        pq.pop();
        if(find(a)==find(b))continue;
        ans += cost;
        edges++;
        Union(a,b);
    }
    if(edges!=n-1){
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        cout<<ans<<'\n';
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
