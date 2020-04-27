#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vi h(n, 0);
    F0R(i, n) cin >> h[i];

    vector<ll> dp(n, 1e18);
    dp[0] = 0;
    F0R(i, n - 1)
        FOR(j, 1, k + 1)
            if(i + j < n)
                ckmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));

    cout << dp[n - 1] << endl;
}

