#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

const ll inf = 1e17;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, W;
    cin >> n >> W;

    vector<ll> wgt(n), val(n);
    F0R(i, n) cin >> wgt[i] >> val[i];

    ll maxVal = accumulate(ALL(val), 0);

    vector<vector<ll>> dp(maxVal + 1, vector<ll>(n, inf));

    fill(ALL(dp[0]), 0);
    dp[val[0]][0] = wgt[0];
    FOR(r, 1, maxVal + 1) 
        FOR(c, 1, n)
            dp[r][c] = min(dp[r][c - 1], 
                           r - val[c] < 0 
                                ? inf : dp[r - val[c]][c - 1] + wgt[c]);

    int r = maxVal;
    while(dp[r][n - 1] > W)
        r--;
    cout << r << endl;

}

