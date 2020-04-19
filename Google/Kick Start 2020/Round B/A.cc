#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    vi a(n, 0);
    F0R(i, n)
        cin >> a[i];

    int cnt = 0;
    FOR(i, 1, n - 1)
        if(a[i - 1] < a[i] && a[i] > a[i + 1])
            cnt++;
    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

