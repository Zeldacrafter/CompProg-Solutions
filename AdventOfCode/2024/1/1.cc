#include "../utils.cc"

void solve() {
    vector<ll> inp1, 
               inp2;
    getInp([&](auto& cin, int) {
        ll k1, k2; cin >> k1 >> k2;
        inp1.pb(k1);
        inp2.pb(k2);
    });
    sort(ALL(inp1));
    sort(ALL(inp2));

    ll res = 0;
    F0R(i, SZ(inp1)) res += abs(inp2[i] - inp1[i]);
    cout << res << endl;
}

