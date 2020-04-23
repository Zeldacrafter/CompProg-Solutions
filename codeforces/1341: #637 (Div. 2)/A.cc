#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ll low = max(0ll, n*(a-b));
    ll high = n*(a+b);
    if((low < c - d && high > c + d) || (low >= c - d && low <= c + d) || (high >= c - d && low <= c + d))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

