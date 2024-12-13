#include "../utils.cc"

void solve() {
    vector<pair<ll, ll>> as, bs, cs;
    getInp([&](auto& cin, int i) {
        ll x, y;
        cin >> x >> y;
        if(i % 4 == 0)        as.eb(x, y);
        else if(i % 4 == 1) bs.eb(x, y);
        else if(i % 4 == 2) cs.eb(x + 10000000000000ll, y + 10000000000000ll);
    }, ".*X.([0-9]*), Y.([0-9]*)");

    ll res = 0;
    F0R(i, SZ(as)) {
        ll inv = as[i].fi*bs[i].se - as[i].se*bs[i].fi;
        if(!inv) continue;

        double a = 1.0*(cs[i].fi*bs[i].se - cs[i].se*bs[i].fi)/inv;
        double b = 1.0*(cs[i].se*as[i].fi - cs[i].fi*as[i].se)/inv;
        if(abs(a - (ll)(a + 0.5)) < 1e-9 && abs(b - (ll)(b + 0.5)) < 1e-9) res += 3*a + b;
    }
    cout << res << endl;
}
