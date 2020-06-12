#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

void solve() {
    ll n, x, m;
    cin >> n >> x >> m;

    ll bestL = x;
    ll bestR = x;

    F0R(_, m) {
        ll l, r;
        cin >> l >> r;

        if((bestL <= r && bestL >= l) || (bestR <= r && bestR >= l)) {
            ckmin(bestL, l);
            ckmax(bestR, r);
        }

    }

    cout << bestR - bestL + 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

