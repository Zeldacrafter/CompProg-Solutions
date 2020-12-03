#include "../template.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int i) {
        int k;
        cin >> k;
        res += k;
    });
    cout << res << endl;
}

