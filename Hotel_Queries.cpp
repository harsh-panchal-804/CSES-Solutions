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
template <typename T, typename Combine = function<T(const T&, const T&)>>
class SegmentTree {
private:
    vector<T> tree;
    int n;
    T neutral;          // Neutral element for the combine operation
    Combine combine;    // The function to combine two elements

    void build(const vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            build(arr, leftChild, start, mid);
            build(arr, rightChild, mid + 1, end);
            tree[node] = combine(tree[leftChild], tree[rightChild]);
        }
    }

    void update(int node, int start, int end, int idx, const T& value) {
        if (start == end) {
            tree[node] -= value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if (idx <= mid) {
                update(leftChild, start, mid, idx, value);
            } else {
                update(rightChild, mid + 1, end, idx, value);
            }
            tree[node] = combine(tree[leftChild], tree[rightChild]);
        }
    }

    T query(int node,int l,int r ,T req) const {
        if(tree[node]<req)return neutral;
        if(l==r){
            return l;
        }
        int mid=(l+r)/2;
        if(tree[2*node+1]>=req){
            return query(2*node+1,l,mid,req);
        }
        else{
            return query(2*node+2,mid+1,r,req);
        }

    }

public:
    SegmentTree(const vector<T>& arr, T neutralElement, Combine combineFunc)
        : n(arr.size()), neutral(neutralElement), combine(combineFunc) {
        tree.resize(4 * n);
        build(arr, 1, 1, n);
    }

    void update(int idx, const T& value) {
        update(1, 1, n , idx, value);
    }

    T query(T req) const {
        return query(1, 1, n ,req);
    }
};




void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> vec(n + 1); 
    for (int i = 1; i <= n; i++) cin >> vec[i];
    SegmentTree<int> tree(vec,0,[&](int a,int b){
        return max(a,b);
    });
    while(m--){
        int req;
        cin>>req;
        int ind=tree.query(req);
        cout<<ind<<" ";
        if(ind !=0){
            tree.update(ind,req);
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
