#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
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

    vii a(n);
    F0R(i, n) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(ALL(a));

    int l = a[0].se,
        r = l == n - 1 ? n - 1 : n,
        leftStart = l;
    FOR(i, 1, n) {
        if(l < r) {
            if(a[i].se != l + 1) {
                cout << "No\n";
                return;
            }

            l++;
            if(l >= r - 1) {
                r = leftStart;
                l = leftStart;
            }
        } else {
            if(a[i].se == r - 1) {
                r--;
            } else {
                leftStart = a[i].se;
                l = a[i].se;
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

