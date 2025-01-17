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
vector<int> vec;
int bs(int x){
    if(vec[0]>x)return -1;
    int l=0;
    int r=vec.size()-1;
    int ans=-1;
    while(l<=r){
        int mid= (l+r)/2;
        if(vec[mid]>x){
            r=mid-1;
        }
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> cust(m);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.insert(x); 
    }
    for (int i = 0; i < m; i++) cin >> cust[i];

    for (auto c : cust) {
        auto it = tickets.upper_bound(c); 
        if (it == tickets.begin()) {     
            cout << -1 << "\n";
        } else {
            --it;                         
            cout << *it << "\n";
            tickets.erase(it);            
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
