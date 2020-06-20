#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    vi even, odd;
    F0R(i, 2*n) {
        int k;
        cin >> k;

        if(k & 1) odd.pb(i+1);
        else even.pb(i+1);
    }

    vii res;
    for(int i = 0; i + 1 < SZ(odd); i += 2)
        res.eb(odd[i], odd[i + 1]);

    for(int i = 0; i + 1 < SZ(even); i += 2)
        res.eb(even[i], even[i + 1]);

    F0R(i, n - 1)
        cout << res[i].fi << ' ' << res[i].se << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

