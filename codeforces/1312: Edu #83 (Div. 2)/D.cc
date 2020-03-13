#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

const ll M = 998244353LL;

ll inv(ll a) {
    ll b = M - 2;
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    ll res = 1;
    F0R(i, k)
        res = res * (n - i) % M;
    FOR(i, 1, k + 1)
        res = res * inv(i) % M;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    ll res = 1;
    F0R(i, n - 3)
        res = res * 2 % M;
    res = res * (n - 2) % M;
    res = res * C(m, n - 1) % M;
    cout << res << endl;
}



