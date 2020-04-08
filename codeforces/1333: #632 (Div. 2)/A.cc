#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, m;
    cin >> n >> m;

    F0R(i, n)
        F0R(j, m)
            cout << (!i && !j ? 'W' : 'B') << (j == m - 1 ? "\n" : "");
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

