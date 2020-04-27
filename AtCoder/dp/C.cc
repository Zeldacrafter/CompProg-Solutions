#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vi a(n), b(n), c(n);
    F0R(i, n) cin >> a[i] >> b[i] >> c[i];

    vector<array<int, 3>> dp(n + 1);
    dp[0][0] = dp[0][1] = dp[0][2];
    F0R(i, n) {
        dp[i + 1][0] = a[i] + max(dp[i][1], dp[i][2]);
        dp[i + 1][1] = b[i] + max(dp[i][0], dp[i][2]);
        dp[i + 1][2] = c[i] + max(dp[i][0], dp[i][1]);
    }
    cout << *max_element(ALL(dp[n])) << endl;

}

