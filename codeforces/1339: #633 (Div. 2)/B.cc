#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)

void solve() {
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) cin >> a[i];

    sort(ALL(a));

    vi res;
    for(int l = 0, r = n - 1; l <= r; ) {
        res.pb(a[l++]);
        if(l <= r)
            res.pb(a[r--]);
    }
    R0F(i, n - 1)
        cout << res[i] << " \n"[!i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

