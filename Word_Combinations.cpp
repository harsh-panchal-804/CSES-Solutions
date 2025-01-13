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
class TrieNode{
    public:
    vector<TrieNode*> child;
    bool end;
    TrieNode(){
        child.resize(26,nullptr);
        end=false;
    }
};
class Trie{
    public:
    TrieNode* triee;
    Trie(){
        triee=new TrieNode();
    }
    void insert(string s){
        TrieNode* curr=triee;
        for(auto ch : s){
            if(curr->child[ch-'a']==nullptr){
                curr->child[ch-'a']=new TrieNode();
            }
            curr=curr->child[ch-'a'];
        }
        curr->end=true;
    }
};

void solve(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    Trie* trie=new Trie();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        trie->insert(s);
    }
    vector<int> dp(s.size()+1);
    int len=s.size();
    dp[s.size()]=1;
    for(int i=len-1;i>=0;i--){
        TrieNode* curr=trie->triee;
        for(int  j=i;j<len;j++){
            if(curr->child[s[j]-'a']==nullptr){
                break;
            }
            curr=curr->child[s[j]-'a'];
            if(curr->end==true){
                dp[i]=(dp[i]+dp[j+1])%mod;
            }

        }
    }
    debug(dp);
    cout<<dp[0]<<"\n";

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
