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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T> 
using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    oset<pair<int,int>> oset;
    for(int i=0;i<n;i++)cin>>vec[i];
    for(int i=0;i<k;i++){
        oset.insert({vec[i],i});
    }
    // for(auto i : oset)cout<<i.first;
    // cout<<"\n";
    cout<<(*oset.find_by_order((k-1)/2)).first<<' ';
    // oset.erase(*oset.find_by_order(k/2));
    for(int i=1;i<n-k+1;i++){
        oset.erase(oset.find({vec[i-1],i-1}));
        oset.insert({vec[i+k-1],i+k-1});
        // for(auto i : oset)cout<<i.first;
        // cout<<"\n";
        cout<<(*oset.find_by_order((k-1)/2)).first <<" ";
    }
    cout<<"\n";
}
//// 1 1 2 3

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
