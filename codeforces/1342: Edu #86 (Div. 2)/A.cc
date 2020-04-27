#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll res = a*(abs(x) + abs(y));
    if((x > 0) == (y > 0)) {
        ll diff = abs(x - y);
        ckmin(res, a*diff + b*(max(abs(x), abs(y)) - diff));
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

