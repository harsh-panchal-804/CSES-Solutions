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
int cycle_start = -1;
int cycle_end = -1;
bool dfs(int node, vector<vector<int>> &graph, vector<int> &colors, vector<int>& parents, int par)
{
    colors[node] = 1;
    for (auto child : graph[node])
    {
        if (child == par)
            continue;
        if (colors[child] == 1)
        {
            cycle_end = node;
            cycle_start = child;
            return true;
        }
        parents[child] = node;
        if (dfs(child, graph, colors, parents, node))
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> parents(n + 1, -1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> colors(n + 1, 0);
    vector<int> cycle;
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == 0)
        {
            bool flag = dfs(i, graph, colors, parents, parents[i]);
            if (flag)
            {
                cycle.push_back(cycle_start);
                for (int v = cycle_end; v != cycle_start; v = parents[v])
                    cycle.push_back(v);
                cycle.push_back(cycle_start);
                // reverse(cycle.begin(), cycle.end());
                cout << cycle.size() << "\n";
                for (int v : cycle)
                    cout << v << " ";
                cout << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
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
