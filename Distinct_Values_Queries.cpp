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
int arr[(int)2e5+100];
int freq[(int)2e5+100];
int block_size;
struct Query{
    int l,r,idx;
    bool operator<(const Query&b)const{
        if(l/block_size !=  b.l /block_size){
            return l/block_size < b.l/block_size;
        }
        else{
            return r <b.r;
        }
    }
};
int curr_ans=0;
void add(int element){
    freq[element]++;
    if(freq[element]>1)return;
    if(freq[element]==1)curr_ans++;
}
void remove(int element){
    freq[element]--;
    if(!freq[element])curr_ans--;
}


void solve(){
    int n,q;
    cin>>n>>q;
    block_size=sqrt(n);
    int compressedNum=1;
    map<int,int> compress_map;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(compress_map.find(arr[i])!=compress_map.end()){
            arr[i]=compress_map[arr[i]];
        }
        else{
            compress_map[arr[i]]=compressedNum;
            arr[i]=compressedNum;
            compressedNum++;
        }
    }
    vector<Query> queries(q);
    vector<int>ans(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        queries[i].l = a-1;
        queries[i].r = b-1;
        queries[i].idx =i;
    }
    sort(all(queries));
    int curr_l=0;
    int curr_r=-1;
    for(auto q : queries){
        int l=q.l;
        int r=q.r;
        int idx=q.idx;
        while(curr_r<r){
            curr_r++;
            add(arr[curr_r]);
        }
        while(curr_l >l){
            curr_l--;
            add(arr[curr_l]);
        }
        while(curr_l <l){
            remove(arr[curr_l]);
            curr_l++;
        }
        while(curr_r > r){
            remove(arr[curr_r]);
            curr_r--;
        }
        ans[idx]=curr_ans;
    }
    for(auto i : ans){
        cout<<i<<"\n";
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
