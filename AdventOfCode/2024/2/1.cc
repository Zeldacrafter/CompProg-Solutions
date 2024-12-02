#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        vector<ll> x; int k;
        while(cin >> k) x.pb(k);

        bool ok = true;
        F0R(i, SZ(x) - 1)
            ok &= (x[1] > x[0]) == (x[i + 1] > x[i])
                  && abs(x[i + 1] - x[i]) >= 1 
                  && abs(x[i + 1] - x[i]) <= 3;
        res += ok;
    });

    cout << res << endl;
}

