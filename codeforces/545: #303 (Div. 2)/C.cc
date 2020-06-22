#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    vii a(n);
    F0R(i, n) cin >> a[i].fi >> a[i].se;

    int cnt = min(2, n);
    ll l = a[0].fi, r;
    FOR(i, 1, n - 1) {
        r = a[i + 1].fi;

        auto [x, h] = a[i];
        if(x - h > l) {
            cnt++;
            l = x;
        } else if(x + h < r) {
            cnt++;
            l = x + h;
        } else
            l = x;
    }

    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    while(tc--)
        solve();
}
