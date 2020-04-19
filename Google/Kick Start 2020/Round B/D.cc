#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

ld getProb(int possEndAmt, int dist) {
    ld half = 1;
    F0R(i, dist - 1)
        half /= 2;

    ld res = 0;
    ld binom = 1;
    F0R(i, possEndAmt) {
        res += binom*half;
        half /= 2;
        binom = binom*(dist + i - 1.0)/(i + 1);
    }
    return res;
}

void solve() {
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    
    ld res = 0;
    if(l - 1 >= 1 && d + 1 <= h)
        res += getProb(l - 1, d + 1);
    if(r + 1 <= w && u - 1 >= 1)
        res += getProb(u - 1, r + 1);

    cout << setprecision(9) << res << endl;
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

