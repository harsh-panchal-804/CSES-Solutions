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
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
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

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);

template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
vector<vector<int>> graph;
vector<int> depth;
vector<int> parent;
void dfs(int node, int prev = -1)
{
    for (auto child : graph[node])
    {
        if (child == prev)
            continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}
void dfs2(int node, int prev = -1)
{
    for (auto child : graph[node])
    {
        if (child == prev)
            continue;
        parent[child] = node;
        dfs2(child, node);
    }
}
int dfs3(int node, vector<vector<int>> &graph, vector<int> &prefix, int prev = -1)
{
    int ans=prefix[node];
    for(auto child: graph[node]){
        if(child==prev)continue;
        ans += dfs3(child,graph,prefix,node);
    }
    prefix[node]=ans;
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    int LOG = ceil(log2(n)) + 1;
    depth.resize(n + 1, 0);
    vector<vector<int>> up(n + 1, vector<int>(LOG, -1));
    parent.resize(n + 1);
    parent[1] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> prefix(n + 1, 0);

    
    dfs(1);
    dfs2(1);

  
    for (int i = 1; i <= n; i++)
    {
        up[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (up[i][j - 1] != -1)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

   
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int x = a, y = b;

        
        if (depth[a] < depth[b])
            swap(a, b);

      
        int k = depth[a] - depth[b];
        for (int i = 0; i < LOG; i++)
        {
            if ((1 << i) & k)
            {
                a = up[a][i];
            }
        }

       
        if (a != b)
        {
            for (int i = LOG - 1; i >= 0; i--)
            {
                if (up[a][i] != -1 && up[a][i] != up[b][i])
                {
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            a = up[a][0]; 
        }

        int lca = a;

        
        prefix[x]++;
        prefix[y]++;
        prefix[lca]--;
        if (parent[lca] != -1)
        {
            prefix[parent[lca]]--;
        }
    }

   
    dfs3(1, graph, prefix, -1);

    for (int i = 1; i <= n; i++)
    {
        cout << prefix[i] << " ";
    }
    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }

    return 0;
}
