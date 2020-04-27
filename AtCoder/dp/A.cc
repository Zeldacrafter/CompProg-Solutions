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
    
    int n;
    cin >> n;

    vi h(n);
    F0R(i, n) cin >> h[i];

    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    F0R(i, n - 1) {
        ckmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        ckmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }
    cout << dp[n - 1] << endl;
}

