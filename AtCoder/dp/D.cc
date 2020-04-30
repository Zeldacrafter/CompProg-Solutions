#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

const ll ninf = -1e17;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, w;
    cin >> n >> w;

    vector<ll> wgt(n), val(n);
    F0R(i, n) 
        cin >> wgt[i] >> val[i];

    vector<vector<ll>> dp(w + 1, vector<ll>(n, ninf));

    fill(ALL(dp[0]), 0);
    dp[wgt[0]][0] = val[0];
    FOR(r, 1, w + 1)
        FOR(c, 1, n)
            dp[r][c] = max(dp[r][c - 1], 
                           r - wgt[c] < 0 
                                ? ninf : dp[r - wgt[c]][c - 1] + val[c]);

    ll res = 0;
    F0R(i, w + 1)
        ckmax(res, dp[i][n - 1]);
    cout << res << endl;
}

