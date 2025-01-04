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

class FenwickTree {
    vector<long long> bit;
    int n;

public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long prefix_sum(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

void range_add(FenwickTree &BIT1, FenwickTree &BIT2, int l, int r, long long x) {
    BIT1.add(l, x);
    BIT1.add(r + 1, -x);
    BIT2.add(l, x * (l - 1));
    BIT2.add(r + 1, -x * r);
}

long long point_query(FenwickTree &BIT1, FenwickTree &BIT2, int idx) {
    return BIT1.prefix_sum(idx) * idx - BIT2.prefix_sum(idx);
}

void solve(){
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    FenwickTree BIT1(n), BIT2(n);

    // Initialize BIT with the array values
    for (int i = 1; i <= n; i++) {
        range_add(BIT1, BIT2, i, i, arr[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Range Update: Add x to range [l, r]
            int l, r, x;
            cin >> l >> r >> x;
            range_add(BIT1, BIT2, l, r, x);
        } else if (type == 2) {
            // Point Query: Get value at position k
            int k;
            cin >> k;
            cout << point_query(BIT1, BIT2, k) << "\n";
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
