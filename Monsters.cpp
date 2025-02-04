#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
char moveDir[] = {'U', 'D', 'L', 'R'};

bool isSafe(ll x, ll y, ll n, ll m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

char getDirection(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second + 1 == b.second) return 'R';
    if (a.second - 1 == b.second) return 'L';
    if (a.first - 1 == b.first) return 'U';
    return 'D';
}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) {
        cin >> grid[i];
    }

    queue<pair<ll, ll>> monsterQueue;
    vector<vector<ll>> monsterDist(n, vector<ll>(m, INF));
    vector<vector<bool>> monsterVis(n, vector<bool>(m, false));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterQueue.push({i, j});
                monsterDist[i][j] = 0;
                monsterVis[i][j] = true;
            }
        }
    }

    while (!monsterQueue.empty()) {
        pair<ll, ll> cell = monsterQueue.front();
        ll x = cell.first, y = cell.second;
        monsterQueue.pop();

        for (ll i = 0; i < 4; i++) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (isSafe(nx, ny, n, m) && grid[nx][ny] != '#' && !monsterVis[nx][ny]) {
                monsterDist[nx][ny] = monsterDist[x][y] + 1;
                monsterVis[nx][ny] = true;
                monsterQueue.push({nx, ny});
            }
        }
    }

    // BFS for 'A' (Player)
    queue<pair<ll, ll>> playerQueue;
    vector<vector<ll>> playerDist(n, vector<ll>(m, INF));
    vector<vector<bool>> playerVis(n, vector<bool>(m, false));
    map<pair<ll, ll>, pair<ll, ll>> parent;

    pair<ll, ll> startPos;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                startPos = {i, j};
                playerQueue.push(startPos);
                playerDist[i][j] = 0;
                playerVis[i][j] = true;
                parent[startPos] = startPos;
            }
        }
    }

    while (!playerQueue.empty()) {
        pair<ll, ll> cell = playerQueue.front();
        ll x = cell.first, y = cell.second;
        playerQueue.pop();

        for (ll i = 0; i < 4; i++) {
            ll nx = x + dx[i], ny = y + dy[i];

            if (isSafe(nx, ny, n, m) && grid[nx][ny] != '#' && !playerVis[nx][ny]) {
                if (playerDist[x][y] + 1 < monsterDist[nx][ny]) {
                    playerDist[nx][ny] = playerDist[x][y] + 1;
                    playerVis[nx][ny] = true;
                    parent[{nx, ny}] = {x, y};
                    playerQueue.push({nx, ny});
                }
            }
        }
    }

   
    vector<pair<ll, ll>> path;
    bool found = false;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] != '#' && playerDist[i][j] < monsterDist[i][j]) {
                pair<ll, ll> curr = {i, j};
                while (parent[curr] != curr) {
                    path.push_back(curr);
                    curr = parent[curr];
                }
                path.push_back(curr);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "YES\n" << path.size() - 1 << "\n";
        reverse(path.begin(), path.end());
        for (ll i = 0; i < path.size() - 1; i++) {
            cout << getDirection(path[i], path[i + 1]);
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
