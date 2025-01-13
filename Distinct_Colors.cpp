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
int n,q;
int values[(int)2e5+100];
vector<int> graph[(int)2e5+100];
vector<int> start((int)2e5+100);
vector<int> finish((int)2e5+100);
vector<int> euler;
void dfs(int node,int prev=-1){
    start[node]=euler.size();
    euler.push_back(values[node]);
    for(auto child: graph[node]){
        if(child==prev)continue;
        dfs(child,node);
    }
    finish[node]=euler.size();
    euler.push_back(values[node]);
}
int block_size;
struct Query{
    int l,r,idx;
    bool operator<(const  Query&  b)const{
        if(l/block_size != b.l /block_size){
            return l/block_size < b.l/block_size;
        }
        else{
            return r < b.r;
        }

    }
};
int curr_ans;
int freq[(int)2e5+100];
void add(int x){
    if(!freq[x])curr_ans++;
    freq[x]++;
}
void remove(int x){
    freq[x]--;
    if(!freq[x])curr_ans--;
}

void solve(){
    cin>>n;
    block_size=sqrt(n);
    map<int,int> mp;
    int comp_num=1;
    for(int i=1;i<=n;i++){
        cin>>values[i];
        if(mp.find(values[i])!=mp.end()){
            values[i]=mp[values[i]];
        }else{
            mp[values[i]]=comp_num;
            values[i]=comp_num;
            comp_num++;
        }
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    // debug(euler)
    // debug(start)
    // debug(finish)
    vector<Query> queries(n);
    for(int i=0;i<n;i++){
        queries[i].l=start[i+1];
        queries[i].r=finish[i+1];
        queries[i].idx=i;
    }
    sort(all(queries));
    int curr_l=0;
    int curr_r=-1;
    vector<int> ans(n);
    for(auto q : queries){
        int l=q.l;
        int r=q.r;
        int idx=q.idx;
        while(curr_r<r){
            curr_r++;
            add(euler[curr_r]);
        }
        while(curr_l >l){
            curr_l--;
            add(euler[curr_l]);
        }
        while(curr_l <l){
            remove(euler[curr_l]);
            curr_l++;
        }
        while(curr_r > r){
            remove(euler[curr_r]);
            curr_r--;
        }
        ans[idx]=curr_ans;
    }
    for(auto i : ans){
        cout<<i<<' ';
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
