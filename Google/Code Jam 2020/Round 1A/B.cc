#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR(a, 0, b)

void solve() {
    int n;
    cin >> n;

    if(n < 31) {
        FOR(i, 1, n + 1)
            cout << i << ' ' << 1 << endl;
        return;
    }

    int goal = n - 31;
    int zeroBits = 0;
    bool onLeft = true;
    for(int i = 0; i < 31; ++i) {
        if(goal & (1 << i)) {
            if(onLeft)
                FOR(j, 1, i + 2)
                    cout << i + 1 << ' ' << j << endl;
            else
                ROF(j, i + 1, 0)
                    cout << i + 1 << ' ' << j << endl;
            onLeft = !onLeft;
        } else {
            zeroBits++;
            cout << i + 1 << ' ' << (onLeft ? 1 : i + 1) << endl;
        }
    }

    F0R(i, 31 - zeroBits)
        cout << 32 + i << ' ' << (onLeft ? 1 : 32 + i) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ":\n";
        solve();
    }
}

