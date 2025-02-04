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

struct range{
    int l,r,idx;
    bool operator<(const range& other){
        if(l==other.l){
            return r>other.r;
        }
        return l<other.l;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<range> ranges(n);
    vector<int> contains(n);
    vector<int> contained(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        range rn;
        rn.l=a;
        rn.r=b;
        rn.idx=i;
        ranges[i]=rn;
    }
    int mx=INT_MIN;
    sort(all(ranges));
    for(int i=0;i<n;i++){
        if( ranges[i].r<=mx){
            contained[ranges[i].idx]=1;
        }
        mx=max(mx,ranges[i].r);
    }
    int mn=INT_MAX;
    for(int i= n-1;i>=0;i--){
        if(ranges[i].r>=mn){
            contains[ranges[i].idx]=1;
        }
        mn=min(mn,ranges[i].r);
    }
    for(auto i : contains){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(auto i : contained){
        cout<<i<<" ";
    }
    cout<<"\n";
    
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
