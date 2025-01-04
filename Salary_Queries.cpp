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

vector<int> buckets((int)1e7, 0);
map<int, int> sal_to_freq;

int bucket_no(int x) {
    return x / 100;
}

int calc(int low, int high, map<int, int>& sal_to_freq) {
    int ans = 0;
    auto it = sal_to_freq.lower_bound(low);
    while (it != sal_to_freq.end() && it->first <= high) {
        ans += it->second;
        it++;
    }
    return ans;
}
template <typename T, typename Combine = function<T(const T&, const T&)>>
class SegmentTree {
private:
    vector<T> tree;
    int n;
    T neutral;          // Neutral element for the combine operation
    Combine combine;    // The function to combine two elements

    void build(const vector<T>& arr) {
        for (int i = 0; i < n; ++i) {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
        }
    }

public:
    SegmentTree(const vector<T>& arr, T neutralElement, Combine combineFunc)
        : n(arr.size()), neutral(neutralElement), combine(combineFunc) {
        tree.resize(2 * n, neutral);
        build(arr);
    }

    void update(int idx, const T& value) {
        idx += n; // Move to the leaf
        tree[idx] = value;
        while (idx > 1) {
            idx /= 2;
            tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    T query(int l, int r) const {
        T leftResult = neutral, rightResult = neutral;
        l += n; // Move to the leaf
        r += n; // Move to the leaf
        while (l <= r) {
            if (l % 2 == 1) {
                leftResult = combine(leftResult, tree[l]);
                ++l;
            }
            if (r % 2 == 0) {
                rightResult = combine(tree[r], rightResult);
                --r;
            }
            l /= 2;
            r /= 2;
        }
        return combine(leftResult, rightResult);
    }
};
int sum(int x,int y) { return x+y; }
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> employee(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        employee[i] = x;
        buckets[bucket_no(x)]++;
        sal_to_freq[x]++;
    }
    SegmentTree<int> segtree(buckets, 0, sum);
    while (m--) {
        char c;
        cin >> c;
        if (c == '!') {
            int p, x;
            cin >> p >> x;
            int prev_salary = employee[p - 1];
            employee[p - 1] = x;
            int prev_bucket = bucket_no(prev_salary);
            int new_bucket = bucket_no(x);

            buckets[prev_bucket]--;
            if (buckets[prev_bucket] == 0) {
                segtree.update(prev_bucket, 0);
            } else {
                segtree.update(prev_bucket, buckets[prev_bucket]);
            }

            buckets[new_bucket]++;
            segtree.update(new_bucket, buckets[new_bucket]);

            sal_to_freq[prev_salary]--;
            if (sal_to_freq[prev_salary] == 0) {
                sal_to_freq.erase(prev_salary);
            }
            sal_to_freq[x]++;
        } else {
            int a, b;
            cin >> a >> b;
            int lbucket = bucket_no(a);
            int rbucket = bucket_no(b);

            int ans = calc(a, min(b, (lbucket + 1) * 100 - 1), sal_to_freq);

            if (lbucket != rbucket) {
                ans += calc(max(a, rbucket * 100), b, sal_to_freq);
            }

            if (lbucket + 1 <= rbucket - 1) {
                ans += segtree.query(lbucket + 1, rbucket - 1);
            }

            cout << ans << "\n";
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

    return 0;
}
