#include "../utils.cc"

void solve() {
    vector<ll> inp1;
    map<int, int> inp2;
    getInp([&](auto& cin, int) {
        ll k1, k2; cin >> k1 >> k2;
        inp1.pb(k1);
        ++inp2[k2];
    });

    ll res = 0;
    F0R(i, SZ(inp1)) res += inp1[i]*inp2[inp1[i]];
    cout << res << endl;
}

