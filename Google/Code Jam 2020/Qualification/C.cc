#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {

    int n;
    cin >> n;

    vii times(n);
    F0R (i, n)
        cin >> times[i].fi >> times[i].se;

    vi ind(n);
    iota(ALL(ind), 0);

    sort(ALL(ind), [&](int& a, int& b) { return times[a] < times[b]; });
    sort(ALL(times));

    int jTill = -1;
    int cTill = -1;
    string res(n, '?');
    F0R(i, n) {
        int from = times[i].fi;
        int to = times[i].se;
        if(cTill <= from) {
            res[ind[i]] = 'C';
            cTill = to;
            continue;
        }
        if(jTill <= from) {
            res[ind[i]] = 'J';
            jTill = to;
            continue;
        }
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << res << endl;
}

int main() {
    int tcc;
    cin >> tcc;

    FOR (tc, 1, tcc + 1) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

