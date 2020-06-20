#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, x;
    cin >> n >> x;

    int odd = 0;
    F0R(i, n) {
        int k;
        cin >> k;
        if(k & 1) odd++;
    }

    if(x == n)
        cout << (odd & 1 ? "Yes" : "No") << endl;
    else if(x & 1)
        cout << (odd ? "Yes" : "No") << endl;
    else
        cout << (odd && (n - odd) ? "Yes" : "No") << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

