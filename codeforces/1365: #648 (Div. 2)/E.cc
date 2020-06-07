#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    F0R(i, n) cin >> a[i];

    ll best = 0;
    F0R(x, n) F0R(y, n) F0R(z, n) ckmax(best, a[x] | a[y] | a[z]);
    cout << best << endl;

    return 0;
}


