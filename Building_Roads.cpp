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
    for(int i=1;i<=n;i++){
        make(i);
    }

    while(m--){
        int a ,b;
        cin>>a>>b;
        Union(a,b);
    }
    vector<int> comps;
    for(int i=1;i<=n;i++){
        if(parent[i]==i)comps.push_back(i);
    }
    cout<<comps.size()-1<<"\n";
    for(int i=1;i<comps.size();i++){
        cout<<comps[0]<<" "<<comps[i]<<'\n';
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
