// this line is here for a reason
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, a, b;
    cin >> n;

    vector<pair<double, int>> d(n);
    F0R(i, n) {
        cin >> a >> b;
        d[i].fi = a/(double)b;
        d[i].se = i + 1;
    }

    sort(ALL(d));

    ll days = 1;
    F0R(i, n) {
        cout << d[i].se << " \n"[i == n - 1];
        days += d[i].fi;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
        if(tc)
            cout << endl;
    }
}
