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
class Manacher{
    public:
    vector<int> p;
    void build(string s){
        string t="";
        t+='#';
        for(auto ch : s){
            t+="#";
            t+=ch;
        }
        t+='#';
        run_manacher(t);
    }
    void run_manacher(string s){
        int l=1;
        int r=1;
        int n=s.size();
        p.resize(n,1);
        for(int i=1;i<n;i++){
            p[i]=max(0,min(r-i,p[r+l-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i-p[i]]==s[i+p[i]])p[i]++;
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
    }
    int get_longest(int centre,int odd){
        int index=2*centre+1 +!odd;
        return p[index]-1;
    }
    bool check_pal(int l,int r,int odd){
        if(get_longest((l+r)/2,l%2==r%2)>=r-l+1)return true;
        else return false;
    }

};



void solve(){
    string s;
    cin >> s;

    Manacher man;
    man.build(s);

    int n = s.size();
    int max_len = 0;
    int start = 0;    

    
    for (int i = 0; i < n; i++) {
        int odd_len = man.get_longest(i, true);
        int even_len = man.get_longest(i, false);

        if (odd_len > max_len) {
            max_len = odd_len;
            start = i ;
        }
        if (even_len > max_len) {
            max_len = even_len;
            start = i ;
        }
    }
    if(max_len&1){
        cout << s.substr(start-max_len/2, max_len) << "\n";
    }
    else{
        cout << s.substr(start-max_len/2 , max_len) << "\n";
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
