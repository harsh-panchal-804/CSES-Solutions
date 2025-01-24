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

vector<int> sieve(int n) {
    vector<bool> vec(n + 1, true);
    vec[0] = vec[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (vec[i]) {
            for (int j = i * i; j <= n; j += i) {
                vec[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (vec[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

int calc(int x, const vector<int>& primes) {
    unordered_map<int, int> mp;
    for (auto p : primes) {
        if (p * p > x) break;
        while (x % p == 0) {
            mp[p]++;
            x /= p;
        }
    }
    if (x > 1) {
        mp[x]++;
    }
    int ans = 1;
    for (auto i : mp) {
        ans *= (i.second + 1);
    }
    return ans;
}

void solve(const vector<int>& primes) {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << calc(a, primes) << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    const int MAX_LIMIT = 1e5;
    vector<int> primes = sieve(MAX_LIMIT);
    int test = 1;
    // cin >> test;
    while (test--) {
        solve(primes);
    }
    return 0;
}
