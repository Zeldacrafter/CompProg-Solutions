#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    ll x, y;
    cin >> x >> y;

    bool xNeg = x < 0;
    bool yNeg = y < 0;
    x = abs(x);
    y = abs(y);

    string s = "";
    while(x || y) {

        if((x & 1) == (y & 1)) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        if( ((x >> 1) || (y >> 1)) && ((x & 2) == (y & 2)) ) {
            if(x & 1) {
                x++;
                s.pb(xNeg ? 'E' : 'W');
            } else {
                y++;
                s.pb(yNeg ? 'N' : 'S');
            }
        } else {
            if(x & 1)
                s.pb(xNeg ? 'W' : 'E');
            else
                s.pb(yNeg ? 'S' : 'N');
        }

        y >>= 1;
        x >>= 1;
    }
    cout << s << endl;
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


