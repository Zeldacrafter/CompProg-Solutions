#include "../utils.cc"

void solve() {
    vii as, bs, wants;
    getInp([&](auto& cin, int i) {
        ll x, y;
        cin >> x >> y;
        if(i % 4 == 0)        as.eb(x, y);
        else if(i % 4 == 1) bs.eb(x, y);
        else if(i % 4 == 2) wants.eb(x, y);
    }, ".*X.([0-9]*), Y.([0-9]*)");

    ll res = 0;
    F0R(i, SZ(as)) {
        ll mn = numeric_limits<ll>::max();
        for(ll aAmt = 0; aAmt*as[i] <= wants[i]; ++aAmt) {
            ii need = wants[i] - aAmt*as[i];
            if(need % bs[i] == {0, 0}) {
                ii bAmt = need / bs[i];
                if(bAmt.fi == bAmt.se)
                    ckmin(mn, 3*aAmt + bAmt.fi);
            }
        }
        if(mn != numeric_limits<ll>::max()) res += mn;
    }
    cout << res << endl;
}
