#include "../utils.cc"

ll next(ll num) {
    num ^= num * 64;
    num %= 16777216ll;
    num ^= num / 32;
    num %= 16777216ll;
    num ^= num * 2048;
    num %= 16777216ll;
    return num;
}

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        ll k; cin >> k;
        F0R(_, 2000) k = next(k);
        res += k;
    });
    cout << res << endl;
}

