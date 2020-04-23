#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int x, y;
    cin >> x >> y;

    int steps;
    for(steps = 2; x < y; ++steps) {
        if(steps & 1)
            x += steps/2;
        else
            y -= steps/2;
    }
    cout << steps - 2 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

