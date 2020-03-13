#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define SZ(x) (x).size()
#define endl '\n'

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    F0R(i, SZ(a))
        if(c[i] != a[i] && c[i] != b[i]) {
            cout << "NO\n";
            return;
        }

    cout << "YES\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();

    return 0;
}
