#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6;

vector<long long> factorial(MAX + 1), inv_factorial(MAX + 1);

// Function to calculate modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and modular inverses
void precompute() {
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    inv_factorial[MAX] = mod_exp(factorial[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; i--) {
        inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % MOD;
    }
}

// Function to calculate C(n, k)
long long binomial_coefficient(int n, int k) {
    if (k > n) return 0;
    return (factorial[n] * inv_factorial[k] % MOD * inv_factorial[n - k] % MOD) % MOD;
}

int main() {
    precompute();

    int queries;
    cin >> queries;
    while (queries--) {
        int n, k;
        cin >> n >> k;
        cout << binomial_coefficient(n, k) << endl;
    }

    return 0;
}
