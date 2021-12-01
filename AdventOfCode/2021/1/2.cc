#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<ll> inp;
    getInp([&](auto& cin, int) {
        ll _k; cin >> _k; inp.pb(_k);
    });
    int n = SZ(inp);

    F0R(i, n - 3)
        res += inp[i] < inp[i + 3];

    cout << res << endl;
}

