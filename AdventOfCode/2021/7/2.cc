#include "../utils.cc"

void solve() {
    vector<ll> inp;
    getInp([&](auto& cin, int) {
        ll k; char c;
        do {
            cin >> k;
            inp.pb(k);
        } while(cin >> c);
    });

    ll res = 1e17, mx = *max_element(ALL(inp));
    F0R(i, mx + 1) {
        ll amt = 0;
        for(ll x : inp) amt += (abs(x - i) + 1)*abs(x - i)/2;
        ckmin(res, amt);
    }

    cout << res << endl;
}
