#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        vector<ll> x; int k;
        while(cin >> k) x.pb(k);

        F0R(k, SZ(x) + 1) {
            auto get = [&](int i) { return i + (i >= k); };

            bool ok = true;
            F0R(i, SZ(x) - 2 + (k > SZ(x)))
                ok &= (x[get(1)] > x[get(0)]) == (x[get(i + 1)] > x[get(i)])
                      && abs(x[get(i + 1)] - x[get(i)]) >= 1 
                      && abs(x[get(i + 1)] - x[get(i)]) <= 3;
            if(ok) {
                ++res;
                return;
            }
        }
    });

    cout << res << endl;
}

