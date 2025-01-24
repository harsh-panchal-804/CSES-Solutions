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
struct matrix{
    ll val[2][2];
    matrix friend operator*(const matrix &a ,const matrix &b){
        matrix c;
        for(ll  i=0;i<2;i++){
            for(ll  j=0;j<2;j++){
                c.val[i][j]=0;
                for(ll  k=0;k<2;k++){
                    c.val[i][j]+=a.val[i][k]*b.val[k][j];
                }
            }
        }
        return c;
    }
    matrix friend operator%(const matrix &a, ll  mod) {
        matrix res;
        for (ll  i = 0; i < 2; i++) {
            for (ll  j = 0; j < 2; j++) {
                res.val[i][j] = a.val[i][j] % mod;
            }
        }
        return res;
    }
    

};
matrix binPow(matrix& a,ll  b,ll  mod){
    matrix ans{{
        {1,0},
        {0,1}
    }};
    while(b){
        if(b&1){
            ans =(ans*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

void solve(){
    ll  n;
    cin>>n;
    matrix init {
        {
            {1,1},
            {1,0}
        }
    };
    matrix ans=binPow(init,n,mod);
    cout<<ans.val[0][1]<<'\n';

    
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
