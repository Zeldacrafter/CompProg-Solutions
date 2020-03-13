#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<ld> cld;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR((a), 0, (b))
#define eb emplace_back
#define fi first
#define se second

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    if(n & 1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<pair<cld, cld>> lines;
    cld last;
    F0R(i, n) {
        int x, y;
        cin >> x >> y;
        if(i)
            lines.eb(last, cld(x, y));
        last = cld(x, y);
    }
    lines.eb(last, lines[0].fi);

    cld delta = (lines[0].fi + lines[n/2].fi)/cld(2, 0);
    
    F0R(i, n/2) {
        cld a1 = lines[i].fi - delta,
            a2 = lines[i].se - delta,
            b1 = cld(-1, 0) * (lines[n/2 + i].fi - delta),
            b2 = cld(-1, 0) * (lines[n/2 + i].se - delta);
       
        if(abs(a1 - b1) > 1e-9 || abs(a2 - b2) > 1e-9) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
