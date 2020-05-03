#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int x, y;
    string s;
    cin >> x >> y >> s;

    F0R(t, SZ(s)) {
        char c = s[t];
        if(c == 'N')
            y++;
        else if(c == 'S')
            y--;
        else if(c == 'W')
            x--;
        else
            x++;

        if(t + 1 >= abs(x) + abs(y)) {
            cout << t + 1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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

