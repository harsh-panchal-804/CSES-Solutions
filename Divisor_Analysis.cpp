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
const int MOD=1000000007; 
const int MOD1=1000000006;
long long int inverse(long long int i, long long int mod){
    if(i==1) return 1;
    return (mod - ((mod/i)*inverse(mod%i,mod))%mod+mod)%mod;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

void solve(){
    ll n;
    cin>>n;
    ll x[n],k[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>k[i];
    }
    ll num=1;
    for(int i=0;i<n;i++)
    {
        num*=(k[i]+1)%MOD;
        num%=MOD;
    }
    ll sum=1;
    for(int i=0;i<n;i++)
    {
        ll temp=(POW(x[i],k[i]+1)+MOD-1)%MOD;
        temp*=inverse(x[i]-1,MOD);
        temp%=MOD;
        sum*=temp;
        sum%=MOD;
    }
    ll prod,num1=1;
    ll flag=0;
    for(int i=0;i<n;i++)
    {
        if(k[i]%2==1 && flag==0)
        {
            num1*=((k[i]+1)/2);
            num1%=MOD1;
            flag=1;
        }
        else
        {
            num1*=(k[i]+1)%MOD1;
            num1%=MOD1;
        }
    }
    if(flag==0)
    {
        for(int i=0;i<n;i++)
        {
            k[i]/=2;
        }
    }
    ll number=1;
    for(int i=0;i<n;i++)
    {
        number*=POW(x[i],k[i]);
        number%=MOD;
    }
    prod=POW(number,num1);
    cout<<num<<" "<<sum<<" "<<prod;
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
