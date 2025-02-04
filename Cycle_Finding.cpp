#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll INF = 1e18;
 
struct Edge {
    int u, v;
    ll w;
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    // Instead of setting one source to 0 and the rest to INF,
    // we set all distances to 0. This way every vertex is “reachable”
    // and a negative cycle anywhere in the graph can be detected.
    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    
    int cycleStart = -1;
    
    // Relax all edges n times.
    // If on the nth iteration an edge can be relaxed, there is a negative cycle.
    for (int i = 0; i < n; i++){
        cycleStart = -1;
        for (auto &e : edges){
            if (dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                cycleStart = e.v;  // Mark the last vertex relaxed
            }
        }
    }
    
    if (cycleStart == -1) {
        cout << "NO\n";
    } else {
        // To ensure that we get a vertex on the negative cycle,
        // follow parent pointers n times.
        int y = cycleStart;
        for (int i = 0; i < n; i++){
            y = parent[y];
        }
        
        // Now, reconstruct the cycle starting from y.
        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            // Once we see y again (and the cycle has at least one edge), break.
            if (cur == y && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        
        cout << "YES" << "\n";
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test = 1;
    // For CSES problems, test = 1 is typical.
    while(test--){
         solve();
    }
    
    return 0;
}
