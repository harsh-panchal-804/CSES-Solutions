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

/// up->1 down->-1 left->-2 right->2  
vector<vector<int>> dirs = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> vec(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, 0));

    int startX, startY;
    int endX = -1, endY = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            if (vec[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    function<void(int, int)> bfs = [&](int a, int b) {
        queue<pair<int, int>> queue;
        queue.push({a, b});
        visited[a][b] = true;

        while (!queue.empty()) {
            int x = queue.front().first;
            int y = queue.front().second;
            queue.pop();

            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                char move = dir[2];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && (vec[nx][ny] == '.' || vec[nx][ny] == 'B')) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    direction[nx][ny] = move;
                    queue.push({nx, ny});

                    if (vec[nx][ny] == 'B') {
                        
                        string path;
                        while (nx != a || ny != b) {
                            path += direction[nx][ny];
                            tie(nx, ny) = parent[nx][ny];
                        }
                        reverse(path.begin(), path.end());
                        cout << "YES\n" << path.size() << "\n" << path << "\n";
                        return;
                    }
                }
            }
        }
        cout << "NO\n";
    };

    bfs(startX, startY);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test = 1;
    while (test--) {
        solve();
    }
    
    return 0;
}
