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
    ll vec[6][6];
    matrix friend operator*(const matrix & a,const matrix &b){
        matrix c;
        for(ll i=0;i<6;i++){
            for(ll j=0;j<6;j++){
                c.vec[i][j]=0;
                for(ll k=0;k<6;k++){
                    c.vec[i][j] = (c.vec[i][j] + (1LL * a.vec[i][k] * b.vec[k][j]) % mod) % mod;

                }
            }
        }
        return c;
    }
    matrix friend operator%(const matrix & a,ll mod){
        matrix c;
        for(ll i=0;i<6;i++){
            for(ll j=0;j<6;j++){
                c.vec[i][j]=a.vec[i][j]%mod;
                
            }
        }
        return c;
    }
};
matrix binPow(matrix & a,ll b,ll mod){
    matrix init;
    for(ll i=0;i<6;i++){
        for(ll j=0;j<6;j++){
            if(i==j){
                init.vec[i][j]=1;
            }
            else{
                init.vec[i][j]=0;
            }
        }
    }
    while(b){
        if(b&1){
            init =(init * a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return init;
}



void solve(){
    ll n;
    cin>>n;
    matrix init;
    for (ll i = 0; i < 6; i++) {
        for (ll j = 0; j < 6; j++) {
            init.vec[i][j] = 0;
        }
    }
    for(ll i=0;i<5;i++)
    {
        init.vec[i][i+1]=1;
    }
    for(ll i=0;i<6;i++)
    {
        init.vec[5][i]=1;
    }
    cout<<binPow(init,n,mod).vec[5][5]<<"\n";

    
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
