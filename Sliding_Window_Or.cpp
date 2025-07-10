#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    // 1) Build the array 'vec'
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) {
        vec[i] = x;
        x = (a * x + b) % c;
    }

    // 2) Prepare prefix and suffix OR arrays in blocks of size k
    vector<ll> pref(n), suff(n);
    for (ll block_start = 0; block_start < n; block_start += k) {
        ll block_end = min(block_start + k - 1, n - 1);
        // compute prefix OR within block
        pref[block_start] = vec[block_start];
        for (ll i = block_start + 1; i <= block_end; i++) {
            pref[i] = pref[i - 1] | vec[i];
        }
        // compute suffix OR within block
        suff[block_end] = vec[block_end];
        for (ll i = block_end - 1; i >= block_start; i--) {
            suff[i] = suff[i + 1] | vec[i];
        }
    }

    // 3) Slide window and XOR the OR of each window
    ll result = 0;
    // windows [i-k+1 .. i] for i from k-1 to n-1
    for (ll i = k - 1; i < n; i++) {
        // OR of window = pref[i] | suff[i - k + 1]
        ll window_or = pref[i] | suff[i - k + 1];
        result ^= window_or;
    }

    cout << result << '\n';
}

int main() {
    solve();
    return 0;
}
