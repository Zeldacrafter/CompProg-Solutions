#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, p, c;
    cin >> n;

    int lastP = 0, lastC = 0;
    bool ok = true;
    F0R(i, n) {
        cin >> p >> c;

        int dp = p - lastP;
        int dc = c - lastC;
        if(dp < 0 || dc < 0 || dc > dp)
            ok = false;

        lastP = p;
        lastC = c;
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

