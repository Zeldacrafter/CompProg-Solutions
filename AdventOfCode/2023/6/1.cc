#include "../utils.cc"

void solve() {
    vector<ll> ts, ds;
    getInp([&](auto& cin, int i) {
        string s; int k; cin >> s;
        if(!i) while(cin >> k) ts.pb(k);
        else   while(cin >> k) ds.pb(k);
    });

    ll res = 1;
    F0R(i, SZ(ts)) {
        ll amt = 0;
        F0R(j, ts[i] + 1) amt += j*(ts[i] - j) > ds[i];
        res *= amt;
    }
    cout << res << endl;
}

